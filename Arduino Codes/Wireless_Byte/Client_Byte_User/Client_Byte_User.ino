#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 11, 12); //Create Liquid Crystal Object called LCD
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); //RX|TX


String inputString = "";
boolean stringComplete = false;
boolean a = true;
boolean b = true;
boolean c = true;

int setpoint;
byte actual;
byte preAct;
float e;
float I;
float P;
float D;
int integral = 0;
float Kp = 1.69; //0.003295;
float Ki = 0.1488; //0.069;
float Kd = 0.031;
float last;
int drive;
float derivative;
void setup() {
  Serial.begin(115200);
  BTSerial.begin(115200);
  LCD.begin(16, 2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0, 0); //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("RPS ");
  LCD.setCursor(10, 0);
  LCD.print("Ref.");

}

void loop() {
  //setpoint =100;
  //  serialEvent();
  //  if (stringComplete)
  //  {
  //    byte z= inputString.toInt();
  //    setpoint = 5*z;
  //    if(setpoint > 150 || setpoint<0)
  //    {
  //      setpoint=150;
  //    }
  //    inputString = "";
  //    stringComplete = false;
  //    a = false;
  //    c = true;
  //  }



  if ( BTSerial.available()) {
    actual = BTSerial.read();

    /*if((abs(actual-preAct) < 10) && (actual >(setpoint+20)))
    {
       actual = preAct;
    }
    else
    {
      preAct = actual;
    }*/
    serialEvent();
    if (stringComplete)
    {
      byte z = inputString.toInt();
      setpoint = z;
      if (setpoint > 150 || setpoint < 0)
      {
        setpoint = 150;
      }
      inputString = "";
      stringComplete = false;
    }

    LCD.setCursor(0, 1);


    LCD.setCursor(10, 1);
    LCD.print(ceil(setpoint));



    Serial.print(actual);
    LCD.print(actual);
    Serial.print("\t");
    Serial.print((setpoint));
    Serial.print("\t");
    e = setpoint - actual;
    integral = integral + e;
    P = e * Kp;
    I = integral * Ki;
    D = (last - actual) * Kd;
    drive = (P + I + D);
    if ((drive) > 255)
    {
      drive = 255;
      integral = 2600;
    }

    if (drive < 0)
    {
      drive = 0;
      integral = 0;
    }
    if ((setpoint) == 0) {
      drive = 0;
      integral = 0;
    }

    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.println(drive);

    BTSerial.write(drive1);




  }

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
  }
}





