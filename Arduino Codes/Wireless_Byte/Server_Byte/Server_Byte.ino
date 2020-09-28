//#include<SoftwareSerial.h>
//SoftwareSerial BTSerial(2,3); //RX|TX
String inputString = "";
boolean stringComplete = false;
byte drive1;
unsigned long tslr = 0;

int interval_one = 10;
int spd = 8;
int pin = 7;
byte RPM;
float x;
int i;


void setup() {
  delay(5000);
  Serial.begin(115200);
  pinMode(pin , OUTPUT);
  pinMode(spd, INPUT);
  // inputString.reserve(200);
}

void loop() {
  digitalWrite(pin, LOW);


  if ( Serial.available() ) {
    drive1 = Serial.read();
    analogWrite(9, drive1);
  }

  int count = 0;
  tslr = millis();
  while ( millis() - tslr < 20)
  {
    if (digitalRead(spd) == HIGH)
    {
      count ++;
      while (digitalRead(spd) == HIGH);
    }
  }

  //int x = random(50);
  RPM = count * 2.5;
  //delay(x);
  Serial.write(RPM);

}


