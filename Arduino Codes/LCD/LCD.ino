#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 11,12);  //Create Liquid Crystal Object called LCD || LiquidCrystal LCD(rs, enable, d4, d5, d6, d7) ||
//int myCounter=0;  //declare your variable myCounter and set to 0
float str1;
float str2;
void setup() {
 
LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
//LCD.print("My Timer:");  //Print Message on First Row
Serial.begin(9600);
Serial.println("Ref\tRPM");
LCD.print("Ref. ");
LCD.setCursor(10,0);
LCD.print("RPM");
}
 
void loop() {
     
     for(int i=0; i<20; i++)
     {
       str1=i;
     Serial.print(str1);
     Serial.print("\t");
     LCD.setCursor(0,1);
     //str1=Serial.readString();
     LCD.print(str1);
      
      //Go to 1st column(column 0) and 2nd row(row 1)
     //LCD.print("                "); //Print blanks to clear the row
     //LCD.setCursor(0,1); //Go to 1st column(column 0) and 2nd row(row 1)
      str2=i+1;
     Serial.println(str2);
     LCD.setCursor(10,1);
    //str2=Serial.readString();
     LCD.print(str2); 
    delay(300);
     }
     //LCD.setCursor(0,1);
    

  
}
