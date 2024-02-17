/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Dell
 */
#include <stdio.h>
#include "CA.h"

void (*CA_state)() = STATE(CA_waiting);
int main()
{
	while(1)
	{
		CA_state();
		for(int i=0;i<700000;i++);
	}
	return 0;
}

