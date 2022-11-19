#include <Servo.h>
Servo tap1_servo;
Servo tap2_servo;
int IR_sensor1=3;
int IR_sensor2=2;
int val;
int val_1;

void setup() {
 
  pinMode(IR_sensor1,INPUT);
  pinMode(IR_sensor2,INPUT);
  tap1_servo.attach(9);
  tap2_servo.attach(8);
  pinMode ( 7 , OUTPUT);
  pinMode (0 , OUTPUT);
  pinMode (1, OUTPUT);
   pinMode (4 , OUTPUT);
  pinMode (5, OUTPUT);
}

void loop() {
  val=digitalRead(IR_sensor1);
  if(val==0)
  {
    tap1_servo.write(0);
    tap2_servo.write(0);
     digitalWrite (0 , HIGH);
     delay (75);
          digitalWrite (0 , LOW);
     delay (100);
     digitalWrite (1 , HIGH);
     delay (75);
     
     digitalWrite (1 , LOW);
     delay (100);
          digitalWrite (1 , HIGH);
     delay (100);
     digitalWrite (0 , HIGH);
     delay (100);
     


     digitalWrite (4 , HIGH);
     delay (75);
          digitalWrite (4 , LOW);
     delay (100);
     digitalWrite (5 , HIGH);
     delay (75);
     
     digitalWrite (5 , LOW);
     delay (100);
          digitalWrite (4 , HIGH);
     delay (100);
     digitalWrite (5 , HIGH);
     delay (100);
     

  }
    val_1=digitalRead(IR_sensor2);
if(val_1==0)
  {
    tap1_servo.write(90);
    tap2_servo.write(90);
      digitalWrite (0 , LOW);
      digitalWrite (1 , LOW);


      digitalWrite (4 , LOW);
      digitalWrite (5 , LOW);
  }
if( val==0)
{

    tone (7,600,250);
    delay(200);
    tone ( 7,300,150);
    delay(200);
     digitalWrite (7 , HIGH);

}
if (val_1==0){
      digitalWrite (7 , LOW);}
}
