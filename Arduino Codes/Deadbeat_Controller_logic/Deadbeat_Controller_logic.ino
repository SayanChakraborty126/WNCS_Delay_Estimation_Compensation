int potpin = A0;
unsigned long tslr = 0;
//unsigned long tslr2 = 0;
int interval_one = 10;
int actual;
String inputString = "";
boolean stringComplete = false;
boolean a = true;
boolean b = true;
 boolean c = true;
int set[2];
int setpoint;
void setup() 
{
Serial.begin(9600);
inputString.reserve(200);
}

void loop() {
 
  if (stringComplete) {
    setpoint = inputString.toInt();
    //Serial.println(inputString);
    Serial.println(setpoint);
     // clear the string:
    inputString = "";
    stringComplete = false;
    c = false;
  }
/*  while(Serial.available()==0){}
 String s=Serial.readString();  //(11100./1023.)*analogRead(potpin);
 int setpoint = s.toInt();*/
 //set[0]=setpoint;
 /*Serial.print(set[0]);
 Serial.print("     ");
 Serial.print(set[1]);
 Serial.print("     ");*/
 /*if(set[1]==set[0])
 {
   Serial.print("true");
 }
 else{Serial.print("false");}
 set[1]=set[0];
 delay(250);*/

 //Serial.println(setpoint);
 

if(c == false)
{
  a= true;
if(a == true){
  tslr=millis();
 while(millis()-tslr< 500)
 {
 while(millis()- tslr< interval_one)
 {
   actual = 500;
 }
   
   Serial.print(actual);
   Serial.print("    ");
   int pwm = 125;
   Serial.println(pwm);
   b= true;
 }
}
}
Serial.println("********************************************************");
 actual=setpoint;
 if(b==true && actual == setpoint)
 {
 actual = setpoint;
 //Serial.print("    ");
 Serial.println(actual);
 a=false;
 c= true;
 }
Serial.println("##########################################################");
delay(250);
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
