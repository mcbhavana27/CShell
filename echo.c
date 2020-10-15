#include "shell.h"

void execute_echo(char args[][100]){
	int i;
	i=0;
	while(strlen(args[i])>0){
		char argx[15][50];
		int j;
		for(j=0;j<15;j++)
			free_array(argx[j],50);
		j=0;
		char *cmd=args[i];
		char *token;
		token=strtok(cmd,"$");
		while(token!=NULL){
			strcpy(argx[j],token);
			j++;
			token=strtok(NULL,"$");
		}
		if(args[i][0]=='$')
			j=0;
		else{
			j=1;
			printf("%s",argx[0] );
		}
		while(strlen(argx[j])>0){
			char *val;
			val=getenv(argx[j]+0);
			if(val!=NULL)
				printf("%s",val );
			j++;
		}
		printf(" ");
		i++;
	}
	printf("\n");
	//printf(":')");
}