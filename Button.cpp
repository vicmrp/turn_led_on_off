#include <Arduino.h>

// When buttob


class Button {
  private:
    byte _pin;
    byte state;
    byte lastReading;
    unsigned long lastButtonPressedTime = 0; // lastDebounceTime
    unsigned long debounceDelay = 50;
  public:
    Button(byte pin) {
      this->_pin = pin;
      lastReading = LOW;
      init();
    }
    void init() {
      pinMode(_pin, INPUT);
      update();
    }
    void update() {
      // You can handle the debounce of the button directly
      // in the class, so you don't have to think about it
      // elsewhere in your code
      byte newReading = digitalRead(_pin); //  Is it HIGH or LOW?
      
      if (newReading != lastReading) {
        lastButtonPressedTime = millis();
      }
      if (millis() - lastButtonPressedTime > debounceDelay) {
        // Update the 'state' attribute only if debounce is checked
        state = newReading;
      }
      lastReading = newReading;
    }
    byte getState() {
      update();
      return state;
    }
    bool isPressed() {
      return (getState() == HIGH);
    }
    bool isReleased() {
        return (getState() == LOW);
    }
};
