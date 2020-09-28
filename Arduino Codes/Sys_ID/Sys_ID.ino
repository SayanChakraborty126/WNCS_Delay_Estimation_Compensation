unsigned long tslr = 0;
int interval_one = 10;
int spd = 8;
int low=7;
//int pwm=9;
//unsigned int counter = 0;
float RPM;

int i;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(A5, INPUT);
  // put your setup code here, to run once:
  /*Serial.print("RPM");
  Serial.print("   ");
  Serial.println("Voltage");*/

}

void loop() 
{
  //digitalWrite(7, LOW);
 float pwm = (255./1023.)*analogRead(A0);
 float vd=analogRead(A5);
// Serial.println(vd);
 //Serial.println(pwm);
  analogWrite(9,pwm);
  tslr = millis();

  float count=0;
  bool array[2];
  array[0]=0;
  array[1]=1;
 
  while (millis() - tslr < interval_one)
  {
    boolean b= digitalRead(spd);
    //Serial.println(b);
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
   //Serial.println(b);
   
  
   }
   //Serial.print("\t");
   Serial.print((count/20)*100);
   Serial.print(",");
   Serial.println((5./1023.)*analogRead(A0));
   //delay(250);
 //Serial.println(" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ");

  
}
