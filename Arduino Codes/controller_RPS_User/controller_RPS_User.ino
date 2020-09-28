int potpin = A0;
int actual;
String inputString = "";
boolean stringComplete = false;
boolean a = true;
boolean b = true;
boolean c = true;
//int set[2];
int setpoint;
unsigned long tslr = 0;
int interval_one = 20;
int spd = 8;
int Dpwm = 9;
int Dpin = 7;
float e;
float I;
float P;
float integral = 0;
float Kp = 0.81; //0.003295;
float Ki = 0.069; //0.069;
float drive;
float drive1;

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);
  //delay(5000);
}

void loop() {

  serialEvent();
  if (stringComplete)
  {
    int z = inputString.toInt();
    setpoint = z;
    if (setpoint > 150 || setpoint < 0)
    {
      setpoint = 150;
    }
    inputString = "";
    stringComplete = false;
    a = false;
    c = true;
  }
  int count = 0;
  tslr = millis();
  //  bool barray[250]={0};
  //  float count=0;
  //  bool array[2];
  //  array[0]=0;
  //  array[1]=1;

  if (a == false) {

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
    //      }
    //    }
    //    if(b==0)
    //    {
    //      array[0]=0;
    //      array[1]=1;
    //    }
    //  }


    while ( millis() - tslr < 10)
    {
      if (digitalRead(spd) == HIGH)
      {
        count ++;
        while (digitalRead(spd) == HIGH);
      }
    }



    actual = count * 5;
    e = setpoint - actual;
    integral = integral + e;
    P = e * Kp;
    I = integral * Ki;
    drive = (P + I); //*(255./11100.);
    //  integral=integral+e;
    if ((drive) > 255)
    {
      drive = 255;
      integral = 2210; //2600.00; 
    }

    if ((drive) < 0)
    {
      drive = 0;
      integral = 0;
    }

    if ((setpoint) == 0) {
      drive = 0;
      integral = 0;
    }
    analogWrite(Dpwm, drive);
  }



  // analogWrite(Dpwm, drive);
  //Serial.print("  \t\t\t ");
  Serial.print(actual);
  Serial.print("\t\t\t ");
  Serial.print(setpoint);
  Serial.print("  \t\t\t ");
  Serial.print(integral);
  Serial.print("  \t\t\t ");
  Serial.println(drive);
  //  Serial.print("  \t\t\t ");
  //  Serial.println(drive1);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
    // stringComplete = true;

  }
}
