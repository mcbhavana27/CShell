#include "shell.h"
void printcommandline(long long int f){
	struct utsname unamedata;
	uname(&unamedata);
	char arr[1000];
	gethostname(arr,1000);
	char username[1000];
	strcpy(username,"<");
	strcat(username,unamedata.nodename);
	strcat(username,"@");
	strcat(username,arr);
	strcat(username,":~");
	printf("\033[0;32m%s\033[0m ",username );
	if(f==1){
		char cwd[1000];
		getcwd(cwd,sizeof(cwd));
		printf("\033[0;34m%s\033[0m> ",cwd );
	}
}