# IoT Based Smart Wardrobe

ℹ️ This code reads data from a DHT sensor and an analog load cell sensor. It provides temperature, humidity, and odor level measurements. It also includes some conditional checks based on the sensor readings.

## Prerequisites

To run this code, you need the following:

- [DHT library](https://github.com/adafruit/DHT-sensor-library) for DHT sensor functionality.

## Installation

1. Connect the DHT sensor to the specified pin.
2. Install the DHT library.
3. Upload the code to your Arduino board.

## Usage

1. Open the Serial Monitor with a baud rate of 9600.
2. The code will continuously read and display sensor data.
3. The temperature is displayed in Celsius and Fahrenheit.
4. The humidity is displayed in percentage.
5. The odor level is displayed as a raw value.
6. The load cell sensors provide voltage readings.
7. Conditional checks are performed based on sensor readings.
8. If the humidity is above 75% and the standard deviation of the temperature readings is above 0.5, a message is displayed to check for molds.
9. If the humidity is above 75% and the temperature is below 30°C, a message is displayed indicating a possibly wet wardrobe.
10. If the odor level is above 300 and the variance of the temporal data is above 0.9, a message is displayed to check for smell in clothes.
11. If the odor level is above 150 and the standard deviation of the temporal data is above 0.4, a message is displayed indicating a medium odor level.
12. If none of the above conditions are met, a message is displayed indicating a low odor level.

## Example Output
Temperature = 25.00°C | 77.00°F
Humidity = 80.00%

Odour = 350.00

Load Cell 1
1.23
Load Cell 2
2.67

Humidity level is high, please check for molds
Odour level is HIGH, please check for smell in clothes
Probably the wardrobe is wet


⚠️ Make sure to modify the code and adjust the pin numbers and thresholds as per your setup and requirements.

🔌 Remember to properly connect the sensors to your Arduino board.

📚 Refer to the DHT library documentation for more information on the DHT sensor functionality.

👉 Feel free to customize the conditional checks based on your specific use case.

🔄 The code includes a 2-second delay between readings. Modify the delay duration as needed.

🚧 Use this code responsibly and ensure safety precautions when dealing with sensors and electrical components.

