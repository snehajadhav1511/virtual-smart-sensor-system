# virtual-smart-sensor-system
Embedded C project using Arduino for temperature monitoring

## Overview

This project is a **virtual embedded system** designed to monitor temperature and respond in real-time using LED indicators and serial communication.

The system is implemented using **Embedded C (Arduino framework) and simulated using Tinkercad.

---

## Features

* Reads temperature using analog sensor (ADC)
* Controls LED based on temperature threshold
* Displays real-time data via UART (Serial Monitor)
* Uses non-blocking timing with 'millis()' (no delay)
* Modular code structure (functions for each task)

---

## Components Used

* Arduino UNO (simulated)
* Temperature Sensor (TMP36)
* LED
* Resistor (220Ω)
* Serial Monitor

---

## Circuit Diagram
![Circuit](circuit_diagram.png)
---

## Working Principle

1. Sensor provides analog voltage based on temperature
2. Microcontroller reads value using ADC
3. Temperature is calculated in software
4. If temperature exceeds threshold:
   * LED turns ON
   * Status shows "HIGH"

5. Else:
   * LED turns OFF
   * Status shows "NORMAL"

### Analog voltage to temperature 

  Convert to Voltage: Convert the raw value into millivolts.
  Formula (5V Arduino): (rawReading * 5000.0) / 1024.0
  Formula (3.3V Arduino): (rawReading * 3300.0) / 1024.0

  Subtract Offset: The TMP36 outputs 500mV at 0°C to allow for 
  negative temperatures.
  Formula: milliVolts - 500

  Calculate Temperature: Divide by 10 
  (since the sensor changes 10mV per 1°C).

  Formula: (milliVolts - 500) / 10
---

## Sample Output

Temp: 32.4 °C | Status: HIGH
Temp: 27.1 °C | Status: NORMAL

---

## How to Run

1. Open Tinkercad simulator
2. Create Arduino UNO project
3. Connect:
   Sensor → A0
   LED → Pin 10
4. Paste code and run simulation
5. Open Serial Monitor to view output

---

## Concepts Used

* Embedded C programming
* GPIO control
* ADC (Analog to Digital Conversion)
* UART communication
* Non-blocking timing ('millis()')

---

## Future Improvements

* Add multiple sensors
* Add buzzer for alerts
* Implement I2C display (LCD)
* Add data logging

---

## Author

Sneha Jadhav

---

## Note

This project demonstrates core embedded system concepts without physical hardware using simulation tools.
