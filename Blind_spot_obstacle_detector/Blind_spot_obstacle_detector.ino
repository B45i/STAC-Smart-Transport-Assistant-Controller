const int trigPin1  = 3;
const int echoPin1  = 4;
const int trigPin2  = 5;
const int echoPin2  = 6;
const int trigPin3  = 7;
const int echoPin3  = 8;

const int leftLED = 9;
const int straightLED = 10;
const int rightLED = 11;
const int buzzerPin = 12;

int minLeft = 5;
int minStraight = 5;
int minRight = 5;

void stopAlert(int alertPin) {
  digitalWrite(buzzerPin, LOW);
  digitalWrite(alertPin, LOW);
}

void alert(int alertPin) {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(alertPin, HIGH);
}

void setup() {
  Serial.begin (9600);

  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(straightLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}
 
void loop() {
  int leftdistance = getDistance(trigPin1, echoPin1);
  int straightDistance = getDistance(trigPin2, echoPin2);
  int rightDistance = getDistance(trigPin3, echoPin3);

  Serial.print("Left: ");
  Serial.print(leftdistance);
  Serial.print(", Straight: ");
  Serial.print(straightDistance);
  Serial.print(", Right: ");
  Serial.println(rightDistance);

  if(leftdistance < minLeft) { alert(leftLED); }
  else { stopAlert(leftLED); }

  if(straightDistance < minStraight) { alert(straightLED); }
  else { stopAlert(straightLED); }

  if(rightDistance < minRight) { alert(rightLED); }
  else { stopAlert(rightLED); }


}
 
int getDistance(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  return  duration*0.034/2;
}
