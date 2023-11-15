/*
Learn In Depth
by : Eman Elsayed 
C code for  UART API
*/ 

#include "PlatformTypes.h"
#include "uart.h"

void UartSendString(uint8* PToStr)
{
	while(*PToStr != '\0')
	{
		UART0DR = (uint32)*PToStr; /*transmit char*/
		PToStr++;                    /*next char*/
	}
}