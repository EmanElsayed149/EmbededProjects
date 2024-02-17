/*
 * CA.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"



//global variable but not accessed by anthor file
static int distance  = 0 ;
static int speed     = 0 ;
static int threshold = 50;

//implement states
STATE_define(CA_waiting)
{

	//state name
	state_id = CA_waiting ;

	//state action (set steed og dc motor)
	speed = 0 ;

	//-get random value for distance
	distance = GetRandomDistance(45 , 55);
	//state event //check for transiction
	(distance <= threshold )? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	//print state info
    printf("CA_waiting state : distance = %d , speed = %d\n",distance , speed);     fflush(stdout);

}
STATE_define(CA_driving)
{
	//state name
	state_id = CA_driving ;

	//state action (set steed og dc motor)
	speed = 30 ;


	//-get random value for distance
	distance = GetRandomDistance(45 , 55);
	//state event //check for transiction
	(distance <= threshold )? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	//print state info
	printf("CA_driving state : distance = %d , speed = %d\n",distance , speed);    fflush(stdout);

}

int GetRandomDistance(int l , int r)
{
		int random ;
		random = (rand() % (r-l+1)) + l ;
		return random;
}
