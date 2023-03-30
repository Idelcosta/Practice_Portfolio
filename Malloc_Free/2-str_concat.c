#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**char *str_concat(char *s1, char *s2)
{
	char s, i;
	int len = 0;

	if (s1 == NULL || s2 == NULL)
		printf(" \n");

	for (i = 0; i != '\0'; i++)
		len++;

	s = (malloc(sizeof(char) * len));
	s = (strcat (s1,s2));
	return (s);
}*/

char *str_concat(char *s1[25], char *s2[25])
{  
  printf("Enter value for string_1 : ");  // first string is taken as input
  scanf("%s", s1); 

  printf("\nEnter value for string_2 : ");  // second string is taken as input
  scanf("%s",s2);   

  strcat(s1,s2);  // concatenation is done here

  printf("After concatenation is done, the new concatenated string will be: %s", s1);  
  return 0;
}


int main(void)
{
    char *s;

    s = str_concat("Betty ", "Holberton");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
