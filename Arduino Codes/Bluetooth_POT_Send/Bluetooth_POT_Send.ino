#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2,3); //RX|TX

String inputString = "";
boolean stringComplete = false;
int V;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  serialEvent();
  if (stringComplete) {
    inputString = inputString.substring(0, inputString.length()-1);
    Serial.print(inputString);        
    inputString = "";
    stringComplete = false;
  }
  delay(100);
  V = analogRead(A0);
  BTSerial.print(V);
  BTSerial.print('#');
  Serial.print("\t");
  Serial.println((5./1023.)*V);
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

