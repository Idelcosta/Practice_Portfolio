#include <stdarg.h>
#include <stdio.h>


void print_numbers(const char *separator, const unsigned int n, ...);

void print_numbers(const char *separator, const unsigned int n, ...)
{
	char *sep;
	unsigned int i;
	va_list list;

	if (separator == NULL || *separator == 0)
		sep = "";
	else
		sep = (char *) separator;
	va_start(list, n);

	if (n > 0)
		printf("%d", va_arg(list, int));
	for (i = 1; i < n; i++)
		printf("%s%d", sep, va_arg(list, int));
	printf("\n");
	va_end(list);
}


int main(void)
{
    print_numbers(", ", 4, 0, 98, -1024, 402);
    return (0);
}
