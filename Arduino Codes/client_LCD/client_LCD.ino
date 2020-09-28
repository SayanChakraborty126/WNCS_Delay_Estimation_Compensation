#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 11,12);  //Create Liquid Crystal Object called LCD
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2,3); //RX|TX

int arr[2];
String inputString = "";
boolean stringComplete = false;
float setpoint;
float actual;
float e;
float I;
float P;
float integral = 0;
float Kp= 0.01375 ;
float Ki=0.487;

void setup() {
  Serial.begin(115200);
  BTSerial.begin(115200);
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  //Serial.println("Ref\tRPM");
  LCD.print("RPS ");
  LCD.setCursor(10,0);
  LCD.print("Ref.");
  inputString.reserve(200);
}

void loop() {
  //delay(1000);
  //delay(10);
  setpoint =100;
  serialEvent();
  if (stringComplete) {
    inputString = inputString.substring(0, inputString.length()-1);
    actual=inputString.toInt();
    arr[0] = actual;
    arr[0]=arr[1];
    arr[1]=actual;
    if(actual<(setpoint-75))
    {
       actual=arr[0];
    }
   // Serial.print(actual);        
    inputString = "";
    stringComplete = false;
  }
  //actual=0;
  Serial.print(actual);
  LCD.setCursor(0,1);
  LCD.print(actual);
  //setpoint =100; //ceil((10500./1023.)*analogRead(A0));
  //setpoint=54;
  Serial.print("\t");
 Serial.print((setpoint));
  LCD.setCursor(10,1);
  LCD.print(ceil(setpoint)); 
  e=setpoint-actual;
 // Serial.print("\t");
  //Serial.print(e);
  delay(10);
  integral=integral+e;
 // Serial.print("\t");
  //Serial.println(integral);
  //delay(10);
  P=e*Kp;
  I=integral*Ki;
  Serial.print("\t");
  //Serial.print(I);
  //integral=integral+e;
  float drive= (P + I);
  if ((drive)>255) 
  {
           drive=255;
           integral=600.00;//2210; //64392.00;     //623089.00;
  }
  if(drive<0)
  {
    drive = 0;
    integral = 0;
  }
  Serial.print(integral);
  Serial.print("\t");
  Serial.println(drive);
  BTSerial.print(drive);
  BTSerial.print('#');
  delay(100);
  
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

