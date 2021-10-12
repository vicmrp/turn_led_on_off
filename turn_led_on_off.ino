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
int lightsLength = (*(&lights + 1) - lights); // Length of array
int turnedOnLeds = 0;
long timeSinceExecution = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Hello world from setup()"); 
}

void loop() {

    // ---- serial loop status ----- //
    Serial.println(
                "millis(): " + String(millis())
                + ", lightsLength: " + String(lightsLength)
                + ", turnedOnLeds: " + String(turnedOnLeds));
    // ---- serial loop status ----- //


    // ---- Starter alle lamper en efter en med 100 milisekunders mellemrum ---- //
    for (int i = 0; i < lightsLength; i++) {
        Serial.println(
            "lights[" + String(i)
             + "], turnedOn: " + String(lights[i].turnedOn()));
             
        lights[i].turnOnLight();
    }
    // ---- Starter alle lamper en efter en med 100 milisekunders mellemrum ---- //



    // ---- Slukker alle lamper hvis alle lamper er tændt ---- //
    if (turnedOnLeds >= 4) {
        for (int i = 0; i < lightsLength; i++) {
            lights[i].turnOffLight();            
        }
        turnedOnLeds = 0;
    }
    // ---- Slukker alle lamper hvis alle lamper er tændt ---- //
    turnedOnLeds++;
}
