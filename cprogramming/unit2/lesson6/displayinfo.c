#include <stdio.h>


typedef struct Info
{
	char name[20];
	int roll;
	float marks;
}info;

int main()
{
	info stud1;
	printf("Enter informatio of students: \nEnter name: ");  fflush(stdout);
	scanf("%s",stud1.name);
	printf("Enter Roll number: ");         fflush(stdout);
	scanf("%d",&stud1.roll);
	printf("Enter marks: ");                fflush(stdout);
	scanf("%f",&stud1.marks);
	printf("Displaying Information ..\n");  fflush(stdout);
	printf("name: %s\n",stud1.name);
	printf("Roll: %d\n",stud1.roll);
	printf("Marks: %.2f\n",stud1.marks);
	
}