#include "shell.h"
int bg_index=0;
void run_bg(){
	int j,x,f;
	f=0;
	pid_t pid = waitpid(-1,&x,WNOHANG);
	if(pid>0){
		char str[100];
		for(j=0;j<bg_index;j++){
			if(bg_pids[j]==pid){
				strcpy(str,bg_processes[j]);
				f=1;
				break;
			}
		}
		if(WEXITSTATUS(x)==0 && WIFEXITED(x) && f==1){
			printf("%s with %d exited normally\n",str,pid );
		}
	}
	return ;
}
void bg(char cmd[],char strr[],int is_bg){
	int p,q,l,s;
	p=fork();
	char *args[10];
	char * token=strtok(strr," ");
	int i=0;
	args[1]=NULL;
	while(token != NULL){
		if(token[0]!='&'){
			args[i]=token;
			if(args[i][strlen(args[i])-1]=='\n'){
				args[i][strlen(args[i])-1]='\0';
			}
			i++;
		}
		token=strtok(NULL," ");
	}
	args[i]=NULL;
	if(p==0){
		if(execvp(cmd,args)<0){
			printf("%s command not found\n",cmd);
			exit(EXIT_FAILURE);
		}
		printf(":')");

	}
	else if(p<0){
		perror("Error: ");
		exit(EXIT_FAILURE);
		printf(":'(");
	}
	else{
		if(is_bg==0){
			q=p;
			int w;
			signal(SIGTTIN, SIG_IGN);
			signal(SIGTTOU, SIG_IGN);
			w=waitpid(p,&s,WUNTRACED);
			signal(SIGTTIN, SIG_DFL);
            signal(SIGTTOU, SIG_DFL);
			if(WIFSTOPPED(s)){
				printf("%s with %d exited normally\n",cmd,p );
			}
		}
		else{
			strcpy(bg_processes[bg_index],cmd);
			bg_pids[bg_index]=p;
			bg_index++;
			bgindex(bg_index);
		}
		printf(":')");
	}
}