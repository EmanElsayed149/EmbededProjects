/*
 * main.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Dell
 */

#include "stdio.h"
#include "PlatformTypes.h"
#include "FIFO.h"

int main()
{
	Buffer StaticBuf ;
	FIFO_Buf_t UartBuf;
	ElementType item ;
	BufferStatus status;

	//initiate UartBuf
	status = FIFOInit(&UartBuf , & StaticBuf);
	PrintBufferStatus(status);
	item = 'H';
	status = FIFOEnqueue(&UartBuf , item);
	item = 'e';
	status = FIFOEnqueue(&UartBuf , item);
	item = 'l';
	status = FIFOEnqueue(&UartBuf , item);
	item = 'l';
	status = FIFOEnqueue(&UartBuf , item);
	item = 'o';
	status = FIFOEnqueue(&UartBuf , item);
	PrintBufferStatus(status);
	item = 'Z';
	status = FIFOEnqueue(&UartBuf , item);
	PrintBufferStatus(status);
	status = FIFODequeue(&UartBuf , &item);
	printf("Item = %c \n",item);
	status = FIFODequeue(&UartBuf , &item);
	printf("Item = %c \n",item);
	PrintBufferStatus(status);
	FIFOBufDisplay(&UartBuf);

	/*
	 * expected output(FIFO definition)
	 * process is successully Done
	 * process is successully Done
	 * Buffer if full
	 * item = H
	 * item = e
	 * process is successully Done
	 * ===========Buffer elements ===============
	 * Element 0 :L
	 * Element 1 :L
	 * Element 2 :0
	 * =======================================
	 */
	/*
	 * expected output(FIFO circular)
	 * process is successully Done
	 * process is successully Done
     * process is successully Done
	 * item = e
	 * item = l
	 * process is successully Done
	 * ===========Buffer elements ===============
	 * Element  :l
	 * Element  :o
	 * Element  :z
	* =======================================
	*/


}
