#include "shell.h"

void set_env(char x[],char y[])
{
	if(strlen(y)!=0 && strlen(x)!=0){
		setenv(x,y,1);
	}
	else if(strlen(x)!=0){
		setenv(x," ",1);
		printf(":')");
	}
	else{
		printf("not enough arguments\n");
		printf(":'(");
	}
	return ;

}
void unset_env(char x[])
{
	if(strlen(x)!=0){
		unsetenv(x);
		printf(":')");
	}
	else{
		printf("not enough arguments\n");
		printf(":'(");
	}
	return ;

}