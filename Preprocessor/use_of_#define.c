#include <stdio.h>

/**
#define PI 22/7.0
#define SQR(X) X*X
#define DEMO X+X
#define A 10
int main()
{
	double areaofcircle = PI * 10 * 10;
	int n = SQR(10);
	//printf ("Area = %lf", areaofcircle);
	//printf ("%d", n);
	n = DEMO(2) * DEMO(3);
	//n = 2+2 * 3+3;

#undef A //now A undefined
//#define A 20
	printf("%d", A);
}



#define VER1

int main()
{
#ifdef VER1
	printf("This is demo");
#else
	printf("This is not demo");
#endif
}



#define VERSION 2 //will print till the defined Version, till 2. Means Ver1 and Ver2 

int main()
{
#if VER >= 1
        printf("This is for Version 1");
#if VER >= 2
        printf("This is for Version 2");
#if VER >= 3
	printf("This is for Version 3")
#endif
}


#define VERSION 2 //will print till the defined Version, till 2. Means Ver1 and Ver2
*/

int main()
{
#if VER == 1
        printf("This is for Version 1\n");
#elif VER == 2
        printf("This is for Version 2\n");
#elif VER == 3
        printf("This is for Version 3\n")
#else
	#error "Please provide the macro VER\n"
#endif
}

