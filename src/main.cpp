#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

Servo myservo;

int potpin = 0;
int val;

int vol;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK);

  myservo.attach(9);

  vol = myservo.read();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);
    IrReceiver.resume(); // Enable receiving of the next value
  }

  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  delay(15);
}