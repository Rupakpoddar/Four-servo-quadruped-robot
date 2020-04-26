/*
 Developer Rupak Poddar
 www.youtube.com/RupakPoddar
 
 Wiring Setup-
 HC05 BLUETOOTH MODULE pin tx - ARDUINO pin rx
 HC05 BLUETOOTH MODULE pin rx - ARDUINO pin tx
 */
#include <Servo.h>

Servo fl;//0   
Servo fr;//180
Servo bl;//0
Servo br;//180

String readString;

void setup() {
  Serial.begin(9600);
  fl.attach(4);//connect front left motor to digital pin 4.  
  fr.attach(6);//connect front right motor to digital pin 6. 
  bl.attach(8);//connect rear left motor to digital pin 8.
  br.attach(11);//connect rear right motor to digital pin 11.

  fl.write(90);
  fr.write(90);
  bl.write(90);
  br.write(90);
  delay(1000);
}

void loop()
{
while (Serial.available()) {
delay(3); 
char c = Serial.read();
readString += c; 
}
if (readString.length() >0) {
Serial.println(readString);
if (readString == "f") 
{
forward();
}
if (readString == "b") 
{
backward();
}
if (readString == "l") 
{
left();
}
if (readString == "r") 
{
right();
}
if (readString == "s") 
{
normalpos();
}
if (readString == "ledon") 
{
sleep();
}
if (readString == "ledoff") 
{
normalpos();
}
readString="";
}
}
void forward()
{
    fr.write(180);
    delay(250);
    fl.write(0);
    delay(250);
    br.write(180);
    delay(250);
    bl.write(0);
    delay(250);
    
    fr.write(60);
    fl.write(130);
    br.write(60);
    bl.write(130);
    delay(250);   
    
    fr.write(90);
    delay(250);
    fl.write(90);
    delay(250);
    br.write(90);
    delay(250);
    bl.write(90);
}

void backward()
{
    bl.write(180);
    delay(250);
    br.write(0);
    delay(250);
    fl.write(180);
    delay(250);
    fr.write(0);
    delay(250);

    bl.write(60);
    br.write(130);
    fl.write(60);
    fr.write(130);
    delay(250);

    bl.write(90);
    delay(250);
    br.write(90);
    delay(250);
    fl.write(90);
    delay(250);
    fr.write(90); 
}

void left()
{
 fr.write(180);
 delay(250);
 fl.write(180);
 delay(250);
 br.write(180);
 delay(250);
 bl.write(180);
 delay(250);

 fr.write(60);
 fl.write(60);
 br.write(60);
 bl.write(60);
 delay(250);

 fr.write(90);
 delay(250);
 fl.write(90);
 delay(250);
 br.write(90);
 delay(250);
 bl.write(90);
}

void right()
{
  br.write(0);
  delay(250);
  bl.write(0);
  delay(250);
  fr.write(0);
  delay(250);
  fl.write(0);
  delay(250);

  br.write(130);
  bl.write(130);
  fr.write(130);
  fl.write(130);
  delay(250);

  br.write(90);
  delay(250);
  bl.write(90);
  delay(250);
  fr.write(90);
  delay(250);
  fl.write(90);
}

void sleep()
{
  fl.write(0);
  fr.write(180);
  bl.write(180);
  br.write(0);
}
 
void normalpos()
{
  fr.write(90);
  br.write(90);
  fl.write(90);
  bl.write(90);
}
