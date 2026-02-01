# 📱 ESP32-WiFi-SMS-Without-GSM

Send SMS using ESP32 and WiFi without using any GSM module like SIM800 or SIM900.
The project uses a cloud-based SMS API (TextBee) to send SMS over the internet.

The project offers a reusable SMS function that may be used in any IoT or automation project.

---

## 🚀 Features

* ✅ Send SMS using ESP32 + WiFi
* ✅ No GSM module required
* ✅ Cloud-based SMS gateway
* ✅ HTTP & JSON communication
* ✅ Reusable `sendSMS()` function
* ✅ Easy integration with sensors

---

## 🛠️ Requirements

### Hardware

* ESP32 Development Board
* WiFi Connection
* DHT22 Sensor (for demo project)

### Software

* Arduino IDE
* ESP32 Board Package
* TextBee Account

---

## 📦 Libraries Used

The following libraries are used in the project. Please install them in the Arduino IDE.

* WiFi (Built-in)
* HTTPClient (Built-in)
* ArduinoJson
* DHT Sensor Library

---

## 🎥 Complete Tutorial Video

In the video below, I have explained the complete setup and working process in detail.

📺 Watch here:


[https://youtu.be/X7mt4jg6PoY](https://youtu.be/X7mt4jg6PoY)


The video explains the following topics in detail:

* TextBee account setup
* API configuration
* ESP32 coding
* DHT22 temperature monitoring
* SMS alert demonstration
* Troubleshooting tips

---

## 📤 How It Works

1. ESP32 connects to WiFi.
2. The `sendSMS()` function prepares a JSON request.
3. Data is sent to the TextBee REST API.
4. The API delivers SMS to the recipient.
5. When temperature crosses the threshold, an alert SMS is triggered.

You can call `sendSMS()` whenever an alert occurs in your project.

---

## 🧩 Example Usage

```cpp
sendSMS("System Started Successfully!");
sendSMS("Fire Detected!");
sendSMS("High Temperature Alert!");
```

---

## 📌 Applications

* 🌡 Temperature Monitoring
* 🔥 Fire Detection
* 💨 Gas Leak Detection
* 🚪 Security Systems
* 🏠 Home Automation
* 📊 IoT Monitoring

---

## ⚠️ Disclaimer

This project is for educational purposes only.

I am not affiliated with TextBee.

Installing the TextBee app requires disabling Play Protect and granting SMS permissions, which may involve security and privacy risks.

Use this project at your own responsibility.

---

## 📄 License

This project is released under the MIT License.
You are free to use, modify, and distribute this project.

---

## 🚀 Related Project: LifeLine Helmet – Smart Safety System

I have also implemented this SMS alert system in a real-world safety project called **LifeLine Helmet – Smart Safety System**.

This project is a smart helmet solution that:

- Prevents ignition if the rider is drunk or not wearing a helmet  
- Detects accidents using sensors  
- Sends automatic SOS alerts with GPS location using the **TextBee.dev Cloud SMS API**

By using TextBee instead of GSM modules, the system achieves:

- ✅ Lower hardware cost  
- ✅ Reduced power consumption  
- ✅ No SIM card dependency  
- ✅ Reliable internet-based messaging  

This makes it a practical and scalable safety solution for two-wheeler riders.

🔗 LifeLine Helmet Repository:

[https://github.com/your-username/LifeLine-Helmet-Smart-Safety-System](https://github.com/hasheerahmed/lifeline-helmet-smart-safety-system.git)

---


## 🙌 Author

**Hasheer Ahmed**

If you find this project helpful, please ⭐ star this repository and subscribe to the YouTube channel for more tutorials.

---

## 📬 Support

For questions or suggestions, feel free to open an Issue in this repository.# ESP32-WiFi-SMS-Without-GSM
Use ESP32 and WiFi to send SMS without a GSM module, employing a cloud-based SMS API. Comprises a reusable SMS function for IoT notification. systems
