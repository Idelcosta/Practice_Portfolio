#include <stdio.h>
#include <unistd.h>

int _putchar(char s)
{
	return (write(1, &s, 1));
}

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;
	_print_rev_recursion(s - 1);
	_putchar(*s);
}

int main(void)
{
    _print_rev_recursion("Colton Walker\n");
    return (0);
}
