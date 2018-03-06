#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

#include "sys.h"

void OSCILLATOR_INIT (void)
{
   unsigned char SFRPAGE_save = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;

   OSCICN = 0x84;                      // Configure internal oscillator for
                                       // 24 MHz / 8

   SFRPAGE = ACTIVE_PAGE;
   
   RSTSRC = 0x04;                      // Enable missing clock detector
   
   SFRPAGE = SFRPAGE_save;
}

inline void set_nth_bit(unsigned char *c, unsigned char n ,unsigned char b)
{ 
  if(b)
    *c |= 1 << n;
  else
    *c &= ~(1 << n);
}

inline void ms_delay(int delay)
{
	int i;
    for (i = 0; i < delay; i++)
    {
        Nop;
    }
}
