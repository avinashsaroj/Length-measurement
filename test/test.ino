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
// Store the high pulse's duration.
constlong duration = pulseIn(echoPin, HIGH);
// Calculate and print the distance to the target.
constdouble distance = microsecondsToDistance(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}
/**
 * @param microseconds a number of microseconds
 * @return the conversion of the provided microseconds into a distance
*/
constdoublemicrosecondsToDistance(constlong microseconds) {
// Initialize m and b to their respective values in the formula, y = mx + b.
// y = distance, x = time (in microseconds).
constdouble m = 1.0;
constdouble b = 0.0;
return m * microseconds + b;
}
