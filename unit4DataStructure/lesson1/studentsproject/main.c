/*
 * main.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Dell
 */

#include "stdio.h"
#include "PlatformTypes.h"
#include "list.h"
#include "additionalfeature.h"
students_list_t studentlist ;
void SelectedTAsk(uint32 option)
{
	uint32 status = List_No_Error;
	switch(option)
	{
	case 1:
		status = AddStudent(&studentlist);
		break ;
	case 2:
		DeleteStudent(&studentlist);
		break;
	case 3:
		DeleteAllStudents(&studentlist);
		break ;
	case 4:
		DisplayAllStudents(&studentlist);
		break;
	}
	PrintStatus(status);
}
int main()
{


	//initiate list
	InitList(&studentlist);

	printf("=====================WELCOME to Student Project================== \n");
	//select option
	uint32 option=0;
	while(1)
	{
		printf("=================================================================\n");
		printf("1- Add new student in the list \n2- Delete student with student id\n3- Delete all students\n4- Display all students\n5- exit \n");
		printf("Select option number : ");   fflush(stdout);
		scanf("%d", &option);                fflush(stdin);
		printf("=================================================================\n");
		if(option == 5 )
		{
			break;
		}
		SelectedTAsk(option);
	}
	///////////////////////////////////////////test GetNth function////////////////////////
	//student_node_t studentnode = GetNth(&studentlist , 2);
	//DisplayNode(studentnode);
	//////////////////////////////////////////check looop code //////////////////////////////
	uint32 status;
	CreateLoop(&studentlist);
	status = DetectLoop(&studentlist);
	PrintStatus(status);
	printf("hhhhhhhhhhhhhhhhh\n");
	//correct loop

	studentlist.tail->next = NULL;
	status = DetectLoop(&studentlist);
	printf("hhhhhhhhhhhhhh\n");
	PrintStatus(status);
}
