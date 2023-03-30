#include <stdio.h>
#include "dog.h"

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner)
{
	if (new_dog == NULL)
		new_dog = malloc(sizeof(dog_t));
	new_dog->name = name;
	new_dog->age = age;
	new_dog->owner = owner;

	if (new_dog == NULL)
		return (NULL);
}

int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}
