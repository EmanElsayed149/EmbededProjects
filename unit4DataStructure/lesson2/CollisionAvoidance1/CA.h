/*
 * CA.h
 *
 *  Created on: Feb 13, 2024
 *      Author: Dell
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
//state id
enum
{
	CA_waiting,
	CA_driving
}state_id;

//declare state function
STATE_define(CA_waiting);
STATE_define(CA_driving);

//state pointer to function (use it to switch between states)(use extern to use it in different files)
extern void (*CA_state)();           //CA_state is variable to function


//helper functions
int GetRandomDistance(int l , int r);

#endif /* CA_H_ */
