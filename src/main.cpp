#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

void volumeUp(void);
void volumeDown(void);

Servo myservo;
int vol = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");
  IrReceiver.begin(13, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);

    if (command == 2) {
      myservo.attach(9);

      if (myservo.attached()) {
        volumeUp();
      }

      if (myservo.attached()) {
        myservo.detach();
      }
    }

    else if (command == 3) {
      myservo.attach(9);

      if (myservo.attached()) {
        volumeDown();
      }

      if (myservo.attached()) {
        myservo.detach();
      }
    }
    IrReceiver.resume();
  }
}

void volumeUp() {
  if (vol > 20) {
    vol = vol - 10;
    Serial.println(vol);
    myservo.write(vol);
    delay(200);
    myservo.detach();
    Serial.println("Successful");
  }
}

void volumeDown() {
  if (vol < 120) {
    vol = vol + 10;
    Serial.println(vol);
    myservo.write(vol);
    delay(200);
    myservo.detach();
    Serial.println("Successful");
  }
}