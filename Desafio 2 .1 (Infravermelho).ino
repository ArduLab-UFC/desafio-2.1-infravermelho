#define rLedPin 13
#define yLedPin 12
#define bLedPin 11

#define irSensor 3

int irPreviousState = HIGH;
int count = 0;

void setup(){
  pinMode(rLedPin, OUTPUT);
  pinMode(yLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(irSensor, INPUT);
}

void loop(){
  
  int irCurrentState = digitalRead(irSensor); 

  if (irCurrentState != irPreviousState) {
    irPreviousState = irCurrentState;

    if (irCurrentState == LOW) {
      count++;
      if (count > 7) { 
        count = 0;
      }
      binaryLedPrint(count); 
    }
  }

  delay(50); 
}


void binaryLedPrint(int decimalNum){
    switch (count) {
      case 0:
        digitalWrite(rLedPin, LOW);
        digitalWrite(yLedPin, LOW);
        digitalWrite(bLedPin, LOW);
        break;
      case 1:
        digitalWrite(rLedPin, HIGH);
        digitalWrite(yLedPin, LOW);
        digitalWrite(bLedPin, LOW);
        break;
      case 2:
        digitalWrite(rLedPin, LOW);
        digitalWrite(yLedPin, HIGH);
        digitalWrite(bLedPin, LOW);
        break;
      case 3:
        digitalWrite(rLedPin, HIGH);
        digitalWrite(yLedPin, HIGH);
        digitalWrite(bLedPin, LOW);
        break;
      case 4:
        digitalWrite(rLedPin, LOW);
        digitalWrite(yLedPin, LOW);
        digitalWrite(bLedPin, HIGH);
        break;
      case 5:
        digitalWrite(rLedPin, HIGH);
        digitalWrite(yLedPin, LOW);
        digitalWrite(bLedPin, HIGH);
        break;
      case 6:
        digitalWrite(rLedPin, LOW);
        digitalWrite(yLedPin, HIGH);
        digitalWrite(bLedPin, HIGH);
        break;
      case 7:
        digitalWrite(rLedPin, HIGH);
        digitalWrite(yLedPin, HIGH);
        digitalWrite(bLedPin, HIGH);
        break;
      case 8:
        count = 0;
        break;
      default:
        break;
    }
}