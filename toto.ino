#include <Servo.h>

char command;
 Servo myservo;

void setup() 
{       
  Serial.begin(9600);
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
   pinMode(3,OUTPUT);

 
}

void loop(){
   myservo.attach(9);
      myservo.write(180);              
    delay(150);
    myservo.write(0);              
    delay(150);  

  if(Serial.available() > 0){ 
   

    command = Serial.read(); 
    // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  Stop();
delay(10);
    Serial.println(command);
    Stop();
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case '1':  
      forward();
      break;
    case '2':  
       back();
      break;
    case '4':  
      left();
      break;
    case '3':
      right();
      break;
       case '5':
      Stop();
      break;
        
    }
  } 
}

void forward()
{
  digitalWrite(13,LOW);
 digitalWrite(12,HIGH);
  digitalWrite(8,LOW);
 digitalWrite(7,HIGH); 
   digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
delay(20);
}

void back()
{
    digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
  digitalWrite(8,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
delay(20);

}

void right()
{
 digitalWrite(13,LOW);
 digitalWrite(12,HIGH);
  digitalWrite(8,HIGH);
 digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
delay(15);

}

void left(){
   digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
  digitalWrite(8,LOW);
 digitalWrite(7,HIGH);
 digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
delay(15);
}

void Stop()
{
   digitalWrite(13,LOW);
 digitalWrite(12,LOW);
  digitalWrite(8,LOW);
 digitalWrite(7,LOW);
  digitalWrite(6,LOW);
digitalWrite(5,LOW);
delay(1000);
 
}

