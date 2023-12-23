#include "stdio.h"
#include "PlatformTypes.h"
#include "gpio.h"

void gpio_init()
{
	volatile uint32 delay_count;
	SYSCTL_RCGC2_R = 0x00000020;
	for(delay_count = 0;delay_count <20000; delay_count++);
	GPIO_PORTF_DIT_R |= 1<<3;
    GPIO_PORTF_DEN_R |= 1<<3;
}
void gpio_wrt(uint32 value)
{
	if(value==HIGH)
		
    	GPIO_PORTF_DATA_R |= 1<<3;
    else
		GPIO_PORTF_DATA_R &= ~(1<<3);
}