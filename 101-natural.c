#include <stdio.h>

int main()
{
	int a, b, c, d, sum;
	for (a = 0; a < 1024; a++)
	{
		b = 0;
		d = 0;
		if (a % 3 == 0 || a % 5 == 0)
		{
			c = b + a;
			d = c;
			sum = d + c;
		}
		else
			continue;
		d = c++;
	}
	printf("the sum of the multiple of 3 or 5 is %d", sum);
}
