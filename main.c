/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/******************************************************************************
 * MSP432 Empty Project
 *
 * Description: An empty project that uses DriverLib
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST               |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 * Author: 
 *******************************************************************************/
/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/* Our Includes */
//#include <HAL/>
#include <HAL/I2C.h>
//#include <HAL/Button.h>
#include <HAL/Timer.h>
#include <HAL/Graphics.h>
#include <HAL/Button_withInterrupts.h>
#include <HAL/LED.h>
//----------------------------------------------------------------
//A special pre-processor directive goes here. You need to find out what that directive is.
//----------------------------------------------------------------



void sleep() {
    // The Launchpad RED LED is used to signify the processor is in low-power mode.
    // From the human perspective, it should seem the processor is always asleep except for fractions of second here and there.

    TurnOn_LL1();
    // Enters the Low Power Mode 0 - the processor is asleep and only responds to interrupts
    PCM_gotoLPM0();
    TurnOff_LL1();

}




int main(void)
{
    /* Stop Watchdog  */
    MAP_WDT_A_holdTimer();

    /* Init the custom system timing... may cause problems */
    InitSystemTiming();

    initButtons();//initializes the buttons
    initLEDs();   //initializes the LEDs

    while(1)
    {
       sleep(); //force the processor into sleep mode (only waking for interrupts)

       buttons_t buttons = updateButtons();//update the buttons pressings

       //===============================================================
       //TODO: Your code goes here
       //===============================================================
    }




}

