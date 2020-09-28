int potpin = A0;
int actual;
String inputString = "";
boolean stringComplete = false;
boolean a = true;
boolean b = true;
 boolean c = true;
int set[2];
int setpoint;
unsigned long tslr = 0;
int interval_one = 10;
int spd = 8;
int Dpwm=9;
int Dpin=7;
float e;
float I;
float P;
float integral = 0;
float Kp=0.81;//0.003295;
float Ki=0.069;
float drive;
float drive1;

void setup() 
{
Serial.begin(9600);
inputString.reserve(200);
}

void loop() {
 
  
  if (stringComplete) 
  {
    int z= inputString.toInt();
    setpoint = 5*z;
    if(setpoint > 150 || setpoint<0)
    {
      setpoint=150; 
    }
    inputString = "";
    stringComplete = false;
    a = false;
    c = true;
  }
   
  tslr = millis();
  bool barray[250]={0};
  float count=0;
  bool array[2];
  array[0]=0;
  array[1]=1;
 
 if(a== false && c == true){
   
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
  
  actual=(count/20)*100;
  e=setpoint-actual;
  
  P=e*Kp;
  I=integral*Ki;
  drive= (P + I);
  integral=integral+e;
  if ((drive)>255) 
  {
           drive=255;
          integral=2210;//43000; //2277000;//23000;//228500; //2272335; 
  }
  
 if ((drive)<0) 
  {
           drive=0;
          integral= 0;
  }
  
  if((setpoint)==0) {
     drive = 0;
     integral =0;
  }
  analogWrite(Dpwm, drive);
 }
 
if(setpoint != 0)
{
if(actual == setpoint || actual == setpoint - 1 )
{
  //Serial.print("done");
  drive1= drive;
  analogWrite(Dpwm, drive1);
  c=false;
}



  }
  
 // analogWrite(Dpwm, drive);
  
  Serial.print(actual);
  Serial.print(",");
  Serial.println(setpoint);
  /*Serial.print("  \t\t\t ");
  Serial.print(integral);
  Serial.print("  \t\t\t ");
  Serial.print(drive);
  Serial.print("  \t\t\t ");
  Serial.println(drive1);*/





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
