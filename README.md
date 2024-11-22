Here's the updated **README.md** file with **Home Automation** replacing **HomeIQ**:

```markdown
# 🏠 Home Automation: Smart Home Control System 🌐

Welcome to **Home Automation**! A powerful and intuitive home automation system designed to give you full control over your household appliances like fans, lights, and curtains. Built using **ESP32** and **C++**, this project allows you to remotely control and monitor your devices through a **web interface** and communicate with a **backend server**. 

## 💡 Features:
- 🔌 **Control Appliances**: Turn your fan on/off, adjust light brightness, or open/close curtains with the push of a button.
- 🌐 **Web Interface**: Simple, clean, and interactive control panel to manage your home automation system from any device.
- 🗄️ **Database Logging**: Commands are logged in a **SQLite** database for tracking and analytics.
- 🔄 **Real-time Control**: Seamless, instant control of your devices via an API.

## 🚀 Getting Started

### 📦 Prerequisites:
- **ESP32 Board** – The microcontroller used for controlling appliances.
- **Arduino IDE** or **PlatformIO** – For uploading code to the ESP32.
- **C++ libraries** – `cpprest` for the backend server and `sqlite3` for database interaction.
- **Web Browser** – To access the web interface for controlling devices.

### 🛠️ Setup Guide:

#### 1️⃣ **Backend Setup** (Server-side):
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/home-automation.git
   ```
2. Install the necessary libraries for **C++**:
   - **cpprest** for HTTP communication.
   - **sqlite3** for database integration.
3. Compile and run the `server.cpp` file to start the HTTP server on port 5000:
   ```bash
   g++ server.cpp -o server -lcpprest -lsqlite3
   ./server
   ```

#### 2️⃣ **ESP32 Setup**:
1. Open the `HomeAutomation.ino` file in **Arduino IDE** or **PlatformIO**.
2. Update the Wi-Fi credentials in the code:
   ```cpp
   const char* ssid = "Your_SSID";
   const char* password = "Your_PASSWORD";
   ```
3. Upload the code to your **ESP32** board.

#### 3️⃣ **Web Interface**:
1. Open `index.html` in any modern browser.
2. Use the control buttons to interact with your devices:
   - Turn fan on/off 🔌
   - Dim the light 💡
   - Open/close the curtain 🏠

## ⚙️ How It Works:

- **ESP32** communicates with a backend server via HTTP requests.
- The **server** responds with control commands for the devices.
- **SQLite** stores all commands sent to the system for tracking and future analysis.
- The **Web Interface** sends commands to the backend, which are processed and forwarded to the ESP32 to control the appliances.

## 🌍 Web Interface Features:
- **Buttons for appliance control**:
  - 💨 **Fan On/Off**
  - 💡 **Light Dimming**
  - 🌿 **Curtain Control (Open/Close)**
- **Real-time updates** for controlling devices.

## 🗂️ Folder Structure:
```plaintext
home-automation/
├── esp32/
│   ├── HomeAutomation.ino               # ESP32 code to control devices
├── backend/
│   ├── server.cpp               # Backend server code
│   ├── CMakeLists.txt           # CMake build script for the backend
├── web/
│   ├── index.html               # Web interface HTML file
│   ├── styles.css               # CSS for styling the webpage
│   ├── app.js                   # JavaScript for handling button actions
├── README.md                    # This README file

## 📱 Control Your Home Anywhere:
With **Home Automation**, you can control your devices from anywhere via a simple web interface! 🌍 Just open the web page on your device, and you're good to go.

## 🧩 Future Enhancements:
- 🕹️ **Mobile App Integration**: Develop a mobile app for Android/iOS.
- 🔔 **Voice Control**: Integrate with voice assistants like Alexa or Google Assistant.
- 🌙 **Scheduling**: Automate appliances based on time of day or events.
- 

## 🔐 License:
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---
