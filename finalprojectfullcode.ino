//Final project code including Arduino uno inputs,computation equations, output onto LCD I2C module aswell as connect to esp8266
//created 08 March. 2022
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line displa

// These constants won't change. They're used to give names to the pins used:
const int irSensor1 = A0;
const int irSensor2 = A1;
const int irSensor3 = A2;

float sensorValue = 0; // value read from the port
float sensorValue1 = 0;
float sensorValue2 = 0;
float AvgSensorValue = 0;
float outputGlucoseprediction =0;
String bloodGlucose;
String store;

SoftwareSerial espSerial(5, 6);

int outputValue = 0; // value output to the PWM (analog out)


void setup() {
 lcd.init(); //initialising the lcd
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Your estimation:");
// initialize serial communications at 9600baud rate:
Serial.begin(9600);
espSerial.begin(115200);
}

void loop() {
// read the analog in value by taking 50 readings of each sensor:
for(int i = 0; i <=50; i++)
{
sensorValue = sensorValue + analogRead(irSensor1);
sensorValue1 = sensorValue1 + analogRead(irSensor2);
sensorValue2 = sensorValue2 + analogRead(irSensor3);
delay(200);
}

//AvgSensorValue = ((sensorValue/50.0)+(sensorValue1/50.0)+(sensorValue2/50.0)) /3;
//AvgSensorValue = AvgSensorValue * 0.005;
AvgSensorValue = sensorValue1 *0.005;
Serial.print("Average sensor value outputs=");
Serial.print(AvgSensorValue);

outputGlucoseprediction = ((-32.88) * AvgSensorValue) + 196.68; //Using regression equation to create extimate glucose values

Serial.print("Equation output = ");
Serial.print(outputGlucoseprediction);

if(outputGlucoseprediction > 65){
  Serial.println();
  Serial.print("Glucose is low");
  bloodGlucose = "Glucose is low";
  }
 else if(outputGlucoseprediction < 65 && outputGlucoseprediction > 190){
   Serial.println();
  Serial.print("Glucose is normal");
  bloodGlucose = "Glucose is normal";
  }
  else 
     Serial.println();
    Serial.print("Glucose is high");
    bloodGlucose = "Glucose is normal";
  
 // print the results to the Serial Monitor:
Serial.print("sensor value= ");
Serial.print(AvgSensorValue);
Serial.println();
Serial.print("Glucose prediction = ");
Serial.print(outputGlucoseprediction);
Serial.println();

//Output onto LCD screen
lcd.setCursor(1,1);
lcd.print(bloodGlucose);


//Sending data to ESP8266
store =String("coming from arduinouno: ")+String(bloodGlucose);
espSerial.println(store);
// converter to settle after the last reading:
delay(5000);
}
