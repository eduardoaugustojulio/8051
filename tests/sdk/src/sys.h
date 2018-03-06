#ifndef __SYS__H
#define __SYS__H

#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

    void OSCILLATOR_INIT (void);
    
    inline void set_nth_bit(unsigned char *c, unsigned char n ,unsigned char b);
    inline void ms_delay(int delay);


#define SYSCLK 48000000

#define Nop     \
    __asm       \
        nop     \
    __endasm    \
 
#endif  // __SYS__H 

