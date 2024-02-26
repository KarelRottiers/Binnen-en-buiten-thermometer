
#include <Wire.h>
#include <SPI.h>  //Why? Because library supports SPI and I2C connection
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

#define BMP280_ADDRESS 0x76 // I2C address of BMP280 sensor
#define LM35DZ A0

//Setup connection of the sensor
Adafruit_BMP280 bmp;  // I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);


//Variables
float temperature1;  //To store the temperature (oC)
float temperature2;

void setup() {
  Wire.begin();              //Begin the sensor
  Serial.begin(9600);        //Begin serial communication at 9600bps
  pinMode(LM35DZ, OUTPUT);  // Set LM35DZ pin as output


  // Initialize BMP280 sensor
  if (!bmp.begin(BMP280_ADDRESS)) {
    Serial.println("Could not find BMP280 sensor, check wiring!");
  }

  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Demo");  
  delay(2000); 
}

void loop() {
  //Read values from the sensor:
  temperature1 = bmp.readTemperature();
  temperature2 = analogRead(LM35DZ);


  //Print values to serial monitor:
  Serial.print("Temperatuur BMP280: ");
  Serial.print(temperature1);
  Serial.print("°C");
  Serial.println(" ");

  Serial.print("Temperatuur LM35DZ: ");
  Serial.print(temperature2);
  Serial.print("°C");
  Serial.println(" ");
  delay(1000);

  lcd.clear();// clear previous values from screen
  lcd.print("Robojax D1 Mini");
  lcd.setCursor(0,1);
  lcd.setCursor(11,1);  
  delay(200); 

} 






