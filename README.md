Shell:
	My bash shell in c implements basic commands,foreground,background processes..
This is a linux shell written in C which implements built in commands like cd,echo etc and system commands like vi..etc. It handles background processes ,redirection,piping and signals also.

For Running
	run 'make'
	execute by using './shell'
	run 'quit' to exit


Files:
main.c: main file which runs all the functions.
printcmdline.c : prints the command line of the command promt
ls.c : executes the ls function
bg.c : implements the background processes and other system commands
pinfo.c : implements pinfo command
history.c: implements history command
cd.c : implements change directory function
make file: which runs all files together
shell.h : contains all the headers and functions to use.
README.md: contains the info of this file.
env.c:implements the setenv and unsetenv functions
bg_job.c: implements the bg job fun
overkill.c: kills all the functions at a time
fg.c: makes a bg proccess to run in foreground
jobs.c: prints all the background implemented jobs
kjob.c: kills a background running job
redirection.c: implements redirection
pipe.c: implements piping
