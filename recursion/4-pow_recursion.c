#include <stdio.h>
#include <math.h>

int _multiplier(int x, int n);

int _sqrt_recursion(int n)
{
if (n == 1)
return (1);
else if (n == 0)
return (0);
else if (n < 0)
return (-1);
return (_multiplier(2, n));
}

int _multiplier(int x, int n)
{
if (x * x == n)
return (x);
else if (x * x > n)
return (-1);
else
return (_multiplier(++x, n));
}


int main(void)
{
    int r;

    r = _pow_recursion(1);
    printf("%d\n", r);
    r = _pow_recursion(1024);
    printf("%d\n", r);
    r = _pow_recursion(16);
    printf("%d\n", r);
    r = _pow_recursion(17);
    printf("%d\n", r);
    r = _pow_recursion(25);
    printf("%d\n", r);
    r = _pow_recursion(-1);
    printf("%d\n", r);
    return (0);
}
