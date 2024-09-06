#include <LiquidCrystal.h>

// Define the pin for the button
const int buttonPin = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables to store the button state and time
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastPressTime = 0;

void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);

  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);

}

void loop() {
  // Read the state of the button (HIGH or LOW)
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (HIGH) and was not pressed before
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Calculate the time since the last button press in seconds
    unsigned long currentTime = millis();
    double timeSinceLastPress = (double) (currentTime - lastPressTime) / 1000; // Convert to seconds
//    lcd.begin(16, 2); 
    
      // Print "Hello, World!" to the LCD
//    lcd.print("Hello, World!");
    // Print the time since the last press
    Serial.print("Time since last press: ");
    Serial.print(timeSinceLastPress);
    Serial.println(" seconds");

    lcd.clear();
    lcd.print((String) timeSinceLastPress + "s");

    // Record the time when the button was pressed
    lastPressTime = currentTime;
  }

  // Update the last button state
  lastButtonState = buttonState;

  // Add a small delay to avoid bouncing issues
  delay(50); // Short delay for debouncing
}
