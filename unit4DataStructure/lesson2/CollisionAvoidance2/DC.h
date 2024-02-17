/*
 * DC.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Dell
 */

#ifndef DC_H_
#define DC_H_

#include <stdio.h>
#include "state.h"

enum
{
	DC_idle,
	DC_busy
}DC_state_id;

//declare state functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

//declare init function
void DC_init();

//global pointer to function (use it to switch between states)
void (*DC_state)();           //UDC_state is variable pointer to function

#endif /* DC_H_ */
