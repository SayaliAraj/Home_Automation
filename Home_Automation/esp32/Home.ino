#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// GPIO pin definitions
const int relayPin = 5;  // Fan
const int dimmerPin = 4; // LED dimmer (PWM)
const int servoPin = 14; // Servo motor for curtains

void setup() {
  Serial.begin(115200);

  // GPIO setup
  pinMode(relayPin, OUTPUT);
  ledcSetup(0, 5000, 8); // PWM channel, frequency, resolution
  ledcAttachPin(dimmerPin, 0);

  // Servo setup
  pinMode(servoPin, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi!");
}

void loop() {
  HTTPClient http;

  // Fetch control signals from the server
  http.begin("http://<SERVER_IP>:5000/api/get_control");
  int httpCode = http.GET();
  if (httpCode == 200) {
    String payload = http.getString();
    parseControlCommands(payload);
  }
  http.end();

  delay(2000); // Poll every 2 seconds
}

void parseControlCommands(String payload) {
  if (payload.indexOf("fan:on") != -1) digitalWrite(relayPin, HIGH);
  else if (payload.indexOf("fan:off") != -1) digitalWrite(relayPin, LOW);

  if (payload.indexOf("light:dim:") != -1) {
    int brightness = payload.substring(payload.indexOf("light:dim:") + 10).toInt();
    ledcWrite(0, brightness); // Set PWM brightness (0-255)
  }

  if (payload.indexOf("curtain:open") != -1) digitalWrite(servoPin, HIGH);
  else if (payload.indexOf("curtain:close") != -1) digitalWrite(servoPin, LOW);
}
