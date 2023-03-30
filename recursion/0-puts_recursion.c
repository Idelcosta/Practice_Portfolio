#include <stdio.h>
#include <unistd.h>

int _putchar(char s)
{
	return(write(1, &s, 1));
}

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	_putchar(*s);
	s++;
	_puts_recursion(s);
}


int main()
{
	_puts_recursion("Puts with recursion");
	return (0);
}
