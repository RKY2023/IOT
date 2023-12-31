// Include Libraries
#include "Arduino.h"
#include "Servo.h"


// Pin Definitions
#define SERVOMD_PIN_SIG	5



// Global variables and defines
const int servoMDRestPosition   = 20;  //Starting position
const int servoMDTargetPosition = 150; //Position when event is detected
// object initialization
Servo servoMD;


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    servoMD.attach(SERVOMD_PIN_SIG);
    servoMD.write(servoMDRestPosition);
    delay(100);
    servoMD.detach();
    // menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    // if(menuOption == '1') {
    // Standard Size - High Torque - Metal Gear Servo - MG995 - Test Code
    // The servo will rotate to target position and back to resting position with an interval of 500 milliseconds (0.5 seconds) 
    servoMD.attach(SERVOMD_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servoMD.write(servoMDTargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD.write(servoMDRestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    // }
    
    // if (millis() - time0 > timeout)
    // {
    //     menuOption = menu();
    // }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Standard Size - High Torque - Metal Gear Servo - MG995"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Standard Size - High Torque - Metal Gear Servo - MG995"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
  return 0;
}
