#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 11, 12); //Create Liquid Crystal Object called LCD
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); //RX|TX


int setpoint;
byte actual;
byte preAct;
float e;
float I;
float P;
int integral = 0;
float Kp = 0.81 ;
float Ki = 0.069;
int drive;
void setup() {
  delay(5000);
  Serial.begin(115200);
  BTSerial.begin(115200);
  LCD.begin(16, 2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0, 0); //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("RPS ");
  LCD.setCursor(10, 0);
  LCD.print("Ref.");

}

void loop() {
  setpoint = 130;

  if ( BTSerial.available() ) {
    actual = BTSerial.read();

    if ((actual > (setpoint + 15)))
    {
      actual = preAct;
    }
    else
    {
      preAct = actual;
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
    drive = (P + I);
    if ((drive) > 255)
    {
      drive = 255;
      integral = 2600;
    }

    if (drive < 0)
    {
      drive = 0;
      //integral = 0;
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



