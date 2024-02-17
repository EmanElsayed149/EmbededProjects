/*
 * US.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "US.h"


//module variable
unsigned int US_distance = 0 ;
extern void (*US_state)();



//init function
void US_init()
{
	//init pins for ultrasonic sensor
	//call function in US driver
	printf("US init\n\n\n");
}
//implementation state functions ST_US_busy() (read data and set distance )
STATE_define(US_busy)
{
	//state name
	US_state_id = US_busy;

	//get US data
	US_distance = GetRandomDistance(45,55);
	printf("US_state_busy : distance = %d\n",US_distance);

	//send signal
	US_distance_set(US_distance);

	//go to next state
	US_state = STATE(US_busy);

}



int GetRandomDistance(int l , int r)
{
		int random ;
		random = (rand() % (r-l+1)) + l ;
		return random;
}
