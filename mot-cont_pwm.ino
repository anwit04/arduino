// Pin definitions (adjust as needed)
const int pin0 = 2;  // P3.0 → Arduino pin 2
const int pin1 = 3;  // P3.1 → Arduino pin 3
const int pin5 = 4;  // P3.5 → Arduino pin 4

void setup() {
  // Set pins as OUTPUT
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin5, OUTPUT);

  // Initial states
  digitalWrite(pin1, HIGH); // SETB P3.1
  digitalWrite(pin0, LOW);  // CLR P3.0
}

void loop() {
  // Turn ON
  digitalWrite(pin5, HIGH); // SETB P3.5
  onDelay();                 // Call ON delay

  // Turn OFF
  digitalWrite(pin5, LOW);  // CLR P3.5
  offDelay();                // Call OFF delay
}

// --- Nested loop delay function (ON) ---
void onDelay() {
  for (int R1 = 0; R1 < 7; R1++) {
    for (int R2 = 0; R2 < 255; R2++) {
      // Empty loop to simulate delay
      asm volatile("nop"); // Prevent optimization
    }
  }
}

// --- Nested loop delay function (OFF) ---
void offDelay() {
  for (int R1 = 0; R1 < 7; R1++) {
    for (int R2 = 0; R2 < 255; R2++) {
      // Empty loop to simulate delay
      asm volatile("nop"); // Prevent optimization
    }
  }
}
