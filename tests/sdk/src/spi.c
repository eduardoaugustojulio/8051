#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

#include "spi.h"
#include "sys.h"

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

