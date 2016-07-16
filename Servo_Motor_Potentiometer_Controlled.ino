#include <Servo.h>                                                //Include Servo.h library

Servo sMotor;                                                     //Establishing sMotor with Servo library

const int potPin = A0;                                            //Tying potPin to A0 pin
int potVal;                                                       //Initializing variables that will hold values later
int angle;

void setup() {
  // put your setup code here, to run once:
  sMotor.attach(9);                                               //Attach servo motor to pin 9.
  
  Serial.begin(9600);                                             //Sets the data rate for serial communication to my computer. 
}

void loop() {
  // put your main code here, to run repeatedly:

  potVal = analogRead(potPin);                                    //potVal set equal to an analog reading of the potentiometer's value.
  Serial.print("Potentiometer Value : ");                         //Print to my computer this text.
  Serial.print(potVal);                                           //Print to my computer the analog reading of the potentiometer's value.

  angle = map(potVal, 0, 1023, 0, 179);                           //usign map function angle is determined comparing the potVal's lower current limit(0) and upper current limit(1023) to the lower angle limit(0) and upper angle limit(179).
  Serial.print("Angle is : ");                                    //Print to my computer this text.
  Serial.println(angle);                                          //Print to my computer the determined angle value.

  sMotor.write(angle);                                            //PWM output to motor determined by angle. The motor should move to the specified angle
  delay(15);                                                      //Small delay to give the motor some time receive information.
}
