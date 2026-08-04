# ultrasensor_distance_alert_system

# 🛰️ Arduino OLED Ultrasonic Radar System

An interactive distance-monitoring radar system built with an **Arduino Uno**, an **HC-SR04 ultrasonic distance sensor**, a **0.96" SSD1306 OLED display**, and an **active piezo buzzer**. 

This system acts like an automotive reverse parking sensor—displaying real-time distance telemetry, a graphical progress bar, and trigger-adaptive audio/visual collision warnings.

---

## ⚡ Features

- **Real-Time Distance Telemetry:** Measures object proximity with millimetre-level accuracy using ultrasonic sound waves.
- **Dynamic Graphical OLED UI:** Displays live distance values (in cm), operational status, and a real-time progress bar.
- **Adaptive 3-Stage Alert Logic:**
  - **🟢 Safe Zone (> 30 cm):** Standard dark-mode telemetry readout, silent buzzer.
  - **🔵 Warning Zone (10 cm – 30 cm):** Dynamic pulsed acoustic beeping that speeds up as objects get closer.
  - **🔴 Critical Danger Zone (< 10 cm):** Solid continuous alarm tone paired with **High-Contrast Screen Inversion** (black text on bright white background) for maximum visual collision warning.

---

## 🛠️ Hardware Components

| Component | Quantity | Description |
| :--- | :---: | :--- |
| **Arduino Uno R3** | 1 | Main Microcontroller |
| **HC-SR04** | 1 | Ultrasonic Distance Sensor |
| **0.96" OLED Display** | 1 | 128x64 I2C Display (SSD1306 Driver) |
| **Active Piezo Buzzer** | 1 | 5V Audio Indicator |
| **Breadboard & Jumpers** | - | Prototyping Wires |

---

## 🔌 Circuit Pinout & Wiring

### 1. HC-SR04 Ultrasonic Sensor
- **VCC** $\rightarrow$ Arduino **5V**
- **Trig** $\rightarrow$ Arduino **Pin 9**
- **Echo** $\rightarrow$ Arduino **Pin 8**
- **GND** $\rightarrow$ Arduino **GND**

### 2. SSD1306 OLED Display (I2C)
- **VCC** $\rightarrow$ Arduino **5V**
- **GND** $\rightarrow$ Arduino **GND**
- **SDA** $\rightarrow$ Arduino **Pin A4**
- **SCL** $\rightarrow$ Arduino **Pin A5**

### 3. Active Buzzer
- **Positive (+) Leg** $\rightarrow$ Arduino **Pin 3**
- **Negative (-) Leg** $\rightarrow$ Arduino **GND**

---

## 📐 How Distance Is Calculated

The HC-SR04 emits a short **10-microsecond trigger pulse** to transmit a **40 kHz ultrasonic burst**. By measuring the return echo time ($\Delta t$), distance is computed using the speed of sound ($0.0343\text{ cm/}\mu\text{s}$):

$$\text{Distance (cm)} = \frac{\text{Echo Time } (\mu\text{s}) \times 0.0343}{2}$$

*(Division by 2 accounts for the two-way wave travel time to the object and back).*

---

## 📦 Required Arduino Libraries

Before uploading the code, install the following libraries via the **Arduino IDE Library Manager** (`Ctrl + Shift + I` or `Cmd + Shift + I`):

1. **Adafruit_SSD1306**
2. **Adafruit_GFX Library**
3. **Wire** *(Built-in)*

---

## 🚀 Getting Started

1. Wire up your components according to the pinout above.
2. Open `arduino_oled_radar.ino` in your **Arduino IDE**.
3. Select **Arduino Uno** under `Tools -> Board`.
4. Choose the correct COM Port under `Tools -> Port`.
5. Click **Upload**!

---

## 👤 Author

- **Harsha Praneeth**
- **GitHub:** [@HarshaPraneeth](https://github.com/Harsha-praneeth)

---

⭐ *If you found this project helpful or inspiring, feel free to give it a star on GitHub!*
