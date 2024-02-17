/*
 * state.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Dell
 */

#ifndef STATE_H_
#define STATE_H_

//state function define
#define STATE_define(statefun)  void  ST_##statefun()
//state
#define STATE(statefun) ST_##statefun


//functions connections
void US_distance_set(unsigned int dis);
void DC_motor(unsigned int speed);


#endif /* STATE_H_ */
