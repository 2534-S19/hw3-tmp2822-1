/*
 * myTimer.c
 *
 *  Created on:
 *      Author:
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"
#include "stdio.h"
// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{

    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(timer,preScaler,TIMER32_32BIT,TIMER32_PERIODIC_MODE );

    // For the specified timer, pass the count value.
    Timer32_setCount(timer, count);

    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer(timer, REPEAT);
}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired()
{
    static unsigned int previousSnap0 = MAX_VALUE;
    unsigned int currentSnap;
    bool returnValue;
    currentSnap = Timer32_getValue(TIMER0);
    printf("%d\n",currentSnap);
    //printf("%d\n",previousSnap0);
    returnValue = (currentSnap > previousSnap0);
    previousSnap0 = currentSnap;
    return returnValue;
}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired()
{
    static unsigned int previousSnap1 = MAX_VALUE;
    unsigned int currentSnap;
    bool returnValue;
    currentSnap = Timer32_getValue(TIMER1);
    returnValue = (currentSnap > previousSnap1);
    previousSnap1 = currentSnap;
    return returnValue;
}
