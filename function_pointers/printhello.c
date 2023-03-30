#include <stdio.h>
void printhello(char *name)
{
	printf("hello %s\n", name);
}

int main()
{
	void (*ptr)(char *);
	ptr = printhello;
	ptr("Tom");
}
