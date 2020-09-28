#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 11, 12); //Create Liquid Crystal Object called LCD



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
float Kd = 0;
float last;
float derivative;
int drive;
void setup() {
  delay(5000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 60;

  if ( Serial1.available() ) {
    actual = Serial1.read();

    Serial.print(actual);
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
      integral = 600;//2600;
    }

    if (drive < 0)
    {
      drive = 0;
      //integral = 0;
    }
    last = actual;
    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.println(drive);
    //    int x = random(50);
    //    delay(x);
    
    Serial1.write(drive1);
    delay(15);




  }

}



