#define LED_PIN 8
#define BUTTON_PIN 7

byte lastButtonState = LOW;
byte ledState = LOW;

unsigned long debounceDuration = 50; //millies
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (LED_PIN, OUTPUT);
  pinMode (BUTTON_PIN, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
 if (millis () - lastTimeButtonStateChanged > debounceDuration) {
  byte buttonState = digitalRead (BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastTimeButtonStateChanged = millis ();
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN,ledState);
    }
    
  }
}
}













