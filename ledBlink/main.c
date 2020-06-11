#include <stdio.h>
#include <C8051F580.h>

SBIT (INPUT, SFR_P3, 5);                 // INPUT == 0 means switch depressed
SBIT (BUZZER, SFR_P1, 6);
SBIT (LED_BLUE, SFR_P1, 7);
SBIT (LED_RED, SFR_P2, 0);
SBIT (LED_GREEN, SFR_P2, 1);
//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------


void OSCILLATOR_Init (void);
void PORT_Init (void);
void ms_delay(unsigned int itime);
void led_blink(void);

//-----------------------------------------------------------------------------
// main() Routine
//-----------------------------------------------------------------------------

void main (void)
{
   	SFRPAGE = ACTIVE_PAGE;              // Set SFR Page for PCA0MD

   	PCA0MD &= ~0x40;                    // Disable the watchdog timer

   	PORT_Init ();                       // Initialize Port I/O
   	OSCILLATOR_Init ();                 // Initialize Oscillator
    
    led_blink();	
}         

//-----------------------------------------------------------------------------
// Initialization Subroutines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// OSCILLATOR_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function initializes the system clock to use the internal oscillator
// at its maximum frequency / 8.
//
//-----------------------------------------------------------------------------

void OSCILLATOR_Init (void)
{
   unsigned char SFRPAGE_save = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;

   OSCICN = 0x84;                      // Configure internal oscillator for
                                       // 24 MHz / 8

   SFRPAGE = ACTIVE_PAGE;

   RSTSRC = 0x04;                      // Enable missing clock detector

   SFRPAGE = SFRPAGE_save;
}

//-----------------------------------------------------------------------------
// PORT_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function configures the crossbar and ports pins.
//
// To configure a pin as a digital input, the pin is configured as digital
// and open-drain and the port latch should be set to a '1'.  The weak-pullups
// are used to pull the pins high.  Pressing the switch pulls the pins low.
//
// To configure a pin as a digital output, the pin is configured as digital
// and push-pull.
//
// An output pin can also be configured to be an open-drain output if system
// requires it.  For example, if the pin is an output on a multi-device bus,
// it will probably be configured as an open-drain output instead of a
// push-pull output.  For the purposes of this example, the pin is configured
// as push-pull output because the pin in only connected to an LED.
//
// P1.3   digital   push-pull     LED
// P1.4   digital   open-drain    SW1
//
//-----------------------------------------------------------------------------
void PORT_Init (void)
{
   unsigned char SFRPAGE_save = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;

   P1MDOUT   = 0xC0;
   P2MDOUT   = 0x03;
   P4MDOUT   = 0x20;
   XBR0      = 0x0F;

   XBR2    	 = 0x40;                     // Enable crossbar and enable
                                       // weak pull-ups

   SFRPAGE = SFRPAGE_save;
}

void ms_delay(unsigned int itime)
{
	unsigned int i,j;
	for (i = 0; i< itime; i++)
		for (j = 0; j < 100; j++);
}

void led_blink(void)
{
	LED_RED = 0;
	LED_BLUE = 0;
	LED_GREEN = 0;

	for(;;)
	{
		if (INPUT == 0)                  // If switch depressed
      	{
        	LED_GREEN = 1;
			LED_BLUE = 1;
        	LED_RED = 1;	
      	}
      	else
      	{
	    	LED_RED = 0;
   			LED_BLUE = 0;
   			LED_GREEN = 0;
      	}
	}
}
