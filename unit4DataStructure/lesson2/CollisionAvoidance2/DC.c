/*
 * DC.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Dell
 */

#include <stdio.h>
#include "state.h"
#include "DC.h"

//module variables
unsigned int DC_speed ;
extern void (*DC_state)();

//init function
void DC_init()
{
	//init pwm driver
	//init dc  driver
	printf("DC_init\n\n");
}
//signal in to dc driver
void DC_motor(unsigned int speed)
{
	DC_speed = speed ;

	DC_state = STATE(DC_busy);
	printf("CA------speed = %d ------->DC\n\n",DC_speed);
}
//impementation state functions DC
STATE_define(DC_idle)
{
	//set state id
	DC_state_id = DC_idle;
	DC_state = STATE(DC_idle);

	//state action
	//Call DC driver

	printf("DC_idle_state: speed =%d \n\n\n",DC_speed);

}
STATE_define(DC_busy)
{
	//state id
	DC_state_id = DC_busy;

	//state action
	//set pwm as speed = DC_speed

	//state event
	DC_state = STATE(DC_idle);
	printf("DC_busy_state: speed = %d \n",DC_speed);
	DC_state();


}


