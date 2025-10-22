const int trigPin = 3;
const int echoPin = 2;
const int ledPin = 12;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  if (distance < 30) {    // ako je distance manja od 30
    digitalWrite(ledPin, HIGH);  // upali LED
    delay(5000);
  } else {
    digitalWrite(ledPin, LOW);   // ugasi LED
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
