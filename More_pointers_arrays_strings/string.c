#include <stdio.h>

int main(int argc, char* argv)
{
	char c = 'x';
	char greeting[5] = {'h', 'e', 'l', 'l', 'o'};
	char farewell[] = {"bye"}; 
		
	printf ("%s\n", greeting);
	printf ("%s\n", &c);
}
