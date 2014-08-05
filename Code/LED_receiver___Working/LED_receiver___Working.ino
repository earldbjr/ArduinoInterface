#include <LiquidCrystal.h>
char buffer[5];
  LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(){
  if(Serial.available()){
    delay(10);
    for(int n=0; n<5; n++){
      buffer[n] = Serial.read();
      delay(10);
    }
    Serial.read(); //Clear '\0'
    for(int n=0; n<5; n++){
      lcd.print(buffer[n]);
    }
    if(buffer[0] == '1'){
      if(buffer[1] == '1'){
        if(buffer[2] =='1'){
          digitalWrite(13, HIGH);
        }
        if(buffer[2] == '2'){
          digitalWrite(13, LOW);
        }
      }
    }
  }
}




