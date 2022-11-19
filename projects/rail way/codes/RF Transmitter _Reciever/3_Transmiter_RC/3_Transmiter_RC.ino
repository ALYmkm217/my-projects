  
#include <RCSwitch.h>

const int btnSelectLinePin   = 6;
const int btnSelectStatusPin = 7;

const int ledNormalLineAPin = 2;
const int ledNormalLineBPin = 3;

const int ledFaultLineAPin  = 4;
const int ledFaultLineBPin  = 5;

int lineState    = 0;
int statusState  = 0;

bool lineAFlag  = true ;
bool lineBFlag  = false ;

bool statusNormalFlag  = true ;
bool statusFaultFlag   = false ;

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(115200);

  pinMode(ledNormalLineAPin  , OUTPUT );
  pinMode(ledNormalLineBPin  , OUTPUT );

  pinMode(ledFaultLineAPin  , OUTPUT );
  pinMode(ledFaultLineBPin  , OUTPUT );
  
  pinMode(btnSelectLinePin    , INPUT  );
  pinMode(btnSelectStatusPin  , INPUT  );

// Arduino Uno Transmitter is connected to Arduino Pin #10 
   mySwitch.enableTransmit(10);

  lineState    = 0;
  statusState  = 0;

  Serial.println("Hello Trains Transmitter");
    
}

void loop() {

  lineState   = digitalRead(btnSelectLinePin);
  statusState = digitalRead(btnSelectStatusPin);
 
     
  if ( lineState == HIGH ) {
      Serial.println("lineState Pressed");

      if ( lineAFlag  ) {
           lineAFlag  = false ;
           lineBFlag  = true ;
      } else {
           lineAFlag  = true ;
           lineBFlag  = false ;
      }
  }

  if (statusState == HIGH) {
      Serial.println("statusState Pressed");

      if ( statusNormalFlag  ) {
        statusNormalFlag  = false ;
        statusFaultFlag  = true ;
      } else {
        statusNormalFlag  = true ;
        statusFaultFlag  = false ;
      }
  }



   
  if ( lineAFlag ) {

//     Serial.println("Train on Line A");
     digitalWrite(ledNormalLineAPin    ,HIGH );
     digitalWrite(ledNormalLineBPin    ,LOW );
//     mySwitch.send("A", 24);  
//     mySwitch.send(1, 24);
      
  } else {
//    Serial.println("Train Not Stopped on Line A");
    digitalWrite(ledNormalLineAPin    ,LOW );

  }

    if ( lineBFlag ) {

//     Serial.println("Train on Line B");
     digitalWrite(ledNormalLineBPin    ,HIGH );
     digitalWrite(ledNormalLineAPin    ,LOW );
//     mySwitch.send("A", 24);  
//     mySwitch.send(1, 24);
      
  } else {
//    Serial.println("Train Not Stopped on Line A");
    digitalWrite(ledNormalLineBPin    ,LOW );

  }


  if ( statusFaultFlag ) {

    if ( lineAFlag ) {
         Serial.println("Train Stopped on Line A");
         mySwitch.send(1, 24);
         digitalWrite(ledFaultLineAPin    ,HIGH );
    } else {
         digitalWrite(ledFaultLineAPin    ,LOW );
    }

    if ( lineBFlag ) {
         Serial.println("Train Stopped on Line B");
         mySwitch.send(2, 24);
         digitalWrite(ledFaultLineBPin    ,HIGH );
    } else {
         digitalWrite(ledFaultLineBPin    ,LOW );
    }
      
  } else {

//    Serial.println("Train Not Stopped on Line B");
    digitalWrite(ledFaultLineAPin    ,LOW );
    digitalWrite(ledFaultLineBPin    ,LOW );
    mySwitch.send(3, 24);
  }
  
  delay(250);


  
}
