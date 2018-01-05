#include <Servo.h>

Servo myservo;
int DELAY;
int isLoop;

void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  DELAY = 5000;
}

void loop() {
  if (isLoop == 1) return;
  Serial.println("loop");

  int MY_SIZE = 9;
  int myarray[MY_SIZE] = {0, 23, 45, 67, 90, 112, 135, 157, 180};
  for (int i = 0; i < MY_SIZE; i++) {
    Serial.println(String(myarray[i]) + " rad");
    Serial.println("");
    myservo.write(myarray[i]);

    delay(DELAY);

    if (i == MY_SIZE - 1) {
      Serial.println("return");
      Serial.println("");
      myservo.detach();
    }
  }

  isLoop = 1;
}
