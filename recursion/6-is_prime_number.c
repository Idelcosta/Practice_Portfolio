#include <stdio.h>

int _divider (int x, int n);
int is_prime_number(int n)
{
	int x;
	if (n <= 0)
		return (0);
	else 
		return( _divider(2,n));
}

int _divider (int x, int n)
{
	if (x == n)
		return(1);
	else if (n % x == 0)
		return (0);
	else 
		return (_divider (++x,n));
} 

int main(void)
{
	int r;

	r = is_prime_number(49);
    	printf("%d\n", r);
    	r = is_prime_number(1024);
    	printf("%d\n", r);
    	r = is_prime_number(16);
    	printf("%d\n", r);
    	r = is_prime_number(17);
    	printf("%d\n", r);
    	r = is_prime_number(25);
    	printf("%d\n", r);
    	r = is_prime_number(-1);
    	printf("%d\n", r);
    	r = is_prime_number(113);
    	printf("%d\n", r);
    	r = is_prime_number(7919);
    	printf("%d\n", r);
    	return (0);
}
