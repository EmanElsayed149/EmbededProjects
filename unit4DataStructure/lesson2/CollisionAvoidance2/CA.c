/*
 * CA.c

 *
 *  Created on: Feb 17, 2024
 *      Author: Eman Elsayed
 */
#include <stdio.h>
#include "state.h"
#include "US.h"
#include "DC.h"
#include "CA.h"

unsigned int speed , distance ;
unsigned int threshold = 50;
extern void (*CA_state)();

void US_distance_set(unsigned int dis)
{
	distance = dis;
	//check for transiction
	(distance <= threshold )? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	printf("US----------distance = %d-------> CA\n",distance);
}


//implement states
STATE_define(CA_waiting)
{

	//state name
	CA_state_id = CA_waiting ;

	//state action (set speed of dc motor)
	speed =0 ;
	//print state info
	printf("CA_waiting state : distance = %d , speed = %d\n",distance , speed);     fflush(stdout);

	DC_motor(speed);



}
STATE_define(CA_driving)
{
	//state name
	CA_state_id = CA_driving ;

	//state action (set speed of dc motor)
	speed = 30 ;
	//print state info
	printf("CA_driving state : distance = %d , speed = %d\n",distance , speed);    fflush(stdout);
	DC_motor(speed);

}




