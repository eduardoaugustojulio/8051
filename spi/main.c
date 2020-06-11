#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>


#define SYSCLK 48000000
#define SPI_CLOCK 500000

#define Nop     \
    __asm       \
        nop     \
    __endasm    \

void INIT(void);

void OSCILLATOR_INIT(void);
 
void PORT_INIT(void);

void SPI0_ISR(void);
void SPI0_INIT(void);

void SPI0_WRITE_BYTE(unsigned char byte);
unsigned char SPI0_READ_BYTE(void);

void SPI0_WRITE_BUFFER(unsigned char *buffer, int size);
void SPI0_READ_BUFFER(unsigned char  *buffer, int size);

int SPI0_CHECK_COLLISION(void);
int SPI0_ERROR(void);

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

//
// OSC
//

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

//
// PORT 
// 

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

//
// SPI
// 

int collision_occurrence = 0;

void SPI0_ISR(void)
{
    if(ESPI0 && SPIF)
    {    
        if(!SPI0_CHECK_COLLISION())
        {
            Nop;
        }
        
        SPIF = 0;
    }
}

void SPI0_INIT(void)
{
    unsigned char SFRPAGE_save = SFRPAGE;
    SFRPAGE = ACTIVE_PAGE;
    
    // Enable the SPI as a Master
    SPI0CFG   = 0x40;

    // 4-wire Single Master, SPI enabled
    SPI0CN    = 0x0D;

    // SPI clock frequency equation from the datasheet
    SPI0CKR   = (SYSCLK / (2 * SPI_CLOCK)) - 1;

    // Enable SPI interrupts
    ESPI0 = 1; 

    SFRPAGE = SFRPAGE_save;
}

void SPI0_WRITE_BYTE(unsigned char byte)
{
    unsigned char SFRPAGE_save = SFRPAGE;
    SFRPAGE = ACTIVE_PAGE;
       
    while (!NSSMD0);                   
    NSSMD0 = 0;    
    
    SPI0DAT = byte;
    SFRPAGE = SFRPAGE_save;
}

unsigned char SPI0_READ_BYTE(void)
{
    unsigned char ret_value;
    unsigned char SFRPAGE_save = SFRPAGE;
    SFRPAGE = ACTIVE_PAGE;
       
    while (!NSSMD0);                   
    NSSMD0 = 0;

    ret_value = SPI0DAT;
       
    SFRPAGE = SFRPAGE_save;
    return ret_value;
}
    
void SPI0_WRITE_BUFFER(unsigned char *buffer, int size)
{
    if(size > 0){
        int i;
        for(i = 0; i <= size; i++){
           unsigned char byte = buffer[i];
           SPI0_WRITE_BYTE(byte);
        }
    }
}

void SPI0_READ_BUFFER(unsigned char  *buffer, int size)
{
    if(size > 0){
        int i;
        for(i = 0; i <= size; i++){
            unsigned char byte = SPI0_READ_BYTE();
            buffer[i] = byte;
        }
    }
}

int SPI0_CHECK_COLLISION(void)
{   
    int ret_value = 0;

    if(WCOL){
        collision_occurrence++;  
        ret_value = WCOL;
        WCOL = 0;
    }
        
    return ret_value;
}

int SPI0_ERROR(void)
{
    return collision_occurrence;
}

//
// UTILS
//

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
