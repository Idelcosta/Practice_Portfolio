#include <stdio.h>

int main()
{
	int n, a, b, c, d;
	printf ("Write the number n = ");
	scanf ("%d", &n);
	if (n < 15 && n > 0)
	{
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < n; b++)
			{
				putchar ('0' + b * a);
				putchar (' ');
			}
			putchar ('\n');
		}
	}
	else
		printf("wrong number!");
return (0);
}
