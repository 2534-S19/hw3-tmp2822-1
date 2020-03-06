#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"


#include <stdio.h>

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.

    unsigned char buttonhistory = BoosterUnpressed;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        if(count0 > MaxCount) count0 = 0; //I don't want the count to go over 7
        if(count1 > MaxCount) count1 = 0;

        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired()){
            count0++;
        }
        //printf("Count0 = %d \n", count0);
        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired()){

            unsigned char x = checkStatus_BoosterpackS1(); //store the button status

            buttonhistory = buttonhistory<<1; //move over one
            buttonhistory= buttonhistory | x; //put new bit

        }


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        if(fsmBoosterpackButtonS1(buttonhistory)) count1++;




        // TODO: If a completed, debounced button press has occurred, increment count1.



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
  switch(count){
  case 1://Red on
      turnOn_LaunchpadLED2Red();
      turnOff_LaunchpadLED2Green();
      turnOff_LaunchpadLED2Blue();
  break;

  case 2://Green on
      turnOff_LaunchpadLED2Red();
      turnOn_LaunchpadLED2Green();
      turnOff_LaunchpadLED2Blue();
  break;

  case 3://Red&Green on
      turnOn_LaunchpadLED2Red();
      turnOn_LaunchpadLED2Green();
      turnOff_LaunchpadLED2Blue();
  break;

  case 4://Blue on
      turnOff_LaunchpadLED2Red();
      turnOff_LaunchpadLED2Green();
      turnOn_LaunchpadLED2Blue();

  break;

  case 5://Red&Blue
      turnOn_LaunchpadLED2Red();
      turnOff_LaunchpadLED2Green();
      turnOn_LaunchpadLED2Blue();
  break;

  case 6://Blue&Green
      turnOff_LaunchpadLED2Red();
      turnOn_LaunchpadLED2Green();
      turnOn_LaunchpadLED2Blue();
  break;

  case 7://white
      turnOn_LaunchpadLED2Red();
      turnOn_LaunchpadLED2Green();
      turnOn_LaunchpadLED2Blue();
  break;

  default:
      turnOff_LaunchpadLED2Red();
      turnOff_LaunchpadLED2Green();
      turnOff_LaunchpadLED2Blue();
  break;
  }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch(count){
    case 1://Red on
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    break;

    case 2://Green on
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    break;

    case 3://Red&Green on
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    break;

    case 4://Blue on
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();

    break;

    case 5://Red&Blue
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    break;

    case 6://Blue&Green
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    break;

    case 7://white
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    break;

    default:
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    break;
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    static bool buttonAction = false;

    if(buttonhistory == BoosterPressed){ //all 8 bits are zeros
       buttonAction = true;
    }
    if(buttonhistory == BoosterUnpressed && buttonAction == true){ //this means the button was pressed and has now been succesfully released
        buttonAction = false;//reset for later
        return true;
    }
    return false;
}
