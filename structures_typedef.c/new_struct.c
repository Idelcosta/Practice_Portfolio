#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct Student
{
        char *name;
        char *email;
        float scores;
} student_t;

struct Student *new_student(char *name, char *email, float scores)
{
	student_t *student;
	student = malloc(sizeof(student_t));
	student->name = name;
	student->email = email;
	student->scores = scores;
	return (struct student);
}

int main()
{
	student_t *student;

	student = new_student("John Doe", "johndoe@gmail.com", 22.79);
	if (student == NULL)
		return (-1);
	printf("\nName		: %s", student->name);
	printf("\nEmail		: %s", student->email);
	printf("\nScores	: %f", student->scores);

	return 0;
}
