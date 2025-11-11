 #include <Servo.h>
const int servoPin1 = 6;
const int servoPin2 = 7;

Servo servo1;
Servo servo2;
//setup code
void setup() {
  // put your setup code here, to run once:
servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // put your main code here, to run repeatedly:
openBarrier(); // Start with arms up
delay(1000);
closeBarrier();
delay(1000);
}

void closeBarrier() {
  servo1.write(0);     // Left barrier down
  servo2.write(180);   // Right barrier down
}

void openBarrier() {
  servo1.write(90);    // Arms up
  servo2.write(90);
}
