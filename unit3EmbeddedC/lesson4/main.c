#include <stdio.h>
#include "PlatformTypes.h"
#include "gpio.h"

int main(void)
{
	volatile uint32 delay_count;
	gpio_init();
	while(1)
	{
		gpio_wrt(HIGH);
		for(delay_count = 0; delay_count<20000; delay_count++);
		gpio_wrt(LOW);
		for(delay_count = 0; delay_count<20000; delay_count++);
	}
	return 0;
}