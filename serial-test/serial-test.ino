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
    Serial.println(results.value);

    // "центр"
    if (results.value == 3772782313) {
      Serial.println("Стоп");
    }

    // "вверх"
    if (results.value == 3772778233) {
      Serial.println("Оба вперед");
    }

    // "вниз"
    if (results.value == 3772810873) {
      Serial.println("Оба назад");
    }

    // "влево"
    if (results.value == 3772819033) {
      Serial.println("Левый назад, Правый вперед");
    }

    // "вправо"
    if (results.value == 3772794553) {
      Serial.println("Правый назад, Левый вперед");
    }

    // ждем следующее значение
    irrecv.resume();
  }

  delay(1000);
}
