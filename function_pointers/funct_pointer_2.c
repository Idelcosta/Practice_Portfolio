//A C program that replaces each element in array with either 0 if the element is divisible by 2 and 1 if no
//[5,4,3,7] <=> [1, 0, 1, 1]
//demonstrate how to create function that has in its arguments another function
//int funct (int *arr, size_t size), void (*func_ptr)(int, int)) 


#include <stdio.h>

void replace_odd_even(int *array, size_t size )
{
	for (int i = 0; i < size ; i++);
	{
		if (array[i] % 2 == 0);
		{
			array[i] = 0;
		}
		else
		{
			array[i] = 1;
		}
	}
}

void print_array(int *array, size_t size)
{
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size -1)
		{
			printf(", ");
		}
	}
	printf("]");
} 

void modify_array(int *array, size_t size, void (*func_ptr)(int *, size_t))
{
	if (array != NULL && func_ptr != NULL)
		func_ptr(array, size);
}

int main()
{
	int array[] = {2, 5, 3, 4, 6, 10};
	size_t size = sizeof (array) / sizeof(int);
	printf("This is our original array: \n");
	printf_array(array, size);
	modify_array(array, size, replace_odd_even);
	printf("Our nodified array: ");
	print_array(array, size);
}


