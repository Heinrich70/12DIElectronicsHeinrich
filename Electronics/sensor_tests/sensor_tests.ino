// Pin definitions for Sensor 1
#define TRIG_PIN_1 9
#define ECHO_PIN_1 10

// Pin definitions for Sensor 2
#define TRIG_PIN_2 11
#define ECHO_PIN_2 12

void setup() {
  Serial.begin(9600);

  // Set pin modes for Sensor 1
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  // Set pin modes for Sensor 2
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  Serial.println("Ultrasonic Sensor Test Started");
}

void loop() {
  // Read distance from both sensors
  long distance1 = getDistance(TRIG_PIN_1, ECHO_PIN_1);
  long distance2 = getDistance(TRIG_PIN_2, ECHO_PIN_2);

  // Print results
  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");

  Serial.print("Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  delay(1); // Wait half a second before next reading
}

// Function to get distance from one ultrasonic sensor
long getDistance(int trigPin, int echoPin) {
  // Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (speed of sound: 343m/s)
  long distance = duration * 0.034 / 2;

  return distance;
}
