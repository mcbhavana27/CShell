#include "shell.h"

void bg_job(char job[],int tjobs){
	int proc;
	proc=atoi(job);
	if(proc>tjobs){
		printf("No such job\n");
		printf(":'(");
	}
	else{
		pid_t pid = bg_pids[proc];
		kill(pid,SIGCONT);
		printf(":')");

	}
}