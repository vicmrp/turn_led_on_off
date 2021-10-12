#include "LedLight.cpp"
#include "Button.cpp"
// #include <iostream>
// Description

// The goal of our project:
// To make a program that turns on led light one by one. Using the same sequence flow as when using a keystroke on a keyboad.
// You shall be able to delete (turn off) and turn on by using two buttons.

// When have made that then we will make a binary counter. We should be able to count to 255 in binary


// Defing the LED-pins
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define BUTTON1_PIN 1
#define BUTTON2_PIN 11


// inistialize lights
LedLight led1(LED1);
LedLight led2(LED2);
LedLight led3(LED3);
LedLight led4(LED4);
Button button1(BUTTON1_PIN);

LedLight lights[4] = {led1, led2, led3, led4};

void setup() { }

void loop() {
    // led1.turnOnLight();
    // led2.turnOnLight();
    // led3.turnOnLight();
    // led4.turnOnLight();
    // led5.turnOnLight();
    // led6.turnOnLight();
    // led7.turnOnLight();
    // led8.turnOnLight();
    // delay(5000);
    // led1.turnOffLight();
    // led2.turnOffLight();
    // led3.turnOffLight();
    // led4.turnOffLight();
    // led5.turnOffLight();
    // led6.turnOffLight();
    // led7.turnOffLight();
    // led8.turnOffLight();
    // delay(5000);
    if (button1.isPressed()) { // a...aaaaaaa
        if (button1.hasNotBeenReleasedForLessThanOneSecond()) {

        // When you have pressed the button turn on one light (a). Then if the button has been pressed solid for ine second. spam aaaaaa

        int lengthOfArray = (*(&lights + 1) - lights); // Length af this array
        for (int i = 0; i < lengthOfArray; i++) {
            lights[i].turnOnLight();
            delay(100);
        }

        // led1.turnOnLight();
        // led2.turnOffLight();
        // led3.turnOnLight();
        // led4.turnOffLight();
    }
    else {
        lights[0].turnOffLight();
        lights[1].turnOffLight();
        lights[2].turnOffLight();
        lights[3].turnOffLight();
        
        // led1.turnOffLight();
        // led2.turnOnLight();
        // led3.turnOffLight();
        // led4.turnOnLight();
    }
}





