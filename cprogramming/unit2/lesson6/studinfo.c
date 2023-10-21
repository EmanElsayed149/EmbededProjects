#include <stdio.h>


typedef struct Info
{
	char name[20];
	float marks;
}info;

int main()
{
	info stud[10];
	printf("Enter informatio of students: \n");  fflush(stdout);
	for(int i=0;i<10;i++)
	{
		printf("for roll%d\n",i+1);
		printf("Enter name: ");   fflush(stdout);
		scanf("%s",stud[i].name);
		printf("Enter marks: ");                fflush(stdout);
		scanf("%f",&stud[i].marks);
	}
	
	printf("Displaying Information ..\n");  fflush(stdout);
	for(int i=0;i<10;i++)
	{
		printf("for roll%d\n",i+1);
		printf("name: %s\n",stud[i].name);
		printf("Marks: %.2f\n",stud[i].marks);
	}
	
	
}