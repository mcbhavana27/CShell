#include "shell.h"
void execute_pinfo(char* s)
{
	int pd,j,i;
	char* token;
	char args[10][10];
	i=0;
	token=strtok(s," ");
	token=strtok(NULL," ");
	char * pp;
	if(token!=NULL && token[0]!='\n' && token[0]!='&'){
		pp=token;
		if(pp[strlen(pp)-1]=='\n')
			pp[strlen(pp)-1]='\0';
		pd=atoi(pp);
	}
	else{
		pd=getpid();
		char buff[300];
		free_array(buff,300);
		sprintf(buff,"%d",pd);
		pp=buff;
	}
	char *arr=malloc(sizeof(char)*100);
	sprintf(arr,"/proc/%d/stat",pd);
	FILE *file;
	char *exe=malloc(sizeof(char)*100);
	sprintf(exe,"/proc/%d/exe",pd);
	if(!(file=fopen(arr,"r"))){
		printf("process does not exist\n");
		printf(":'(");
		return ;
	}
	char tp[300];
	fscanf(file,"%[^\n]",tp);
	char prr[10][100];
	for(i=0;i<10;i++){
		free_array(prr[i],100);
	}
	char * token1;
	token1=strtok(tp," ");
	for(i=0;i<9;i++){
		strcpy(prr[i],token1);
		token1=strtok(NULL," ");
	}
	printf("pid -- %s\n",prr[0] );
	printf("process status -- %s\n",prr[2] );
	printf("virtual mem -- %s\n",prr[8] );
	char exe_path[2050];
	int ret=readlink(exe,exe_path,1000);
	//printf("executable path -- %s\n",prr[1] );
	if(ret==-1){
		printf("no path for executable\n");
	}
	else{
		printf("executable path -- %s\n",prr[1] );
	}
	printf(":')");
	free(exe);
	free(arr);
}