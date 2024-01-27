#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


float temperature;
float humidity;
DHT dht(D4, DHT11);


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);
  

  dht.begin();
  

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hum:       %");
  lcd.setCursor(0, 1);
  lcd.print("Temp:       c");
}

void loop() {
  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  Serial.print("Hum : ");
  Serial.print(humidity);
  Serial.print("Temp : ");
  Serial.print(temperature);

  lcd.setCursor(5, 0);
  lcd.print(humidity);
  lcd.setCursor(6, 1);
  lcd.print(temperature);  

  delay(500); 
}