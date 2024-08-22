#include<SoftwareSerial.h>

char AA= 5; // right side 
char AB= 6; // right side 
char BA= 7; // left side 
char BB= 8; // left side  
char rot = 1;

#define rxPin 9
SoftwareSerial bt (rxPin,1); /* (Rx,Tx) */  
void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */

  pinMode(AA,OUTPUT);
  pinMode(BB,OUTPUT);
  pinMode(AB,OUTPUT);
  pinMode(BA,OUTPUT);

  bt.begin(9600); /* Define baud rate for software serial communication */

}
int x;
void loop() {  
 if(bt.available())x = bt.read();

     if ((x==70)){
       digitalWrite(AA,HIGH);
       digitalWrite(BA,HIGH);
       delayMicroseconds(800);
       digitalWrite(AA,LOW);
       delayMicroseconds(100);
       digitalWrite(BA,LOW);
       delayMicroseconds(150);
       }

     else if(x==66){
       digitalWrite(AB,HIGH);
       digitalWrite(BB,HIGH);
       delayMicroseconds(800);
       digitalWrite(AB,LOW);
       delayMicroseconds(100);
       digitalWrite(BB,LOW);
       delayMicroseconds(150);
     }
     
     else if(x==76){
      digitalWrite(BA,HIGH);
      digitalWrite(AB,HIGH);
      delay(1);
      digitalWrite(AB,LOW);
      delay(0.5);
      // left side is forward and full speed (1.5 ms)
      // right side is in reverse and lower speed (1 ms).
      // car module turns to the Right,
     }
     
     else if(x==82){
      digitalWrite(AA,HIGH);
      digitalWrite(BB,HIGH);
      delay(1);
      digitalWrite(BB,LOW);
      delay(0.5);
      // right side is forward and full speed (1.5 ms)
      // left side is in reverse and lower speed (1 ms).
      // car module turns to the left,
     }
     else if(x==83) stop_();  
}
void stop_(){
      digitalWrite(AA,LOW);
      digitalWrite(AB,LOW);
      digitalWrite(BA,LOW);
      digitalWrite(BB,LOW);
}
