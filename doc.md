# ESP32 Weather Monitoring System using Blynk IoT

This project monitors **temperature, humidity, and Soil Moisture / Voltage Sensor** using an **ESP32**, **DHT11 sensor**, and **Blynk IoT platform**.  
It displays live data on the Blynk app and sends **email alerts** when the temperature exceeds a certain threshold.

---

## Components Used

| Component | Description |
|------------|-------------|
| ESP32 | Main microcontroller with Wi-Fi |
| DHT11 | Temperature and humidity sensor |
| Soil Moisture Sensor | For moisture level detection |
| Blynk IoT App | To visualize and log sensor data |
| LED | Indicator controlled via app slider |

---

## Required Libraries

Install these libraries in Arduino IDE (**Sketch → Include Library → Manage Libraries**)

- `Blynk`  
- `DHT sensor library` by Adafruit  
- `Adafruit Unified Sensor`  

---

## Circuit Connections

| Sensor Pin | ESP32 Pin |
|-------------|-----------|
| DHT11 Data | GPIO 4 |
| Soil Moisture AOUT | GPIO 36 |
| LED | GPIO 2 |

<img width="572" height="1049" alt="image" src="https://github.com/user-attachments/assets/d45f2d21-571c-4d9e-9aa8-aaafcd34d42c" />
