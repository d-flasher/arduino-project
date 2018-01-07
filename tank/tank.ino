// библиотека для ИК приёмника
#include <IRremote.h>
// подключаем библиотеку для работы с сервоприводами
#include <Servo.h>
// создаём объект для управления сервоприводом
Servo myServoL;
Servo myServoR;

// даем имя пину подключения ИК приёмника
int RECV_PIN = 2;

// указываем к какому пину подключен ИК приёмник
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  // запускаем работу ИК приемника
  irrecv.enableIRIn();
  // подключаем сервоприводы
  //  myServoL.attach(4);
  //  myServoR.attach(8);
}

void loop()
{
  // принимаем данные с ИК пульта
  // в зависимости от нажатой кнопки пульта
  // даём разные команды роботу
  if (irrecv.decode(&results)) {
    if (results.value == 3772778233) {
      ford();
    } else if (results.value == 3772810873) {
      back();
    } else if (results.value == 3772819033) {
      left();
    } else if (results.value == 3772794553) {
      right();
    } else if (results.value == 3772782313) {
      stop();
    }
    // ждем следующее значение
    irrecv.resume();
  }
  //делаем задержку
  delay(100);
}

// функция движение вперёд
void ford() {
  attach();
  myServoL.write(110);
  myServoR.write(110);
}

// функция движение назад
void back() {
  attach();
  myServoL.write(70);
  myServoR.write(40);
}

// функция поворота налево
void left() {
  attach();
  myServoL.write(110);
  myServoR.write(70);
}

// функция поворота направо
void right() {
  attach();
  myServoL.write(70);
  myServoR.write(110);
}

// функция остановки
void stop() {
  //  myServoL.write(90);
  //  myServoR.write(90);
  myServoL.detach();
  myServoR.detach();
}

void attach() {
  if (!myServoL.attached()) {
    myServoL.attach(4);
  }

  if (!myServoR.attached()) {
    myServoR.attach(8);
  }
}

