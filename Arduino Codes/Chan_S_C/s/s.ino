//#include<SoftwareSerial.h>
//SoftwareSerial BTSerial(2,3); //RX|TX
String inputString = "";
boolean stringComplete = false;
//unsigned int pwm;
int drive;
unsigned long tslr = 0;

int interval_one = 10;
int spd = 8;
int pin=7;
//unsigned int counter = 0;
byte RPM;
float arr[2];
float x;
int i;


void setup() {
  Serial.begin(115200);
  //BTSerial.begin(9600);
  pinMode(pin , OUTPUT);
  pinMode(spd, INPUT);
  inputString.reserve(200);
}

void loop() {
  digitalWrite(pin, LOW);
  //serialEvent();
  //if (stringComplete) {
//    inputString = inputString.substring(0, inputString.length()-1);
//    drive = inputString.toInt();
    //pwm = map(pwm, 0, 1023, 0, 255);
    /*x=0.9*drive;
    arr[0] = drive;
    arr[0]=arr[1];
    arr[1]=drive;
    if(drive<(x))
    {
       drive=arr[0];
    }*/
    if( Serial.available() ) {
     
      drive= Serial.read();
      analogWrite(9, drive);
    }
    
    
    
    
 //Serial.print(drive);
   // Serial.print(inputString);
   // Serial.print('#');
        
    inputString = "";
    stringComplete = false;
  }
   
  //bool barray[250]={0};
  float count=0;
 
  
  tslr = millis();
  count = 0;
  while( millis() - tslr < 10)
  {
    if (digitalRead(spd) == HIGH)
    {
      count ++;
      while(digitalRead(spd) == HIGH);
    }
  }
//  rps = count*5;
  
//  while (millis() - tslr < interval_one)
//  {
//    boolean b= digitalRead(spd);
//    if(b>0)
//    {
//      if(b != array[0])
//      {
//        count= count+1;
//        array[0]=1;
//        array[1]=0;
//        
//      }
//    }
//    
//    if(b==0)
//    {
//      array[0]=0;
//      array[1]=1;
//    }
//   //Serial.println(b);
//   }
   
   
   RPM= count*5;
   //Serial.print(',');
   //delay(100);
   RPM = 0;
   Serial.write(RPM);
   //Serial.print('#');
   //delay(100);
   //Serial.println('#');
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}


