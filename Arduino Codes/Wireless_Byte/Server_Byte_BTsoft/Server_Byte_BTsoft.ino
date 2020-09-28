
byte drive1;
unsigned long tslr = 0;

int interval_one = 20;
int spd = 8;
int pin = 7;
byte RPM;
float x;
int i;


void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(pin , OUTPUT);
  pinMode(spd, INPUT);

}

void loop() {
  digitalWrite(pin, LOW);


  if ( Serial1.available() ) {
    drive1 = Serial1.read();

    //      if((abs(drive1-preDrive1) < 15) && (drive >(setpoint+15)))
    //    {
    //       actual = preAct;
    //    }
    //    else
    //    {
    //      preAct = actual;
    //    }


    //Serial.print(drive1);
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

  RPM = count * 2.5;
  Serial1.write(RPM);
  Serial.print(RPM);
  Serial.print("\t");
  Serial.println(drive1);

}



