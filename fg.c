#include "shell.h"

void fg(char job[],int tjobs){
	if(strlen(job)==0){
		printf("no job given\n");
		printf(":'(");
		return;
	}
	int job_num;
	job_num=atoi(job);
	if(job_num>tjobs){
		printf("no such job\n");
		printf(":'(");
		return;
	}
	int pid,w,s;
	pid=bg_pids[job_num-1];
	char job_name[100];
	strcpy(job_name,bg_processes[job_num-1]);
	kill(pid,SIGCONT);
	w=waitpid(pid,&s,WUNTRACED);
	if(WIFSTOPPED(s)){
		printf("%s with %d exited normally\n",job_name,pid );
	}
	printf(":')");
}