#include <stdio.h>
#include <stdlib.h>

struct Student
{
        char *name;
        char *email;
        float scores;
}student_t;

typedef struct Student student_t;

int main()
{
        student_t student1;
        student_t *ptr;

        ptr->name = "John Doe";
	ptr->email = "j.doe@gmail.com";
        ptr->scores = 124.467;

        printf("\nName          : %s", student1.name);
        printf("\nEmail         : %s", student1.email);
        printf("\nScores        : %f", student1.scores);

        return 0;
}

