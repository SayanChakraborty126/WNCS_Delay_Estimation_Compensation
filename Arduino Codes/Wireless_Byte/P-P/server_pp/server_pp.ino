byte drive1;
unsigned long tslr = 0;
unsigned long t2 = 0;
int interval_one = 20;
int spd = 8;
int Dpwm = 9;
byte RPM;
float x;
int i;
boolean flag = true;
void setup() {
  delay(10000);
  Serial.begin(115200);
  //Serial1.begin(115200);
  pinMode(spd, INPUT);

  // pinMode(Dpwm, OUTPUT);

}

void loop() {
  if ( Serial.available() ) {
    drive1 = Serial.read();
    analogWrite(Dpwm, drive1);
  }

  int count = 0;
  tslr = millis();
  bool array[2];
  array[0]=0;
  array[1]=1;
//  while ( millis() - tslr < 20)
//  {
//    if (digitalRead(spd) == HIGH)
//    {
//      count ++;
//      while (digitalRead(spd) == HIGH);
//    }
//  }

  while (millis() - tslr < interval_one)
  {
    boolean b= digitalRead(spd);
    if(b>0)
    {
      if(b != array[0])
      {
        count= count+1;
        array[0]=1;
        array[1]=0;
      }
    }
    if(b==0)
    {
      array[0]=0;
      array[1]=1;
    }
  }

  RPM = count * 2.5;
  //Serial.write(RPM);
  t2 = millis();
  if(flag == true)
  {
    while(millis()-t2< 240)
    {
    Serial.write(0);
    delay(20);
    
    }
    flag = false;
  }
  
  if(flag==false)
  {
    Serial.write(RPM);
  }
  

}



