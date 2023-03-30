#include <stdio.h>

int main()
{
	int x;
	int *ptr;
	x = 5;
	ptr = &x;

	printf("x is: %d\n", x);
	printf("Memory address of c is: %p\n", ptr);
	printf("%d\n", *ptr);
	return(0);
}
