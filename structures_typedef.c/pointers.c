#include <stdio.h>

struct Student
{
	char *name;
	char *email;
	float scores;
};

int main()
{
	struct Student student1;
	struct Student *ptr;
	ptr = &student1;

	(*ptr).name = "John Doe";

	ptr->email = "j.doe@gmail.com";
	ptr->scores = 124.467;
	
	printf("\nName          : %s", student1.name);
        printf("\nEmail         : %s", student1.email);
        printf("\nScores        : %f", student1.scores);

        return 0;
}
