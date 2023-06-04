#include <dht.h>        // Include library
#define outPin 7        // Defines pin number to which the sensor is connected

dht DHT;                // Creates a DHT object

int[] temporalData;
int count;

void setup() {
  Serial.begin(9600);
		count = 0;
}

void loop() {
  int readData = DHT.read11(outPin);

  float t = DHT.temperature;        // Read temperature
  float h = DHT.humidity;           // Read humidity
  float odour = readAdc(0);
  
		temporalData[count] = t;
		temporalData[count++] = h;
		temporalData[count++] = odour;
		
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");
  Serial.print((t*9.0)/5.0+32.0);        // Convert celsius to fahrenheit
  Serial.println("°F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");
  Serial.print("Odour = ");
  Serial.print(odour);
  Serial.println(" ");
  Serial.println("");

  int sensorValue = analogRead(A0);
		int sensorValue2 = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
		float voltage2 = sensorValue2 * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println("Load Cell 1");
  Serial.println(voltage);
	
		Serial.println("Load Cell 2");
  Serial.println(voltage2);

		int stdVal = std(temporalData);
		int varVal = var(temporalData);
		
  if(h > 75 && stdVal > 0.5) {
    Serial.println("Humidity level is high, please check for molds");
  }
  if(h > 75 && t < 30) {
    Serial.println("Probably the wardrobe is wet");
  }

  if(odour > 300 & varVal > 0.9) {
    Serial.println("Odour level is HIGH, please check for smell in clothes");
  } else if(odour > 150 & stdVal > 0.4) {
    Serial.println("Odour level is MEDIUM, please check for smell in clothes");
  } else {
    Serial.println("Odour level is LOW, please clothes are OK");
  }
  if(h > 75 && t < 30) {
    Serial.println("Probably the wardrobe is wet");
  }
  
  delay(2000); // wait two seconds
}
