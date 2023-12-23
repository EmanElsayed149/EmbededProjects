#ifndef _GPIO_H_
#define _GPIO_H_

#define SYSCTL_RCGC2_R      (*((volatile uint32 *)0x400fe108)) 
#define GPIO_PORTF_DATA_R   (*((volatile uint32 *)0x400253fc))
#define GPIO_PORTF_DIT_R    (*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_DEN_R    (*((volatile uint32 *)0x4002551c))
#define HIGH                (uint32)1
#define LOW                 (uint32)0

void gpio_wrt(uint32 value);
void gpio_init();
#endif