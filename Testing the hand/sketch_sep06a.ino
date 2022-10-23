#include <Servo.h>
Servo sevro1;
Servo sevro2;
Servo sevro3;
Servo sevro4;
Servo sevro5;

void setup() {
  sevro1.attach(15);
  sevro2.attach(16);
  sevro3.attach(17);
  sevro4.attach(18);
  sevro5.attach(19);

} 

void loop() {
  delay (2000);
  sevro1.write(180);
  delay (4000);
  sevro1.write(0);
  delay (4000);
  sevro4.write(180);
  delay (4000);
  sevro4.write(0);
  delay (6000);
  sevro5.write(0);
  delay (4000);
  sevro5.write(180);
  delay (4000);
  sevro2.write(180);
  delay (4000);
  sevro2.write(0);
  delay(4000);
  sevro3.write(180);
  delay (4000);
  sevro3.write(0);
  delay (2000);
  sevro1.write(180);
  sevro4.write(180);
  sevro5.write(0);
  sevro2.write(180);
  sevro3.write(180);
  delay (4000);
  sevro1.write(0);
  sevro4.write(0);
  sevro5.write(180);
  sevro2.write(0);
  sevro3.write(0);
  delay (1000000000);
}
