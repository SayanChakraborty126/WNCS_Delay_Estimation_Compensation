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
float derivative;
int drive;
double y = 0;
double y2 = 0;
double y3 = 0;
double x;
double x0;
double x1 = 0;
double x2 = 0;
double yh = 0;
double eh;
double trV; //= 0.240;

void setup() {
  delay(10000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 80;

  if ( Serial1.available() ) {
    actual = Serial1.read();
    
    if (actual == 0)
    {
      trV = 20 + trV;
      
    }
    double tr = trV/1000;
    Serial.print(actual);
    Serial.print("\t");
    Serial.print(trV);
    Serial.print("\t");
    Serial.print((setpoint));
    Serial.print("\t");
    eh = setpoint - actual;
    e = eh - yh;
    integral = integral + e;
    P = e * Kp;
    I = integral * Ki;
    D = (last - actual) * Kd;
    drive = (P + I + D);
    drive = constrain(drive, 0, 255);
    
     if( abs(integral) > 880)
    {
      integral = 880;
    }
    
    last = actual;
    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.print(drive);
    Serial.print("\t");
    Serial.println(yh);
    
    
    Serial1.write(drive1);
    
    x0 = drive * (12. / 255.);
    double a = ( 2 - (100*tr) );
    double b = ( 2 + (100*tr) );
    double c = ( b - a );
    double d = ( 1.33876 * (c/b) )*x1;
    double e = ( -1.33876 * (c/b) )*x2;
    double f = ( -((a/b) - 0.914) )*y2;
    double g = ( 0.914 * (a/b) )*y3;
    
    yh = d + e + f +g ;
    
    x2 = x1;
    x1 = x0;
    
    y3 = y2;
    y2 = yh;
    

  }

}



