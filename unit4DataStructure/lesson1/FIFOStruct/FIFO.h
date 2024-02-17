/*
 * FIFO.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Dell
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "FIFOConfig.h"
#include "PlatformTypes.h"
//static allocated buffer
typedef struct
{
	ElementType buf[BufferLength];
}Buffer;
#ifdef FIFO
//Decleration of FIFO Structure (Queue)
typedef struct
{
	//pointer to place where new element will be added
	ElementType * head ;
	//pointer to place where the oldest element will be removed
	ElementType * tail ;
	//no of elements added in FIFO
	uint32 count;
}FIFO_Buf_t;
#else
//Decleration of FIFO circular Structure
typedef struct
{
	//pointer to base address of the buffer
	ElementType *base ;
	//pointer to place where new element will be added
	ElementType * head ;
	//pointer to place where the oldest element will be removed
	ElementType * tail ;
	//no of elements added in FIFO
	uint32 count;
}FIFO_Buf_t;
#endif
//Declaration of buffer status
typedef enum
{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Not_Full,
	FIFO_Empty,
	FIFO_Not_Empty,
	FIFO_Null
}BufferStatus;

//APIs prototype
BufferStatus FIFOEnqueue(FIFO_Buf_t *PtrFIFOBuf, ElementType item);
BufferStatus FIFODequeue(FIFO_Buf_t *PtrFIFOBuf, ElementType *PtrItem);
BufferStatus FIFOInit(FIFO_Buf_t *PtrFIFOBuf , Buffer *PtrBuf);
BufferStatus ISFIFOBufFull(FIFO_Buf_t *PtrFIFOBuf);
BufferStatus IsFIFOBufEmpty(FIFO_Buf_t *PtrFIFOBuf);
void FIFOBufDisplay(FIFO_Buf_t *PtrFIFOBuf);
void PrintBufferStatus(BufferStatus BufStatus);
#endif /* FIFO_H_ */
