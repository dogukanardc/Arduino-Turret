#include <Servo.h>

const int trigger_pin1 = 12;
const int echo_pin1 = 13;
const int trigger_pin2 = 11;
const int echo_pin2 = 10;

int sure1 ;
int mesafe1 ;
int sure2 ;
int mesafe2 ;

Servo ates;
Servo rotate;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  pinMode(trigger_pin1 , OUTPUT);
  pinMode(echo_pin1 ,INPUT);
  pinMode(trigger_pin2 , OUTPUT);
  pinMode(echo_pin2 ,INPUT);
  ates.attach(5);  // attaches the servo on pin 9 to the servo object
  rotate.attach(6);
}

void loop() {
  digitalWrite(trigger_pin1 , HIGH);
delayMicroseconds(1000);
digitalWrite(trigger_pin1 , LOW);
sure1 = pulseIn(echo_pin1 , HIGH);
mesafe1 = (sure1/2) / 29.1;
Serial.print("Mesafe1:");
Serial.print(mesafe1);

digitalWrite(trigger_pin2 , HIGH);
delayMicroseconds(1000);
digitalWrite(trigger_pin2 , LOW);
sure2 = pulseIn(echo_pin2 , HIGH);
mesafe2 = (sure2/2) / 29.1;
Serial.println("");
Serial.print("Mesafe2:");
Serial.print(mesafe2);
Serial.println("");
Serial.println("");
if (mesafe1 > 0 and mesafe2 > 0 and mesafe1 <= 50 and mesafe2 <= 50 ){
  rotate.write(45);
  Serial.println("Servo: 45");
   rotate.attach(6);
  ates.attach(5);
  delay(300);
  rotate.detach();
    ates.write(0);
    delay(100);
    ates.write(70);
    delay(300);
    ates.write(0);
    delay(100);
    ates.detach();
  }
 if (mesafe1 > 0 and mesafe1 <= 50 ){
  rotate.attach(6);
  rotate.write(90);
  Serial.println("Servo: 0");
  ates.attach(5);
  delay(300);
  rotate.detach();
    ates.write(0);
    delay(100);
    ates.write(70);
    delay(300);
    ates.write(0);
    delay(100);
    ates.detach();
  }
 if (mesafe2 > 0 and mesafe2 <= 50 ){
   rotate.attach(6);
  rotate.write(20);
  Serial.println("Servo: 90");
  ates.attach(5);
  delay(300);
  rotate.detach();
    ates.write(0);
    delay(100);
    ates.write(70);
    delay(300);
    ates.write(0);
    delay(100);
    ates.detach();
  }
}

void tarama() {
  for (pos = 20; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rotate.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    rotate.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
