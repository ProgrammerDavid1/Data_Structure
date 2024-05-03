#include <stdio.h>
#include <stdlib.h>

int main()
{
	double* p1;
	double a = 23.92;
	p1 = (double*)malloc(sizeof(double));
	p1 = &a;

	return 0;
}
