#include <stdio.h>
#include "PlatformTypes.h"
#include "lifo.h"

int main()
{

	buffer reservedbuffer ;
	lifo_buf_t LifoUART;
	uint8 item;
	uint32 status;
	//first initiate LifoUART
	status = LIFOInit(&LifoUART , &reservedbuffer);
	PrintBufferStatus(status);
	status = LIFOPush(&LifoUART, 'H');
	status = LIFOPush(&LifoUART, 'E');
	status = LIFOPush(&LifoUART, 'L');
	status = LIFOPush(&LifoUART, 'L');
	status = LIFOPush(&LifoUART, 'O');
	PrintBufferStatus(status);
	status = LIFOPush(&LifoUART, 'R');
	PrintBufferStatus(status);
	status = LIFOPop(&LifoUART,&item );
	status = LIFOPeek(&LifoUART , &item);
	PrintBufferStatus(status);
	printf("last item is : %c\n",item);
	LIFODisplay(&LifoUART);
	return 0;




	/*
	 * expected output
	 * ===========Process is successfully Done! ==========
     * ===========Process is successfully Done! ==========
     * ===========Buffer is Full ===============
     * ===========Process is successfully Done! ==========
     * last item is : L
     * =====================LIFO Buffer Elements :=============================
     * L
     * L
     * E
     * H
     * =========================================================================
	 */
}
