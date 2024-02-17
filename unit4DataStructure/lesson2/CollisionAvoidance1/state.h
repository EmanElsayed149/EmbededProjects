/*
 * state.h
 *
 *  Created on: Feb 13, 2024
 *      Author: Dell
 */

#ifndef STATE_H_
#define STATE_H_

//state function define
#define STATE_define(statefun)  void  ST_##statefun()

//state
#define STATE(statefun) ST_##statefun


#endif /* STATE_H_ */
