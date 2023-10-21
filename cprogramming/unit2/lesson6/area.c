#include <stdio.h>

#define pi (3.14)
#define area(r)  (pi*(r)*(r))

int main()
{
	float radius,area  ;
	printf("Enter the radius: ");   fflush(stdout);
	scanf("%f",&radius);
	area = area(radius);
	printf("Area pi * %.1f * %.1f= %.2f\n",radius,radius,area);
}