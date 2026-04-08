// -----------------------------
// Virtual Smart Sensor System
// -----------------------------


// Pin definitions
#define TEMP_PIN A0
#define LED_PIN 10

// Threshold temperature
#define TEMP_THRESHOLD 30.0

// Timer variables (for millis)
unsigned long interval = 1000;  //1 second
unsigned long previousMillis = 0;

// -----------------------------
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Started...");
}

// -----------------------------
void loop()
{
  unsigned long currentMillis = millis();

  // Non-blocking delay (runs every 1 sec)
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    float temperature = readTemperature();
    controlLED(temperature);
    printData(temperature);
  }
}

// -----------------------------
// Read temperature from sensor
float readTemperature()
{
  
  int adcValue = analogRead(TEMP_PIN);
  
  // Convert to voltage (0–5V)
  float Voltage = adcValue * (5.0 / 1023.0); 
  
  // TMP36 formula
  float tempInCelcius = (Voltage - 0.5) / 0.01;
  
  return tempInCelcius;
}

// -----------------------------
// Control LED based on temperature
void controlLED(float temp)
{
  if (temp > TEMP_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

// -----------------------------
// Print data to Serial Monitor
void printData(float temp)
{  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.write(0xB0); // Prints the degree symbol Using Extended ASCII (Hex 0xB0)
  Serial.print("C | Status: ");

  if (temp > TEMP_THRESHOLD) {
    Serial.println("HIGH");
  } else {
    Serial.println("NORMAL");
  }
}