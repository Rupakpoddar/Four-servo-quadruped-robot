/*
 Written by: Rupak Poddar
 www.youtube.com/RupakPoddar
 
 Wiring Setup:
 HC05 Bluetooth module pin TX - Arduino pin RX
 HC05 Bluetooth module pin RX - Arduino pin TX

 Front left servo motor   - Digital pin 4
 Front right servo motor  - Digital pin 6
 Rear left servo motor    - Digital pin 8
 Rear right servo motor   - Digital pin 11
*/
#include <Servo.h>

Servo fl; //  0   
Servo fr; //  180
Servo bl; //  0
Servo br; //  180

void setup() {
  Serial.begin(9600);
  fl.attach(4);
  fr.attach(6);
  bl.attach(8);
  br.attach(11);

  fl.write(90);
  fr.write(90);
  bl.write(90);
  br.write(90);
  delay(1000);
}

void loop(){
  
String readString;
while (Serial.available()) {
  readString = Serial.readString();
  Serial.println(readString);
}

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

/*if (readString == "s") 
{
normalpos();
}*/

if (readString == "LED_ON") 
{
sleep();
}

if (readString == "LED_OFF") 
{
normalpos();
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
