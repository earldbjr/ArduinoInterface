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

//int  intMenu, intSubmenu, intChoice, intEnd = -1;
char buffer[5];

void setup(){
  lcd.begin(16, 2);
  lcd.print("Booted");
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

  if(Serial.available()){
    //delay(10);
    //if(Serial.peek() == '<'){
      //Serial.read();             // Erase <
      delay(10);
      for(int n=0; n<5; n++){    //Get Data
        buffer[n] = Serial.read();
        delay(10);
      }
      Serial.read();//Clear '\0', otherwise buffer refills from \0
      lcd.setCursor(0,1);
      for(int i=0;i<5;i++){
        lcd.print(buffer[i]);
        Serial.println(buffer[i]);
      }
    //}

  }
}
