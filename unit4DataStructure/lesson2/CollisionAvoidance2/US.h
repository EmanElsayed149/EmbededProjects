/*
 * US.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Dell
 */

#ifndef US_H_
#define US_H_

enum
{
	US_busy
}US_state_id;

//declare state functions US
STATE_define(US_busy);

//declare init function
void US_init();

//helper functions
int GetRandomDistance(int l , int r);

//global pointer to function (use it to switch between states)
void (*US_state)();           //US_state is variable pointer to function

#endif /* US_H_ */
