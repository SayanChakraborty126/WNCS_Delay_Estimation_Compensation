unsigned long tslr = 0;
int interval_one = 1000;
int spd = 8;
//unsigned int counter = 0;
float RPM;



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
  float counter=0;
  tslr = millis();
  while (millis() - tslr < interval_one)
  {
    
  boolean b = digitalRead(spd);
  Serial.println(b);
 //if(b==1)
 /* {
 counter=counter+1;
 
   //Serial.println(counter);
    //RPM=(counter/20);
     //Serial.print(" ");
     float a=(counter/100);
    Serial.println((a*60));
    
  }*/
  //Serial.print(" ");
//counter=counter+1;


    
  }
  // put your main code here, to run repeatedly:
  
  
  Serial.println(" **************************************** ");
  //Serial.println(" ");
 // Serial.println(" ");
  delay(250);

  
}
