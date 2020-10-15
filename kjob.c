#include "shell.h"

void kjob(char job_num[],char sig[],int jobs){
	printf("%s %s %d\n",job_num,sig,jobs );
	if(strlen(job_num)==0 || strlen(sig)==0){
		printf("less no of aruments given\n");
		printf(":'(");
		return ;
	}
	int proc, sg;
	proc=atoi(job_num);
	if(proc>jobs){
		printf("No such job exists\n");
		printf(":'(");
		return;
	}
	sg=atoi(sig);
	kill(bg_pids[proc-1],sg);
	printf(":')");
}