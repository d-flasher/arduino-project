#include <Servo.h>

Servo myservo1;
Servo myservo2;
int DELAY;
int isLoop;

void setup() {
  Serial.begin(9600);
  myservo1.attach(4);
  myservo2.attach(8);
  DELAY = 3000;
}

void loop() {
  if (isLoop == 1) return;
  Serial.println("loop");

  int MY_SIZE = 5;
  int myarray[MY_SIZE] = {45, 67, 90, 112, 135};
  for (int i = 0; i < MY_SIZE; i++) {
    Serial.println(String(myarray[i]) + " rad");
    Serial.println("");
    myservo1.write(myarray[i]);
    myservo2.write(myarray[i]);

    delay(DELAY);

    if (i == MY_SIZE - 1) {
      Serial.println("return");
      Serial.println("");
      myservo1.detach();
      myservo2.detach();
    }
  }

  isLoop = 1;
}
