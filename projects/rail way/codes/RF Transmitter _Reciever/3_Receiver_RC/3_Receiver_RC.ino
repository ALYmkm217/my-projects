#include <RCSwitch.h>

const int btnSelectLinePin   = 7;

const int ledNormalLineAPin = 3;
const int ledNormalLineBPin = 4;

const int ledFaultLineAPin  = 5;
const int ledFaultLineBPin  = 6;

const int trailRelayPin     = 8;

int lineState    = 0;

bool lineAFlag  = true ;
bool lineBFlag  = false ;

bool statusFaultlineAFlag   = false ;
bool statusFaultlineBFlag   = false ;

RCSwitch mySwitch = RCSwitch();

void setup() {
  
  Serial.begin(115200);

  mySwitch.enableReceive(0);  
  // Arduino Uno Receiver on interrupt 0 => that is pin #2 

  pinMode(ledNormalLineAPin  , OUTPUT );
  pinMode(ledNormalLineBPin  , OUTPUT );

  pinMode(ledFaultLineAPin  , OUTPUT );
  pinMode(ledFaultLineBPin  , OUTPUT );

  pinMode(trailRelayPin     , OUTPUT );
    
  pinMode(btnSelectLinePin    , INPUT  );
  
  lineState    = 0;

  Serial.println("Hello Trains Receiver");
 
}



void loop() {

  lineState   = digitalRead(btnSelectLinePin);

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


  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    Serial.print("value = ");
    Serial.println(value);

//    if (mySwitch.getReceivedValue()) {
//        process();
//    }

    switch (value){
      case 1:
       Serial.println("Fault on Line A");
       digitalWrite(ledFaultLineAPin  ,HIGH );
       digitalWrite(ledFaultLineBPin  ,LOW );
       statusFaultlineAFlag  = true ;
       statusFaultlineBFlag  = false ;
      break;
    
      case 2:
       Serial.println("Fault on Line B");
       digitalWrite(ledFaultLineAPin  ,LOW );
       digitalWrite(ledFaultLineBPin  ,HIGH );
       statusFaultlineAFlag  = false ;
       statusFaultlineBFlag  = true ;
      break;

      case 3:
       Serial.println("Normal Status");
       digitalWrite(ledFaultLineAPin  ,LOW );
       digitalWrite(ledFaultLineBPin  ,LOW );
       statusFaultlineAFlag  = false ;
       statusFaultlineBFlag  = false ;
      break; 
  }

  if ( statusFaultlineAFlag && lineAFlag ) {
     Serial.println("Relay Stopped A ");
       digitalWrite(trailRelayPin  ,LOW );
  }
//  else {
//         Serial.println("Relay Not Stopped A ");
//       digitalWrite(trailRelayPin  ,HIGH );
//  }

  if ( statusFaultlineBFlag && lineBFlag ) {
         Serial.println("Relay Stopped B ");
       digitalWrite(trailRelayPin  ,LOW );
  } 
//  else {
//      Serial.println("Relay Not Stopped B ");
//       digitalWrite(trailRelayPin  ,HIGH );
//  }

  if ( !statusFaultlineAFlag && !statusFaultlineBFlag ) {
      Serial.println("Not Not");
       digitalWrite(trailRelayPin  ,HIGH );
  }
    
    mySwitch.resetAvailable();
    
    Serial.println("  ");  
   }
   
  delay(250); 
}
