/*
 * FIFO1.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Dell
 */


#include "stdio.h"
#include "PlatformTypes.h"
#include "FIFO.h"

//APIs Definition

/* Postcases
 * check about returned value to know if process is successfuly done or not
 */
#ifdef FIFO
BufferStatus ISFIFOBufFull(FIFO_Buf_t *PtrFIFOBuf)
{
	//check if FIFOBuffer is initialized
	if(!PtrFIFOBuf->head || !PtrFIFOBuf->tail)
		return FIFO_Null ;
	if(PtrFIFOBuf->count == BufferLength)
		return FIFO_Full ;
	//else return not full status
	return FIFO_Not_Full ;
}
BufferStatus IsFIFOBufEmpty(FIFO_Buf_t *PtrFIFOBuf)
{
	//check if FIFOBuffer is initialized
	if(!PtrFIFOBuf->head || ! PtrFIFOBuf->tail)
		return FIFO_Null ;

	if(PtrFIFOBuf->count == 0 )
		return FIFO_Empty ;
	//else return not empty status
	return FIFO_Not_Empty ;
}
BufferStatus FIFOEnqueue(FIFO_Buf_t *PtrFIFOBuf, ElementType item)
{
	//check if head not initialized correctly (NULL pointer)
	if(! PtrFIFOBuf->head)
		return FIFO_Null ;

	//check if buffer not Full
	if(ISFIFOBufFull(PtrFIFOBuf) == FIFO_Full)
		return FIFO_Full;

	//at the item at head pointer
	*(PtrFIFOBuf->head) = item ;
	PtrFIFOBuf->head++;
	PtrFIFOBuf->count++;

	//return no error status
	return FIFO_No_Error;

}
BufferStatus FIFODequeue(FIFO_Buf_t *PtrFIFOBuf, ElementType *PtrItem)
{
	//check if FIFOBuffer is initialized
	if(! PtrFIFOBuf->head || ! PtrFIFOBuf->tail)
		return FIFO_Null ;

	//check if FIFOBuffer not Empty
	if(IsFIFOBufEmpty(PtrFIFOBuf) == FIFO_Empty)
		return FIFO_Empty ;

	//retrieve first element into PtrItem
	*PtrItem = *(PtrFIFOBuf->tail) ;
	PtrFIFOBuf->tail++;
	PtrFIFOBuf->count--;

	//return no error status
	return FIFO_No_Error ;
}
BufferStatus FIFOInit(FIFO_Buf_t *PtrFIFOBuf , Buffer *PtrBuf)
{
	//check if there is available space for reserved buffer
	if(PtrBuf->buf == NULL)
	{
		return FIFO_Null;
	}
	//at the begining , head and tail points to the base of buffer
	PtrFIFOBuf->head = PtrBuf->buf ;
	PtrFIFOBuf->tail = PtrBuf->buf ;
	PtrFIFOBuf->count = 0;

	//return No error status
	return FIFO_No_Error;
}

void FIFOBufDisplay(FIFO_Buf_t *PtrFIFOBuf)
{
	ElementType *Iterator = PtrFIFOBuf->tail ;

	uint8 i ;
	printf("=====================FIFO Buffer Elements :=============================\n");
	for(i=0;i<PtrFIFOBuf->count  ;i++)
	{
		printf("Element%d : %c\n",i , *(Iterator));
		Iterator ++;
	}
	printf("=========================================================================\n");

}

void PrintBufferStatus(BufferStatus BufStatus)
{
	switch(BufStatus)
	{
	case FIFO_Empty:
		printf("===========Buffer is Empty ============\n");
		break ;
	case FIFO_Full:
		printf("===========Buffer is Full ===============\n");
		break ;
	case FIFO_No_Error:
		printf("===========Process is successfully Done! ==========\n");
		break;
	case FIFO_Null:
		printf("===========Failed ! ( Null Pointer is accessed )===============\n");
		break;
	default:
		printf("================ Undefined case! ============== \n");

	}
}

#else
//APIs for circular FIFO staructure
BufferStatus FIFOEnqueue(FIFO_Buf_t *PtrFIFOBuf, ElementType item)
{
	//check if head not initialized correctly (NULL pointer)
		if(! PtrFIFOBuf->head || !PtrFIFOBuf->tail || !PtrFIFOBuf->base)
			return FIFO_Null ;

		//check if the address of new item is the same of tail and count not equal 0 ....increment tail
		if((PtrFIFOBuf->head == PtrFIFOBuf-> tail)  && PtrFIFOBuf->count )
		{
			//increment tail
			PtrFIFOBuf->tail++;
			if(PtrFIFOBuf->tail == PtrFIFOBuf->base + BufferLength)
			{
				PtrFIFOBuf->tail = PtrFIFOBuf->base ;
			}

		}

		//add the item at head pointer
		*(PtrFIFOBuf->head) = item ;
		PtrFIFOBuf->count++;

		//increment head ....check if buffer is full , overwites oldest elements
		PtrFIFOBuf->head++;
		if(PtrFIFOBuf->head == (PtrFIFOBuf->base + BufferLength))
		{
			PtrFIFOBuf->head = PtrFIFOBuf->base ;
		}

		//return no error status
		return FIFO_No_Error;
}
BufferStatus FIFODequeue(FIFO_Buf_t *PtrFIFOBuf, ElementType *PtrItem)
{
	//check if head not initialized correctly (NULL pointer)
	if(! PtrFIFOBuf->head || !PtrFIFOBuf->tail || !PtrFIFOBuf->base)
		return FIFO_Null ;

	//check if FIFOBuffer not Empty
	if(IsFIFOBufEmpty(PtrFIFOBuf) == FIFO_Empty)
		return FIFO_Empty ;

	//retrieve oldest element into PtrItem
	*PtrItem = *(PtrFIFOBuf->tail) ;
	PtrFIFOBuf->count--;

	//increment tail
	PtrFIFOBuf->tail++;
	if(PtrFIFOBuf->tail == PtrFIFOBuf->base + BufferLength)
	{
		PtrFIFOBuf->tail = PtrFIFOBuf->base ;
	}

	//return no error status
	return FIFO_No_Error ;
}
BufferStatus FIFOInit(FIFO_Buf_t *PtrFIFOBuf , Buffer *PtrBuf)
{
	//check if there is available space for reserved buffer
		if(PtrBuf->buf == NULL)
		{
			return FIFO_Null;
		}
		//at the begining , head and tail points to the base of buffer
		PtrFIFOBuf->head = PtrBuf->buf ;
		PtrFIFOBuf->tail = PtrBuf->buf ;
		PtrFIFOBuf->base = PtrBuf->buf ;
		PtrFIFOBuf->count = 0;

		//return No error status
		return FIFO_No_Error;
}
BufferStatus ISFIFOBufFull(FIFO_Buf_t *PtrFIFOBuf)
{
	//check if head not initialized correctly (NULL pointer)
	if(! PtrFIFOBuf->head || !PtrFIFOBuf->tail || !PtrFIFOBuf->base)
		return FIFO_Null ;
	if(PtrFIFOBuf->count < BufferLength)
		return FIFO_No_Error;
	return FIFO_Full;

}
BufferStatus IsFIFOBufEmpty(FIFO_Buf_t *PtrFIFOBuf)
{
	//check if head not initialized correctly (NULL pointer)
	if(! PtrFIFOBuf->head || !PtrFIFOBuf->tail || !PtrFIFOBuf->base)
		return FIFO_Null ;
	if(PtrFIFOBuf->count == 0)
		return FIFO_Empty;
	return FIFO_No_Error;
}
void FIFOBufDisplay(FIFO_Buf_t *PtrFIFOBuf)
{
	ElementType *Ptriterator = PtrFIFOBuf->tail ;
	printf("=====================FIFO Buffer Elements :=============================\n");
	while(Ptriterator != PtrFIFOBuf->head)
	{
		printf("Element : %c \n",*Ptriterator);
		//increment iterator
		Ptriterator++;
		if(Ptriterator == PtrFIFOBuf->base + BufferLength)
		{
			Ptriterator = PtrFIFOBuf->base ;
		}
	}
	printf("=========================================================================\n");
}
void PrintBufferStatus(BufferStatus BufStatus)
{
	switch(BufStatus)
	{
	case FIFO_Empty:
		printf("===========Buffer is Empty ============\n");
		break ;
	case FIFO_Full:
		printf("===========Buffer is Full ===============\n");
		break ;
	case FIFO_No_Error:
		printf("===========Process is successfully Done! ==========\n");
		break;
	case FIFO_Null:
		printf("===========Failed ! ( Null Pointer is accessed )===============\n");
		break;
	default:
		printf("================ Undefined case! ============== \n");

	}
}
#endif
