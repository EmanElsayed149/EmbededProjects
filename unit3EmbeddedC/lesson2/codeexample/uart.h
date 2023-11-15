/*
Learn In Depth
by : Eman Elsayed 
header file for UART
*/ 
#ifndef _UART_H_
#define _UART_H_

#define UART0DR  *((volatile uint32 * const)0x101f1000)
//uart api declaration
void UartSendString(uint8* PToStr);

#endif