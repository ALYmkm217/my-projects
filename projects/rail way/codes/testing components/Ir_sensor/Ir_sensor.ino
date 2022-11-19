int sensor=4;
int val;
void setup() {
 pinMode (sensor,INPUT);
 Serial.begin(9600);
}

void loop() { 
  val=digitalRead(sensor);
  if(val==LOW){
 Serial.println("on");}
 
 else
 {  
  Serial.println("off");
 }
 

}
