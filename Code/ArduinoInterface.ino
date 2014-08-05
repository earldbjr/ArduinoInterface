/***************************************************************
 * Name:      ArduinoInterfaceMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-07-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/
//Serial instructions follow the format:
//Device# - To differentiate between listening wireless devices
//Primary Task - Choose between major tasks of the device
//Primary Instruction - Choose function to call
//Arg1
//Arg2  
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int  intMenu, intSubmenu, intChoice, intEnd = -1;
char pointer = 0;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Booted");
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(){
  if(Serial.available()){
    pointer = (Serial.read());
    //intMenu = (pointer);//-48;
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("pointer");
    Serial.println("pointer");
    /*delay(500);
    int first = pointer % 10;
    int second = ((pointer/10) %10);

    for(int i=0; i < second; i++){
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
    }
    delay(1000);
    for (int i=0; i < first; i++){
      digitalWrite(13,HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
    }*/
  }
}



