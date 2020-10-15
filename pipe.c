#include "shell.h"
int check_piping(char str[]){
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='|')
			return 1;
	}
	return 0;
}

void piping(char str[])
{
	//printf("came ....\n");
	char *ptoken;
	char **args=malloc(100*sizeof(char *));
	int i,j,fd,status;

	ptoken=strtok(str,"|");
	i=0;
	while(ptoken!=NULL){
		args[i]=ptoken;
		i++;
		ptoken=strtok(NULL,"|");
	}
	int pargs[2];
	pid_t proc;
	fd=0;
	i=0;

	int in_fd,out_fd;
	in_fd=dup(0);
	out_fd=dup(1);

	while(args[i]!=NULL){
		//printf("%s\n",args[i] );
		pipe(pargs);
		proc=fork();

		if(proc<0){
			perror("Error in piping");
			printf(":'(");
		}
		else if(proc==0){
			dup2(fd,0);
			if(args[i+1]!=NULL){
				dup2(pargs[1],1);
			}
			close(pargs[0]);
			execute_commands(args[i]);
			exit(0);
		}
		else{
			wait(NULL);
			//dup2(in_fd,0);
			//dup2(out_fd,1);
			close(pargs[1]);
			fd=pargs[0];
		}
		i++;
	}

}