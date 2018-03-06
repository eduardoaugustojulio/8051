#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

#include "portIO.h"
#include "sys.h"

void PORT_INIT(void)
{
    unsigned char SFRPAGE_save = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    
    P1MDOUT = 0xC0;
    P2MDOUT = 0x03;
    P4MDOUT = 0x20;
    XBR0 = 0x0F;

    XBR2 = 0x40;                     

    SFRPAGE = SFRPAGE_save;
}
