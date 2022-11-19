#include <Servo.h>
Servo tap1_servo;
Servo tap2_servo;
int IR_sensor1=4;
int IR_sensor2=3;
int val;
int val_1;

void setup() {
 
  pinMode(IR_sensor1,INPUT);
  pinMode(IR_sensor2,INPUT);
  tap1_servo.attach(2);
  tap2_servo.attach(5);
  pinMode (7, OUTPUT);
}

void loop() {
  val=digitalRead(IR_sensor1);
  if(val==0)
  {
    tap1_servo.write(0);
    tap2_servo.write(0);
    tone (7,300,150);
    delay (250);
    tone (7, 700,400);
    delay (250);
    
  }
    val_1=digitalRead(IR_sensor2);
if(val_1==0)
  {
    tap1_servo.write(90);
    tap2_servo.write(90);
  }

}
