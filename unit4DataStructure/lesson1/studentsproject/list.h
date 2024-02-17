/*
 * list.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Dell
 */

#ifndef LIST_H_
#define LIST_H_

//max length of name
#define MaxLimit 20


//data for each student(node)
typedef struct
{
	sint8 StudentName[MaxLimit];
	uint32 StudentID;
	float StudentHight;
}data_t;

//each node for student consist of data - next pointer
typedef struct student_node
{
	data_t data;
	struct student_node* next;
}student_node_t;


//all data about student list
typedef struct
{
	//points to first node in students list
	student_node_t *head ;
	//points to last node in students list
	student_node_t *tail;
	//no of students in the list
	uint8 count;
}students_list_t;

//states of operations on list
typedef enum
{
	List_Null,
	List_No_Error,
	List_Loop
}ListState;
//APIs
void InitList(students_list_t *PtrStudentList);
ListState AddStudent(students_list_t *PtrStudentList );
void DeleteStudent(students_list_t *PtrStudentList );
void DisplayAllStudents(students_list_t *PtrStudentList);
void DeleteAllStudents(students_list_t *PtrStudentList);
void DisplayNode(student_node_t studentnode);

#endif /* LIST_H_ */
