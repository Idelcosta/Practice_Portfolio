#include <stdio.h>

int add (int x, int y)
{
	return x + y;
}

int main()
{
//	int n;
//	int *ptr;
//	ptr = &n;

	int (*func_ptr)(int ,int);
	int  result;

	func_ptr = &add; // func_ptr = add

	result = func_ptr(2, 4); // result = (*func_ptr)(2,4);
	printf("%d\n", result);
	return 0;
}

