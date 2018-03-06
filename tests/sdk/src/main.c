#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

#include "sys.h"
#include "portIO.h"
#include "spi.h"

void INIT(void);

void main (void)
{
    INIT();
    
    while(1)
    {
    
    }
}

void INIT(void)
{
    OSCILLATOR_INIT();
    PORT_INIT();
    SPI0_INIT();
}
