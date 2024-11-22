#include <iostream>
#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <sqlite3.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// Database connection
sqlite3* db;

void handleGet(http_request request) {
  json::value response;
  response[U("status")] = json::value::string(U("ok"));

  // Example control commands
  response[U("commands")] = json::value::string(U("fan:on,light:dim:128,curtain:open"));

  request.reply(status_codes::OK, response);
}

void handlePost(http_request request) {
  request.extract_json().then([](json::value body) {
    std::string command = body[U("command")].as_string();

    // Log command to SQLite
    std::string sql = "INSERT INTO commands (command) VALUES ('" + command + "')";
    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
  }).wait();

  request.reply(status_codes::OK);
}

int main() {
  // Initialize SQLite
  sqlite3_open("control.db", &db);
  sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS commands (id INTEGER PRIMARY KEY, command TEXT)", nullptr, nullptr, nullptr);

  // Start HTTP server
  http_listener listener(U("http://0.0.0.0:5000/api"));
  listener.support(methods::GET, handleGet);
  listener.support(methods::POST, handlePost);

  listener.open().wait();
  std::cout << "Server is running on port 5000..." << std::endl;

  std::string input;
  std::getline(std::cin, input);

  sqlite3_close(db);
  return 0;
}
