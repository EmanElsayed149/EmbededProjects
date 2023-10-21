#include <stdio.h>


typedef struct cplx
{
	float real;
	float img;
}complex;

void sum(complex num1,complex num2)
{
	complex res ;
	res.real = num1.real + num2.real;
	res.img = num1.img + num2.img;
	printf("sum = %.2f + %.2f i\n",res.real,res.img);  fflush(stdout);
}
int main()
{
	complex num1,num2;
	printf("for 1st complex \nEnter real and imaginary respectivly : \n");  fflush(stdout);
	scanf("%f %f",&num1.real,&num1.img);
	printf("for 2nd complex \nEnter real and imaginary respectivly : \n");  fflush(stdout);
	scanf("%f %f",&num2.real,&num2.img);
	sum(num1,num2);
	
}