#include <stdio.h>
#include <stdlib.h>

// program that reads a content of a file and dispay the content

int main()
{
	FILE *fh;

	fh = fopen("file.txt", "r");
	if (fh != NULL)
	{
		char c;
		while ((c = fgets(fh) != EOF)
	} else printf("Error opening file.\n");

	return 0;
} 
