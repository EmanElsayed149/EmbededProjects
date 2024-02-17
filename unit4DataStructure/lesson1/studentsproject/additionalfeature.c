/*
 * additionalfeature.c
 *
 *  Created on: Jan 23, 2024
 *      Author: Dell
 */

#include "PlatformTypes.h"
#include "stdio.h"
#include "list.h"
#include "additionalfeature.h"

ListState DetectLoop(students_list_t *PtrStudentList)
{
	//if there is one node or no node ...return no error  ....to prevent access null condition
	if((PtrStudentList->head == NULL) || (PtrStudentList->head->next == NULL))
		return List_No_Error;

	student_node_t *ptrslow = PtrStudentList->head ;
	student_node_t *ptrfast = PtrStudentList->head->next->next;
	while(ptrfast)
	{
		if(ptrslow == ptrfast)
			return List_Loop;
		//move pointers
		ptrslow = ptrslow->next ;
		ptrfast = ptrfast->next->next ;
	}
	return List_No_Error;


}
void CreateLoop(students_list_t *PtrStudentList)
{
	PtrStudentList->tail->next = PtrStudentList->head;
}
student_node_t GetNth(students_list_t *PtrStudentList , uint8 index)
{
	uint8 counter;
	student_node_t *PtrIterator = PtrStudentList->head ;
	for(counter =0 ; counter < index ; counter ++ , PtrIterator = PtrIterator->next);
	//now counter = index
	//printf("Name : %s\nID : %d\nHeight : %f\n",PtrIterator->data.StudentName,PtrIterator->data.StudentID,PtrIterator->data.StudentHight);
	return *PtrIterator;
}
void PrintStatus(ListState Status)
{
	switch(Status)
	{
	case List_No_Error:
		printf("===========Process is successfully Done! ==========\n");               fflush (stdout);
		break;
	case List_Null:
		printf("===========Failed ! ( Null Pointer is accessed )===============\n");   fflush (stdout);
		break;
	case List_Loop:
		printf("============Loop is detected ======================\n ");              fflush (stdout);
		break;
	default:
		printf("================ Undefined case! ============== \n");                  fflush (stdout);

	}
}

