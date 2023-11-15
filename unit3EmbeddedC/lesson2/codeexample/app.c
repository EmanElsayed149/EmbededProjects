/*
Learn In Depth
by : Eman Elsayed 
C code for APP
*/ 

#include "PlatformTypes.h"
#include "uart.h"

//initialized global pointer to char saved in .data section
//and const string saved in .rodata
uint8 mystring[100] = "Learn In Depth : Eman Elsayed";

int main(void)
{
	UartSendString(mystring);
	return 0;
}

