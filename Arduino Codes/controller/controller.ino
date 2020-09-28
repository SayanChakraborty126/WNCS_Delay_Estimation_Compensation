unsigned long tslr = 0;
int interval_one = 50;
int spd = 8;
float actual;
int potpin=A0;
int Dpwm=9;
int Dpin=7;
float e;
float I;
float P;
float integral = 0;
float Kp=.01375; //0.008165;
float Ki=.1171;


int i;


void setup() {
  pinMode(potpin, INPUT);
 pinMode(Dpwm, OUTPUT);
 pinMode(Dpin, OUTPUT);
  Serial.begin(9600);
  Serial.print("RPM\tINPUT");
  Serial.println("RPM\tsetpoint");
  // put your setup code here, to run once:

}

void loop() 
{
 float setpoint=7800;   //(11100./1023.)*analogRead(potpin);
  //c=(255./1023.)*analogRead(potpin);
  
  
  
  tslr = millis();
  bool barray[250]={0};
  float count=0;
  bool array[2];
  array[0]=0;
  array[1]=1;
 
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
  
  actual=(count/20)*1200; //6000;
 e=setpoint-actual;
  integral=integral+e;
  P=e*Kp;
  I=integral*Ki;
  float drive= (P + I)*(255./10500.);
  if ((drive)>255) 
  {
           drive=255;
           integral=90000;//940000.00; //2269800.00 ;
  }
  if(drive<0)
  {
    drive = 0;
    integral = 0;
  }

  analogWrite(Dpwm, drive);
 //Serial.println("RPM\tsetpoint");
  Serial.print(actual);
  Serial.print("  \t\t\t ");
  Serial.print(setpoint);
  Serial.print("  \t\t\t ");
  Serial.print(integral);
  Serial.print("  \t\t\t ");
  Serial.println(drive);
  //Serial.print(drive);
 // Serial.print("\t");
 // Serial.println(e);
  
  
  
  
}
