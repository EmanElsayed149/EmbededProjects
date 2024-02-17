#include <stdio.h>
#include "PlatformTypes.h"
#include "lifo.h"
buffer_status LIFOInit(lifo_buf_t * PtrLifoBuf ,buffer*	uartbuf)
{
	//check if there is reserved space for buffer
	if(uartbuf->buf  == NULL)
	{
		return lifo_null;
	}
	PtrLifoBuf->base = uartbuf->buf;
	PtrLifoBuf->head = uartbuf->buf ;
	PtrLifoBuf->count= 0;
	PtrLifoBuf->length = MaxSize;
	//there is no error
	return lifo_no_error;

}
buffer_status IsLIFOEmpty(lifo_buf_t *PtrLifoBuf)
{
	if(PtrLifoBuf->base == NULL)
	{
		return lifo_null;
	}
	if(PtrLifoBuf->count == 0)
		return lifo_empty;
	return lifo_not_empty ;
}
buffer_status IsLIFOFull(lifo_buf_t *PtrLifoBuf)
{
	if(PtrLifoBuf->base == NULL)
	{
		return lifo_null;
	}
	if(PtrLifoBuf->count == PtrLifoBuf->length)
		return lifo_full;
	return lifo_not_full ;
}
buffer_status LIFOPush(lifo_buf_t * PtrLifoBuf, uint8 item)
{

	if(IsLIFOFull(PtrLifoBuf)==lifo_full)
	{
		return lifo_full;
	}
	if(PtrLifoBuf->base == NULL)
	{
		return lifo_null;
	}
	*(PtrLifoBuf->head) = item ;
	PtrLifoBuf->head++;
	PtrLifoBuf->count++;
	return lifo_no_error;
}
buffer_status LIFOPop (lifo_buf_t * PtrLifoBuf, uint8* ptritem )
{
	if(PtrLifoBuf->base == NULL)
		return lifo_null;
	if(IsLIFOEmpty(PtrLifoBuf)==lifo_empty)
		return lifo_empty;
	PtrLifoBuf->head--;
	*ptritem = *(PtrLifoBuf->head) ;
	PtrLifoBuf->count--;
	return lifo_no_error;
}
buffer_status LIFOPeek(lifo_buf_t * PtrLifoBuf, uint8* ptritem)
{
	if(PtrLifoBuf->base == NULL)
		return lifo_null;
	if(IsLIFOEmpty(PtrLifoBuf)==lifo_empty)
		return lifo_empty;
	*ptritem = *(PtrLifoBuf->head - 1) ;
	return lifo_no_error;
}
void LIFODisplay(lifo_buf_t *PtrLifoBuf )
{
	uint8 i;
	printf("=====================LIFO Buffer Elements :=============================\n");
	uint8* PIterator = PtrLifoBuf->head;
	if(IsLIFOEmpty(PtrLifoBuf)==lifo_empty)
		printf("Buffer is empty\n");
	for(i=0 ; i<PtrLifoBuf->count;i++)
	{
		printf("%c\n",*(--PIterator));
	}
	printf("=========================================================================\n");
}

void PrintBufferStatus(buffer_status BufStatus)
{
	switch(BufStatus)
	{
	case lifo_empty:
		printf("===========Buffer is Empty ============\n");
		break ;
	case lifo_full:
		printf("===========Buffer is Full ===============\n");
		break ;
	case lifo_no_error:
		printf("===========Process is successfully Done! ==========\n");
		break;
	case lifo_null:
		printf("===========Failed ! ( Null Pointer is accessed )===============\n");
		break;
	default:
		printf("================ Undefined case! ============== \n");

	}
}
