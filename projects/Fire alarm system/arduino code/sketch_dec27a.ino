
const int buzzerPin = 2;
const int flamePin = 8;
int Flame = HIGH;
int greenled = 3;
int redled = 4;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    Serial.print(Flame);
       Serial.print("\t");
       Serial.print("\n");
   delay (300);
  }
  else
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
        Serial.print(Flame);
       delay (300);

  }
}
