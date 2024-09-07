/**
 * @brief Demo Two Month Pico code. Blinks an LED and responds to a few basic serial commands.
 * 
 */

const uint32_t BLINK_INTERVAL = 1000;
uint32_t lastBlink = 0;
bool ledState = false;

void setup() {
  // Initialize LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // Turn LED on for initialization
  digitalWrite(LED_BUILTIN, !ledState);

  // Configure serial transport
  Serial.begin(115200);
  delay(1000);

  // Turn LED off after serial initialization
  digitalWrite(LED_BUILTIN, ledState);
}

void loop() {
  // Blink
  if (millis() - lastBlink > BLINK_INTERVAL) {
    lastBlink = millis();
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }

  // Respond to serial commands
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "led_on") {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (command == "led_off") {
      digitalWrite(LED_BUILTIN, LOW);
    } else if (command == "ping") {
      Serial.println("pong");
    } else if (command == "time") {
      Serial.println(millis());
    }
  }
}
