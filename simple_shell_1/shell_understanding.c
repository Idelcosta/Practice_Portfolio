built-in command: cd pathname. usually pwd

shell will do the following: give options, I/O redirection, piping, sequencing, run in the background, recognition of paranthesis to group

Missing: variables, substitution, aliasing, scripting control (if...fi, while...fo...fone), built commands like pwd etc, line editing, history (arrow keys, command, filename completion), background control, initialization/ strart-up files, environment variables

System calls:
- process control: fork, exec, exit, wait
-I/O: open, close, read, write
-Pipe: pipe, dup
-Change directory: chdir

Main cmnd:
-parse cmnd: recursive descent parser
-run cmnd: walk the tree recursively. "execute" the nodes. Create child procecsses as required 

#define exec 1
#define redir 2
#define pipe 3
#define list 4
#define back 5 

Organisation of program: 
- structs: pipecmd, listcmd, backcmd, execmd, redircmd
- "constructor" functions: pipecmd, listcmd, backcmd, execmd, redircmd
-functions: 
	parsecmd (ptr to buf-> ptr to tree), parseline, parsepipe, parseredirs, 	  parseblock, parseexec
	multerminate
	gettoken
	main (print "$", read stdin->buf)
	runcmd (walk tree and execute
	panic (print error message, terminate process)
	fork1
