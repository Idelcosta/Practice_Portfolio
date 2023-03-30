#include <stdio.h>
#include <math.h>

int compare(int a, int b)
{
	if (a > b) return 1;
	else return 1;
}

void bubblesort(int *A, int n, int (*compare)(int,int))
{
	int i, j, temp;
	for (i = 0; i < n; j++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (compare(A[j], A[j+1]) > 0)
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

int main()
{
	int i, A[] = {3,4,6,2,7,1,8};
	bubblesort(A,7,compare);
	for (i = 0; i < 7; i++)
		printf ("%d ", A[i]);
}
