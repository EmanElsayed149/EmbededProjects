/*
 * main.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Eman Elsayed
 */

#include <stdio.h>
#include "state.h"
#include "US.h"
#include "DC.h"
#include "CA.h"


void setup()
{
	//init DC
	DC_init();
	//init US
	US_init();
	//init US state
	US_state = STATE(US_busy);
	//init CA state
	CA_state = STATE(CA_waiting);
}

int main(void)
{
	setup();
	while(1)
	{
		//US state
		US_state();
		//CA state
		CA_state();
		//DC state
		DC_state();

		//delay
		for(int i=0;i<700000; i++);

	}

}
