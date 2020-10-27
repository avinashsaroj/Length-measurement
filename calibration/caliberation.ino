constint echoPin = 2;
/**
 * The digital pin that sends output to the ultrasonic sensor.
*/
constint trigPin = 4;
voidsetup() {
pinMode(echoPin, INPUT);  // Register echoPin for receiving input
pinMode(trigPin, OUTPUT);  // Register trigPin for sending output
  Serial.begin(9600);  // Begin serial communication to receive data from the ultrasonic sensor
}
voidloop() {
// Send a short low pulse to ensure a clean high one.
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Send a ten-second high pulse.
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Read the high pulse and print out its duration.
constlong duration = pulseIn(echoPin, HIGH);
  Serial.print("Period (microseconds): ");
  Serial.println(duration);
}
