/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO(){

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);//LED1 Red
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);//LED2 Red
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);//LED2 Green
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);//LED2 Blue
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);//BLED Red
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4);//BLED Green
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);//BLED Blue
    //L1
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1,GPIO_PIN1);
    //L2
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1,GPIO_PIN4);
    //B1
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5,GPIO_PIN1);
    //B2
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3,GPIO_PIN5);
    // Turn off all LEDs at the start.
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);//LED1 Red Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);//LED2 Red Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);//LED2 Green Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);//LED2 Blue Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);//BLED Red Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);//BLED Green Low
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);//BLED Blue Low
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    unsigned char status =  GPIO_getInputPinValue(GPIO_PORT_P1,GPIO_PIN1);
    return status;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    unsigned char status =  GPIO_getInputPinValue(GPIO_PORT_P1,GPIO_PIN4);
    return status;
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    unsigned char status =  GPIO_getInputPinValue(GPIO_PORT_P5,GPIO_PIN1);
    return status;
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    unsigned char status =  GPIO_getInputPinValue(GPIO_PORT_P3,GPIO_PIN5);
    return status;
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);//LED1 Red High
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);//LED1 Red Low
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);//LED2 Red High
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);//LED2 Red Low
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);//LED2 Green High
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);//LED2 Green Low
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);//LED2 Blue High
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);//LED2 Blue Low
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);//BLED Red High
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);//BLED Red Low
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);//BLED Green High
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);//BLED Green Low
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);//BLED Blue High
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);//BLED Blue Low
}
