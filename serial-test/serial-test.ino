#include <IRremote.h>

// подключение ИК-приемника
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    // отображаем значение от ИК-пульта
    Serial.println(results.value);

    // ждем следующее значение
    irrecv.resume();
  }

  delay(1000);
}
