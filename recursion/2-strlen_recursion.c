#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _strlen_recursion(char *s)
{
	if (strlen(s) == 0)
		return 0;
	return strlen(s);
}


int main(void)
{
    int n;
    n = _strlen_recursion("Corbin and Coleman");
    printf("%d\n", n);
    return (0);
}
