/*startup.c cortex-m3
Eman Elsayed 
*/
 

#include <stdio.h>
#include "PlatformTypes.h"


/****************************vectors handlers**************/
extern int main(void);

/*****these are the sympols for start and end of each   section ******/
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;
extern uint32 _stack_top;

void ResetHandler(void) 
{
	uint32 i;
	
	/*first copy data section from flash to sram*/
	uint32 DataSize = (uint8 *)(&_E_data) - (uint8 *)(&_S_data);
	uint8 *psrc = (uint8 *)(&_E_text);
	uint8 *pdst = (uint8 *)(&_S_data);
	
	for(i =0; i< DataSize ; i++)
	{
		*((uint8 *)pdst++) = *((uint8 *)psrc++);
	}
	
	/*initiate space of bss with zeros */
	uint32 BssSize = (uint8 *)(&_E_bss) - (uint8 *)(&_S_bss);
	
	pdst = (uint8 *)(&_S_bss);
	for(i =0;i< BssSize ;i++)
	{
		*((uint8 *)pdst++) = (uint8)0;
	}
	//jump to main 
	main();
}
void DefaultHandler(void)
{
	ResetHandler();
}
/* 
if you define this handler like this way 

void NMIHandler(void)
{
	ResetHandler();
}
* this will give you an error when you rewrite handler in app 
*redefined for NMIHandler
*so you should use weak - alias attributes with function 
*/

void NMIHandler(void)        __attribute__((weak,alias("DefaultHandler")));;
void HFaultHandler(void)     __attribute__((weak,alias("DefaultHandler")));;
void MMFaultHandler(void)    __attribute__((weak,alias("DefaultHandler")));;
void BusFaultHandler(void)   __attribute__((weak,alias("DefaultHandler")));;
void UsageFaultHandler(void) __attribute__((weak,alias("DefaultHandler")));;

//define this global data to be put in vector section not in data section
uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32) &_stack_top,                                   //put value of sp in first 4 byte in vector section
	(uint32) &ResetHandler,
	(uint32) &NMIHandler,
	(uint32) &HFaultHandler,
	(uint32) &MMFaultHandler,
	(uint32) &BusFaultHandler,
	(uint32) &UsageFaultHandler
	//and so on ... put addresses of vectors handler 
};

