#include <SoftwareSerial.h>
int M11=8;
int M12=9;
int M21=10;
int M22=11;
int led = 13;

void setup()
{
  Serial.begin(4800);
  pinMode(13, OUTPUT);
  pinMode(M11,OUTPUT);analogWrite(M11,0);
  pinMode(M12,OUTPUT);analogWrite(M12,0);
  pinMode(M21,OUTPUT);analogWrite(M21,0);
  pinMode(M22,OUTPUT);analogWrite(M22,0);

}

void loop()
{

  if(Serial.available())
  {
      char cmd = Serial.read();    //从串口读取指令
      switch(cmd)
     {
        case 'a':
            digitalWrite(led,HIGH);  //亮灯
           break;
        case 'b':
            SetMotor(0,0);//停止
           break;
        case 'c':
            SetMotor(-255,-255);//后退
           break;
       case 'd':
            SetMotor(255,255);//前进
           break;  
       case 'e':
            SetMotor(0,255);//右转
           break; 
       case 'f':
            SetMotor(255,0);//左转
           break;   
       default:
           break;
      
     }

  }
}
void SetMotor(float v1,float v2)
{
  if (v1>255){v1=255;analogWrite(M11,0);analogWrite(M12,v1);}
  else if (v1>0) {analogWrite(M11,0);analogWrite(M12,v1);}
  else if (v1>-255) {analogWrite(M12,0);analogWrite(M11,-v1);}
  else  {v1=-255;analogWrite(M12,0);analogWrite(M11,-v1);}
  
  if (v2>255){v2=255;analogWrite(M21,0);analogWrite(M22,v2);}
  else if (v2>0) {analogWrite(M21,0);analogWrite(M22,v2);}
  else if (v2>-255) {analogWrite(M22,0);analogWrite(M21,-v2);}
  else {v2=-255;analogWrite(M22,0);analogWrite(M21,-v2);}  
}
