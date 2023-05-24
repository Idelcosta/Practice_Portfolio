/**1. Process Identifier (PID) and Parent Process Identifier (PPID)
 * 2. Command Line Arguments (argc and argv)
 * 3. Executing a program (with execve system call)
 * 4. Creating Processes (with the fork system call)
 * 5. suspending Processes (with the wait system call)
 * 6. File Information (with the stat system call)
 * 7. Environment (printenv, etc)
 * 8. Tokenize string


1. Process Identifier (PID) and Parent Process Identifier (PPID)
1.1. what is a Process?
-It is a program in execution
-It is an instance of an executing program that has a unique ID

What's with the pid_t data type?
The pid_t data type is a signed integer type which is capable of representing a process ID
*/

#include <stdio.h>
#include <unistd.h>

//getpid();It returns the process id
//any execution will give a different process id that shows it is unique

int main(void)
{
	int a = 3;
	int b = 5;
	int sum = a + b;
	pid_t pid;

	pid = getpid();

	printf("sum is %d\n", sum);
	printf("sum is %u\n", pid);

	return 0;
}

/**1.2. What is a parent process
the Parent Process is the process that creates a child process
- use PPID (Parent Process Identifier)
This is simply thfe unique identifier of the parent process
getppid();
*/
//The function returns the ppid of the current process
//ppid stay same anytime we execute on the same path of the shell. For example on this file, the path that gives the same ppid is c/User/Lily/Practice_Portfolio/simple_shell_1

#include <stdio.h>
#include <unistd.h>

int main(void)
{
        int a = 3;
        int b = 5;
        int sum = a + b;
        pid_t ppid;

        ppid = getppid();

        printf("sum is %d\n", sum);
        printf("sum is %u\n", ppid);

        return 0;
}
// echo $$ gives the process id of the current running process
// echo $$ will give another ppid if we run /bin/bash in the terminal, even though it seems nothing changed







// 4. Creating Processes (with the fork system call)
/** #fork() system call 
 *
 *  ##Function
 *  System call fork() is used to create processes. It takes no arguments
 *
 *  ## Return Value
 *  pid of child in the parent
 *  0 in the child
 *  -1 if unsuccessful
 *
 *  ##Parameters
 *  None
 *
 *  ##Basic Operation
 *  After a new child process is created, both processes will execute thge next instruction following the 
 *  fork() system call.
 *
 * ##syntax
 * fork()
 *
 * ##header file
 * <unistd.h>
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int mai(void)
{
	pid_t pid;
	pid_t ppid;

	printf("Before fork, I was one\n");

	fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
			return 1;
	}

	if (pid == 0)
	{
		sleep(40);
		printf ("I am the child\n");
	}
	else
	{
		wait(NULL);
		ppid = getpid();
		printf("Parent pid is: %u\n", pid);
	}

	return 0;
}

/**How our program ran
 * Print->after fork I became two
 * Return to shell process
 * Print->After fork I became two, written itself in the command space
 * Does not return to shell process
 *
 *
 *How our program ran
 * -Parent executes and terminates before the child
 * -Child becomes an orphan because its parent died while it was still alive (executing)
 * -The init process (mother of all processes) adopts the child and becomes its parent until it terminates
 * -This adoption changes thge ppid of the child to 1 (the pid of the init process) during its execution
 * -The init process then removes or reaps the child from the process table after its execution
 * -This explains why we couldn't find the child process in the process table with the "ps -eaf" command
 *
 *
 * Why did it write itself and... 
 * #Basic Operations
 * After a new child process is created, both processes will execute the next instruction following thge fork() system call.
 *
 * When child exits, it returns back to the parent
 *
 * If parent has already exited before child returns, the child gets stranded. It is an orphan process. What 
 * happened is that the init process adopted the orphan process, which gave him the ppid of 1
 *
 * #Things to notice
 * Parent id of child process changes during execution to 1
 * child process is removed from process table after execution
 */



/** Things to know about the processes
 * # Orphan Process
 * This is a running process whose parent has finished or terminated.
 *
 * ## Init process 
 * - init is the parent of all processes, executed by the kernel during the booting of the system
 * - it has a pid of 1
 *
 * ## Process Table
 * This is a data structure in the RAM of a computer that holds information about the processes currently been handled by the OS
 *
 * ##Process Entry
 * This is created when the process is created by a fork() system call.
*/


 /** Why do we need to prevent the creation of the Zombie process?
  * There is one process table per system. The size of the process table is finite. If too many zombie proce ar  *e generated, then the process table will be full. That is , the system will not be able to genetate any new   *process, then the system will come to a standstill. Hence, we need to prevent the creation of zombie processes.
  */






// 3. Executing a program (with execve system call)

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
        pid_t pid;

        char *argv[] = {"/bin/ls", "-l", NULL};

        pid = fork();

        if(pid == -1)
                return -1;

        if (pid == 0)
        {
                int val = execve(argv[0], argv, NULL);
                if (val == -1)
                        perror("Error");
        }
        else
        {
                wait(NULL);
                printf("Done with execve\n");
        }
        printf("Done with execve\n");
        return 0;
}











/* Receive inputs in our shell
 * getline usage: ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 * -stream: specify we areareading text fromm keyboard and stored in a buffer called n with size_t
 * -lineptr: stores the address of the buffer that was created.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;
	//char *buf = malloc(sizeof(char)*n);
	char *buf = NULL; //getline will calculate the size and dynamically allocate it.

	printf("Enter name ");
	getline(&buf, &n, stdin);

	printf("Name is %sBuffer size is %ld\n", buf, n);

	free(buf);

	return 0;
}





//8. Tokenize string
/**Strtok: extracts tokesns from strings
 * char *strtok(char *str, const chat *delim)
 * getline reads the whole sentence cmd...
*/

#include <stdin.h>
#include <string.h>
#include <stdlib.h> 

int main (void)
{
	//char str[] = "we are in Buja";
	
	char *src = "we are in Buja";
	char *str = malloc(sizeof(char) * strlen(src));
	char *delim = " ";
	char *token;

	strcpy(str, src);

	token = strtok(str, delim);
	
	//token = strtok(NULL, delim); to get the second word of the cmd which is "are"
	
	while(token != NULL) // while (token)
	{
		printf("%s\n", token);
		token = strtok (NULL, delim);
	} 

	printf("%s", token);
	return 0;
}

//when first token parsed, terminating byte is assigned to the end of the token and start to the address of the next token






//2. Command Line Arguments (argc and(&&) argv)
/** these are the arguments passed from tne command line to the C program when they are executed
 *
 * #argc
 * stores number of command line arguments passed by the user including the name of the program
 *
 * #argv: argument vectors
 * this is a NULL terminated array of strings (character pointers) used to store the entire list of comman * d line arguments
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argc[])
{
	//argv => char *argv[] = {"./cmd_line_args", "coding", "is", "fun", NULL);
	printf ("argc: %d\n", argv);

	for (int i =0; argv[i] != NULL; i++)
		printf("argv[%d]; %s\n", 1, argv[1]);

	return 0;
}


/** Understand what is a shell
 * Shell is REPL (Read Evaluate Print Loop)
 */

//Create custom command line args

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main (void)
{
        char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
        char *delim = " \n";
        size_t n = 0;
        int argc = 0, i = 0;
        char **argv = NULL;

        printf("$ ");

        if (getline(&cmd, &n, stdin) == -1)
                return -1;

        //need a copy of a string if we use strtok because this one alters the string beyond repair
        cmd_cpy = strdup(cmd);

        /**while (cmd[i])
        {
                if (cmd[i] == '\n')
                        printf("\\n ---> Input has %ld characters", strlen(cmd));
                else
                        printf("%c", cmd[i]);
                i++;
        }
        */

        token = strtok (cmd, delim);
 
	while (token)
        {
                token = strtok(NULL, delim);
                argc++;
        }

        printf("%d\n", argc);

        argv = malloc(sizeof(char *) *argc);

        token = strtok(cmd_cpy, delim);

        while (token)
        {
                argv[i] = token;
                token = strtok(NULL, delim);
                i++;
        }
        argv[i] = NULL;

        i = 0;

        while (argv[i])
                printf("%s\n", argv[i++]);

        free(cmd), free(cmd_cpy), free(argv);

        return 0;
}
