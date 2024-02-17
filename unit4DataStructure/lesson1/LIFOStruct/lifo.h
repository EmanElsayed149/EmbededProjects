#ifndef LIFO_H_
#define LIFO_H_
#include "LIFOconfig.h"
#ifdef ArrayBased
typedef struct
{
	uint8 buf[5];
}buffer;
#endif
typedef struct
{
	uint8* base;
	uint8* head;
    uint32 count;
    uint32 length;	
}lifo_buf_t;
typedef enum{
	lifo_no_error,
	lifo_full,
	lifo_not_full,
	lifo_empty,
	lifo_not_empty,
	lifo_null
}buffer_status;
buffer_status LIFOInit(lifo_buf_t * PtrLifoBuf ,buffer*	uartbuf);
buffer_status LIFOPush(lifo_buf_t * PtrLifoBuf, uint8 item);
buffer_status LIFOPop (lifo_buf_t * PtrLifoBuf, uint8* ptritem );
buffer_status LIFOPeek(lifo_buf_t * PtrLifoBuf, uint8* ptritem);
buffer_status IsLIFOFull(lifo_buf_t *PtrLifoBuf);
buffer_status IsLIFOEmpty(lifo_buf_t *PtrLifoBuf);
void LIFODisplay(lifo_buf_t *PtrLifoBuf );
void PrintBufferStatus(buffer_status BufStatus);
#endif
