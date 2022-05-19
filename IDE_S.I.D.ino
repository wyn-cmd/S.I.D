
// setup
void setup() {
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
}

// variables
long duration, inches, cm, cm2;
int pingPin = 7;
int pingPin2 = 8;


void loop() {
  //indicator light
  digitalWrite(2, HIGH);
  
  //ping sensor 1
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);


  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);


  //ping sensor 2
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

  pinMode(pingPin2, INPUT);
  duration = pulseIn(pingPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration);


  if (cm2 > 30) {if (cm < 30){tone(5, 300);} else{noTone(5);}}
  else {digitalWrite(2,LOW);}

}


//convert the time taken for the sound into distance
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
