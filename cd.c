#include "shell.h"
void  execute_cd(char changedir[]){
	if(changedir[0]=='~' || strlen(changedir)==0){
		chdir(shelldir);
	}
	else if(chdir(changedir)!=0){
		perror("error: ");
		printf(":'(");
		return ;
	}
	printf(":')");
	char arr[500];
	free_array(arr,500);
	getcwd(arr,500);
	if(strcmp(arr,predir)!=0){
		free_array(lastdir,500);
		strcpy(lastdir,predir);
		free_array(predir,500);
		strcpy(predir,arr);
	}
}