#ifndef __SPI__H
#define __SPI__H

#include <stdio.h>
#include <stdlib.h>

#include <C8051F580.h>
#include <compiler.h>

    void SPI0_ISR(void);
    
    void SPI0_INIT(void);
       
    void SPI0_WRITE_BYTE(unsigned char byte);
    unsigned char SPI0_READ_BYTE(void);
    
    void SPI0_WRITE_BUFFER(unsigned char *buffer, int size);
    void SPI0_READ_BUFFER(unsigned char  *buffer, int size);

    int SPI0_CHECK_COLLISION(void);
    int SPI0_ERROR(void);

    
#define SPI_CLOCK 500000

#endif  // __SPI__H 
