#include <stdio.h>
#include <stdarg.h>

int add (int arg,...);

int main ()
{
	printf("Addition 1 = %d\n", add(4, 5, 6, 7, 3, 7, 1));
	return 0;
}

int add (int args,...)
{
	va_list list;
	va_start(list, args);
	//All actions will take place here
	
	int i, sum = 0;

	for (i - 0; i < args; i++)
	{
		sum += va_arg(list, int);
	}

	va_end(list);

	return sum;
}
