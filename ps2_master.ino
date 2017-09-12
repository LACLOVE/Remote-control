#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2); // RX, TX
//摇杆PS2
int JoyStick_X = A0; //x
int JoyStick_Y = A1; //y
int JoyStick_Z = 5; //key

const int buttonPin = 4;  
int buttonState = 0;   
char flag;

void setup()  
{
  pinMode(buttonPin, INPUT);
  pinMode(JoyStick_Z, INPUT); 
  digitalWrite(buttonPin, HIGH); 
  Serial.begin(9600);
  mySerial.begin(4800);

}

void loop() 
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
      flag='a';
      mySerial.write(flag);
      Serial.println(flag);
  }
//  else if(buttonState == LOW){
//    flag='b';
//    mySerial.write(flag);
//    Serial.println(flag);
//    }
   else if(x==512&&y==512){
    flag='b';
    mySerial.write(flag);
    Serial.println(flag);
    }
   else if(x>512){
    flag='c';
    mySerial.write(flag);
    Serial.println(flag);
    }
  else if(x<512){
    flag='d';
    mySerial.write(flag);
    Serial.println(flag);
    }
  else if(y>512){
    flag='e';
    mySerial.write(flag);
    Serial.println(flag);
    }
  else if(y<512){
    flag='f';
    mySerial.write(flag);
    Serial.println(flag);
    }
}

