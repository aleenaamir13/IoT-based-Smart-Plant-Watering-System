# Smart Plant Watering System using ESP8266, DHT11, and Blynk
This project is an **IoT-based Smart Plant Watering System** built using an ESP8266 microcontroller, DHT11 sensor, and soil moisture sensor. The system monitors **temperature, humidity, and soil moisture** and controls a **relay** to water plants automatically. It is connected to the **Blynk app**, allowing real-time monitoring and manual control from your smartphone.

## **Features**
- Measures **temperature** and **humidity** using the DHT11 sensor.
- Measures **soil moisture** using a soil moisture sensor.
- Automatic **watering control** via a relay based on soil moisture level.
- Real-time monitoring on the **Blynk app**.
- Manual relay control from Blynk using a virtual button.
- Data visualization using Blynk virtual pins:
  - **V1**: Temperature
  - **V2**: Humidity
  - **V3**: Soil Moisture
  - **V0**: Relay Control

## **Components Required**
- ESP8266 Module (NodeMCU or Wemos D1 Mini)
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- Relay Module
- Jumper Wires
- Smartphone with **Blynk App** installed
- Wi-Fi Connection

## **Wiring**
| Component        | ESP8266 Pin |
|-----------------|-------------|
| DHT11 Data       | D1          |
| Soil Sensor Analog| A0         |
| Relay            | D3          |

## **Blynk Setup**
1. Download the **Blynk app** on your smartphone.
2. Create a new project and select **ESP8266** as the device.
3. Copy the **Auth Token** generated and replace it in your code.
4. Add **widgets** in the Blynk app:
   - **Button** (V0) → Control the relay manually
   - **Gauge/Value Display** (V1) → Temperature
   - **Gauge/Value Display** (V2) → Humidity
   - **Gauge/Value Display** (V3) → Soil Moisture

## **Code Explanation**
- **Libraries Used**:
  - `DHT11.h` → To read temperature and humidity
  - `BlynkSimpleEsp8266.h` → For Blynk IoT platform integration

- **Logic**:
  1. Read temperature and humidity from DHT11.
  2. Read soil moisture from the analog pin.
  3. Send readings to Blynk virtual pins.
  4. Automatically turn on the relay if soil moisture is below the threshold.
  5. Relay can also be controlled manually from Blynk.

# System Diagram
<img width="3000" height="1758" alt="image" src="https://github.com/user-attachments/assets/9c2830c1-83eb-4c2d-9c5b-8ae00ab4935f" />


#Blynk App Output
<img width="3000" height="1731" alt="image" src="https://github.com/user-attachments/assets/71612aee-1673-412a-94b6-c6f8f87f5565" />



```cpp
BLYNK_WRITE(V0) {
  relayState = param.asInt();
  digitalWrite(relay, relayState);
}


