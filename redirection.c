#include "shell.h"

int check_redirection(char str[])
{
	int i,type;
	for(i=0;i<strlen(str);i++){
		if(str[i]=='>' || str[i]=='<'){
			return 1;
		}
	}
	return 0;
}
int redirection_type(char str[])
{
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]=='>' && str[i+1]=='>')
			return 3;
		if(str[i]=='>')
			return 2;
		if(str[i]=='<')
			return 1;
	}
	return 0;
}
void redirection(char str[])
{
	int type=redirection_type(str);
	if(type==0){
		return;
	}
	char *in_file;
	char *out_file;
	char *input[2];
	char *output[2];
	in_file=out_file=NULL;

	int saved_stdout=dup(STDOUT_FILENO);

	char *str1;
	str1=str;
	output[0]=strtok(str1,">");
	output[1]=strtok(NULL,">");

	input[0]=strtok(output[0],"<");
	input[1]=strtok(NULL,"<");

	char * token;
	char *args[10];
	token=strtok(input[0]," \n\t\r");
	int i=0;
	while(token!=NULL){
		args[i]=token;
		token=strtok(NULL," \n\t\r");
		i++;
		//printf("%s\n",args[i-1] );
	}
	args[i]=NULL;

	in_file=strtok(input[1]," \n\t\r");
	out_file=strtok(output[1]," \n\t\r");
	//printf("%s %s \n",in_file,out_file );
	int pid;
	pid=fork();
	int status;
	if(pid < 0){
		perror("Error ");
		printf(":'(");
		return;
	}
	else if(pid>0){
		while(wait(&status)!=pid){}
	}
	else{
		if(type==1){
			int fd_in;
			fd_in=open(in_file,O_RDONLY);
			if(fd_in<0){
				perror("Input redirection");
				printf(":'(");
				return;
			}
			dup2(fd_in,0);
			close(fd_in);
		}
		if(type==2){
			int fd_out;
			fd_out=open(out_file,O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if(fd_out < 0){
				perror("Output redirection");
				printf(":'(");
				return;
			}
			dup2(fd_out,1);
			close(fd_out);
		}
		if(type==3){
			int fd_out;
			fd_out=open(out_file,O_WRONLY | O_CREAT | O_APPEND, 0644);
			if(fd_out < 0){
				perror("Output redirection");
				printf(":'(");
				return;
			}
			dup2(fd_out,1);
			close(fd_out);
		}
		int r = execvp(args[0],args);
		if(r<0){
			dup2(saved_stdout,1);
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	printf(":')");
	//printf("%d\n",type);
}