#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>

/**char *_strdup(char *str)
{
	int i, len, k;
	char *j;
	len = 0;

	if (str = NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		len++;

	j = (char *)malloc(sizeof(char) * len + 1);

	if (j != NULL)
	{
		for (k = 0; str[k] != '\0'; k++)
			j[k] = str[k];
	}
	else
	{
		return (NULL);
	}
	return (j);
}*/


/**
 * *_strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}


int main(void)
{
    char *s;

    s = _strdup("ALX SE");
    if (s == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}

