#include "LedLight.cpp"
#include "Button.cpp"

// Defing the LED-pins
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

// Defing the BUTTON-pins
#define BUTTON1_PIN 1
#define BUTTON2_PIN 11

// Description
// The goal of our project:
// To make a program that turns on led light one by one. Using the same sequence flow as when using a keystroke on a keyboad.
// You shall be able to delete (turn off) and turn on by using two buttons.
// When have made that then we will make a binary counter. We should be able to count to 255 in binary




// inistialize lights
LedLight led1(LED1);
LedLight led2(LED2);
LedLight led3(LED3);
LedLight led4(LED4);
Button button1(BUTTON1_PIN);

LedLight lights[4] = {led1, led2, led3, led4};
int turnedOnLeds = 0;
void setup() {
    Serial.begin(9600);
    // Serial.println("Hej fra setup");
 }

void loop() {
    int lengthOfArray = (*(&lights + 1) - lights); // Length af this array
    
    if (button1.isPressed()) { // a...aaaaaaa

        // When you have pressed the button turn on one light (a). Then if the button has been pressed solid for ine second. spam aaaaaa
        lights[turnedOnLeds].turnOnLight();
        turnedOnLeds++;
        Serial.println("Hej fra setup");
        // for (int i = 0; i < lengthOfArray; i++) {
        //     lights[i].turnOnLight();
        //     delay(100);
        // }

    }
    else {

        // Check if all led's is on
        
        for (int i = 0; i < lengthOfArray; i++) {
            if(lights[i].turnedOn()) {
                turnedOnLeds++;
            }
        }

        if (turnedOnLeds == 4) {
            for (int i = 0; i < lengthOfArray; i++) {
                lights[i].turnOffLight();
                // delay(100);
                
            }
            turnedOnLeds = 0;
        }
    }
}





