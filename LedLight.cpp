#include <Arduino.h>

class LedLight{
  private: byte _pin;
  public: LedLight(byte pin) {
      this->_pin = pin;
      init();
    }
    void init() {
      pinMode(_pin, OUTPUT);
      turnOffLight();
    }
    void turnOnLight() {
      digitalWrite(_pin, HIGH);
    }
    void turnOffLight() {
      digitalWrite(_pin, LOW);
    }

    bool turnedOn() {
        byte newReading = digitalRead(_pin);

        if (newReading == HIGH) {
            return true;
        }

        return false;
    }
};