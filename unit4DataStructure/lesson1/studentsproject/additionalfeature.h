/*
 * additionalfeature.h
 *
 *  Created on: Jan 23, 2024
 *      Author: Dell
 */

#ifndef ADDITIONALFEATURE_H_
#define ADDITIONALFEATURE_H_

ListState DetectLoop(students_list_t *PtrStudentList);
void PrintStatus(ListState Status);
void CreateLoop(students_list_t *PtrStudentList);
student_node_t GetNth(students_list_t *PtrStudentList , uint8 index);

#endif /* ADDITIONALFEATURE_H_ */
