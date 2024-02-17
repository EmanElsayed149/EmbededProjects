/*
 * list.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Dell
 */

#include "stdio.h"
#include "stdlib.h"
#include "PlatformTypes.h"
#include "list.h"

void InitList(students_list_t *PtrStudentList)
{
	PtrStudentList->head = NULL;
	PtrStudentList->tail = NULL;
	PtrStudentList->count = 0;

}
ListState AddStudent(students_list_t *PtrStudentList )
{
	//reserve space for the student ......................check for failur of malloc
	student_node_t *PtrNewStudent = (student_node_t *)malloc(sizeof(student_node_t));
	if(PtrNewStudent == NULL)
	{
		return List_Null;
	}

	//insert node to list .....................then increament counter
	if(PtrStudentList->head == NULL)
	{
		//this is the first student in the list
		PtrStudentList->head = PtrNewStudent ;
		PtrStudentList->tail = PtrNewStudent ;
		PtrNewStudent->next = NULL ;
	}else
	{
		//insert this student at the last position in the list
		PtrStudentList->tail->next = PtrNewStudent ;
		PtrNewStudent->next = NULL ;
		PtrStudentList->tail = PtrNewStudent ;
	}
	PtrStudentList->count++;

	//fill data of new student (name - height - id )
	printf("=================Enter data of the student ==================: \n");    fflush(stdout);
	printf("Name : ");                                                              fflush(stdout);
	fgets(PtrNewStudent->data.StudentName , MaxLimit , stdin);                      fflush(stdin);
	printf("ID : ");                                                                fflush(stdout);
	scanf("%u",&PtrNewStudent->data.StudentID);                                     fflush(stdin);
	printf("Height : ");                                                            fflush(stdout);
	scanf("%f",&PtrNewStudent->data.StudentHight);                                  fflush(stdin);

	return List_No_Error;
}
void DeleteStudent(students_list_t *PtrStudentList )
{
	//enter id of student to be deleted
	uint32 id;
	printf("Enter id of student to be deleted :  ");                               fflush(stdout);
	scanf("%d", &id);                                                              fflush(stdin);

	//search for student
	student_node_t *PtrIterator = PtrStudentList->head ;
	student_node_t *PtrPrevious = PtrStudentList->head;
	/* corner case ..........if the first student */
	if(PtrStudentList->head->data.StudentID == id )
	{
		PtrStudentList->count--;
		//if this only student ?
		if(PtrStudentList->head->next == NULL )
		{
			free(PtrStudentList->head);
			InitList(PtrStudentList);
			return ;
		}
		PtrStudentList->head = PtrStudentList->head->next ;
		free(PtrIterator);
		return ;
	}
	PtrIterator = PtrIterator->next ;
	while(PtrIterator)
	{
		if(PtrIterator->data.StudentID == id)
		{
			//check if this is the last node to change tail
			if(PtrIterator->next == NULL)
				PtrStudentList->tail = PtrPrevious ;
			//delete this node
			PtrPrevious->next = PtrIterator->next ;
			free(PtrIterator);
			PtrStudentList->count--;
			return ;
		}
		//move iterator
		PtrIterator = PtrIterator->next ;
		PtrPrevious = PtrPrevious->next;
	}
}
void DisplayAllStudents(students_list_t *PtrStudentList)
{
	student_node_t *PtrIterator = PtrStudentList->head ;
	printf("=========================student data ==========\n");
	while(PtrIterator)
	{
		printf("student name : %s \n",PtrIterator->data.StudentName);
		printf("student ID : %d \n", PtrIterator->data.StudentID);
		printf("student height : %f \n",PtrIterator->data.StudentHight);

		//move iterator
		PtrIterator = PtrIterator->next ;
	}
	printf("==================================================\n");
}
void DeleteAllStudents(students_list_t *PtrStudentList)
{

		student_node_t *PtrIterator = PtrStudentList->head ;
		student_node_t *PtrPrevious ;
		//if this only student ?
		if(PtrStudentList->head->next == NULL )
		{
			free(PtrStudentList->head);
			InitList(PtrStudentList);
			return ;
		}
		//PtrIterator = PtrIterator->next ;
		while(PtrIterator)
		{
			//delete this node
			PtrPrevious = PtrIterator ;
			//move iterator
			PtrIterator = PtrIterator->next ;
			free(PtrPrevious);
		}
		InitList(PtrStudentList);
		printf("All students ara deleted successfully\n");

}
void DisplayNode(student_node_t studentnode)
{
	printf("Name : %s\nID : %d\nHeight : %f\n",studentnode.data.StudentName,studentnode.data.StudentID,studentnode.data.StudentHight);
}
