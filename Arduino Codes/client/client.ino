#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2,3); //RX|TX

String inputString = "";
boolean stringComplete = false;
float setpoint;
float actual;
float e;
float I;
float P;
float integral = 0;
float Kp=0.0025;
float Ki=.255;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  //delay(1000);
  serialEvent();
  if (stringComplete) {
    inputString = inputString.substring(0, inputString.length()-1);
    actual=inputString.toFloat();
    Serial.print(actual);        
    inputString = "";
    stringComplete = false;
  }
  //actual=0;
  delay(1000);
  setpoint = (102./1023.)*analogRead(A0);
  Serial.print("\t");
  Serial.print(setpoint);
  e=setpoint-actual;
  Serial.print("\t");
  Serial.print(e);
  integral=integral+e;
  Serial.print("\t");
  Serial.print(integral);
  P=e*Kp;
  I=integral*Ki;
  float drive= (P + I)*(255./102.);
  if ((drive)>255) 
  {
           drive=255;
           integral = 255;
  }
  Serial.print("\t");
  Serial.println(drive);
  BTSerial.print(drive);
  BTSerial.print('#');
  
  //delay(100);
}

void serialEvent() {
  while (BTSerial.available()) {
    char inChar = (char)BTSerial.read();
    inputString += inChar;
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}

