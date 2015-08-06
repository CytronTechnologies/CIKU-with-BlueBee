//  Author              :CYTRON	Technologies
//	Project             :Controlling Mobile Robot using Android
//	Project description	:This robot is using BlueBee to communicate with the Smartphone through bluetooth
//  IDE                 :MPLAB X IDE v2.30
//  Compiler            :X8 Compiler v1.31 (default XC)
//  Date                :1 August 2015
//  Example code is provided as "it is", Cytron Technologies do not take responsibility to
//  verify, improve or explain the working of the code.
//  If you have any inquiry, welcome to discuss in our techcanil forum:
//  http://forum.cytron.com.my
//============================================================================================================

#include "Arduino.h"
#include "HardwareSerial.h"

int key = 0;
int motor1 = 4;
int motor2 = 7;
int speedmotor1 = 5;
int speedmotor2 = 6;

void forward(int speedmotor1, int speedmotor2);
void backward(int speedmotor1, int speedmotor2);
void left(int speed1, int speed2);
void right(int speed1, int speed2);

void setup()
{
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(speedmotor1, OUTPUT);
  pinMode(speedmotor2, OUTPUT);
  Serial_begin(9600);
}

void loop()
{
  if(Serial_available() > 0)
  {
    delay(10);

    Serial_read();
    Serial_read();
    Serial_read();
    key = Serial_read();
    Serial_read();


    if(key == '0')
    {
      forward(0,0);
    }
    else if(key == '1')//UP
    {
      forward(500,500);
    }
    else if(key == '2') //DOWN
    {
      backward(500,500);
    }
    else if(key == '3') //LEFT
    {
      left(500,500);
    }
    else if(key == '4') //RIGHT
    {
      right(500,500);
    }
    else if(key == '5'); //SELECT
    else if(key == '6'); //START
    else if(key == '7'); //TRIANGLE
    else if(key == '8'); //SQUARE
    else if(key == '9'); //X
    else if(key == 'A'); //CIRCLE

  }
}
void forward(int speed1, int speed2)
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  analogWrite(speedmotor1, speed1);
  analogWrite(speedmotor2, speed2);
}
void backward(int speed1, int speed2)
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  analogWrite(speedmotor1, speed1);
  analogWrite(speedmotor2, speed2);
}
void left(int speed1, int speed2)
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  analogWrite(speedmotor1, speed1);
  analogWrite(speedmotor2, speed2);
}
void right(int speed1, int speed2)
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  analogWrite(speedmotor1, speed1);
  analogWrite(speedmotor2, speed2);
}