/*
 * FreeRTOS Kernel V10.0.0
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software. If you wish to use our Amazon
 * FreeRTOS name, please do so in a fair use way that does not cause confusion.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/*
 * Creates the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main. c also creates four other tasks:
 * 
 * 1) vErrorChecks()
 * This only executes every few seconds but has the highest priority so is 
 * guaranteed to get processor time.  Its main function is to check that all 
 * the standard demo application tasks are still operational and have not
 * experienced any errors.  vErrorChecks() will toggle the on board LED
 * every mainNO_ERROR_FLASH_PERIOD milliseconds if none of the demo application
 * tasks have reported an error.  Should any task report an error at any time
 * the rate at which the on board LED is toggled is increased to 
 * mainERROR_FLASH_PERIOD - providing visual feedback that something has gone
 * wrong.
 *
 * 2) vRegisterCheck()
 * This is a very simple task that checks that all the registers are always
 * in their expected state.  The task only makes use of the A register, so
 * all the other registers should always contain their initial values.
 * An incorrect value indicates an error in the context switch mechanism.
 * The task operates at the idle priority so will be preempted regularly.
 * Any error will cause the toggle rate of the on board LED to increase to
 * mainERROR_FLASH_PERIOD milliseconds.
 *
 * 3 and 4) vFLOPCheck1() and vFLOPCheck2()
 * These are very basic versions of the standard FLOP tasks.  They are good
 * at detecting errors in the context switch mechanism, and also check that
 * the floating point libraries are correctly built to be re-enterant.  The
 * stack restrictions of the 8051 prevent the use of the standard FLOP demo
 * tasks.
 */

/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

void main( void )
{
    while(1){
    }
}


