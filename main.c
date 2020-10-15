#include "shell.h"
long long int f,j,is_bg,i;
void sigtstp_handler(int sig_num){
	signal(sig_num,SIG_IGN);
}
void sigint_handler(int sig_num){
	printf("\n");
	printcommandline(f);
	fflush(stdout);
}
void free_array(char arr[],long long int n){
	for(long long int i=0;i<n;i++)
		arr[i]='\0';
}
int tjobs;
void tjbs(int cnt){
	tjobs=cnt;
}
void take_input(){
	char str[2000];
	free_array(str,2000);
	fgets(str,2000,stdin);
	if(strlen(str)==0){
		printf("Thank you\n");
		exit(EXIT_SUCCESS);
	}
	if(strlen(str)>1){
		add_to_history(str);
		//execute_commands(str);
		int j=0;
		char cmds[10][1000];
		for(j=0;j<10;j++)
			free_array(cmds[j],1000);
		char *token=strtok(str,";\n");
		j=0;
		while(token!=NULL){
			strcpy(cmds[j],token);
			//printf("--%s\n",cmds[j] );
			j++;
			token=strtok(NULL,";\n");
		}
		int k=0;
		for(k=0;k<j;k++){
			execute_commands(cmds[k]);
		}
	}
}

void execute_commands(char ostr[]){
	char str[2000];
	free_array(str,2000);
	strcpy(str,ostr);
	char args[100][100];
	char* cmd;
	char* token;
	token=strtok(str," \n\t\r");
	cmd=token;
	token=strtok(NULL," \n\t\r");
	for(i=0;i<100;i++)
		free_array(args[i],100);
	i=0;
	while(token != NULL){
		strcpy(args[i],token);
		i++;
		token=strtok(NULL," \n\t\r");
	}

	is_bg=0;
	j=0;
	int ff=0;
	while(strlen(args[j])>0){
		if(args[j][0]=='&'){
			is_bg=1;
			break;
		}
		j++;
	}
	if(check_piping(ostr)){
		piping(ostr);
		return;
	}
	if(check_redirection(ostr)){
		redirection(ostr);
		return ;
	}
	else if(strcmp(cmd,"cd")==0){
		if(args[0][0]=='-'){
			printf("%s\n",lastdir );
		}
		else{
			f=1;
			execute_cd(args[0]);
		}
	}
	else if(strcmp(cmd,"pwd")==0){
		char pwdd[1000];
		free_array(pwdd,1000);
		getcwd(pwdd,1000);
		printf("%s\n",pwdd );
	}
	else if(strcmp(cmd,"echo")==0){
		execute_echo(args);
	}
	else if(strcmp(cmd,"history")==0){
		execute_history(ostr);
	}
	else if(strcmp(cmd,"ls")==0){
		char argx[100];
		free_array(argx,100);
		j=0;
		int l,a;
		l=0;
		a=0;
		while(strlen(args[j])>0){
			if(strcmp(args[j],"-l")==0)
				l=1;
			if(strcmp(args[j],"-a")==0)
				a=1;
			if(strcmp(args[j],"-al")==0 || strcmp(args[j],"-la")==0){
				l=1;
				a=1;
			}
			j++;
		}
		j=0;
		int fg=0;
		long long int jj=0;
		j=0;
		while(j<10){
			if(strlen(args[j])>0 && args[j][0]!='-' && args[j][0]!='&' ){
				printf("%s:\n",args[j]);
				execute_ls(args[j],l,a);
				fg=1;
			}
			jj++;
			j=jj;

		}
		if(fg==0){
			execute_ls(args[3],l,a);
		}
		
	}
	else if(strcmp(cmd,"pinfo")==0){
		execute_pinfo(ostr);
	}
	else if(strcmp(cmd,"quit")==0){
		exit(EXIT_SUCCESS);
	}
	else if(strcmp(cmd,"jobs")==0){
		jobs();
	}
	else if(strcmp(cmd,"kjob")==0){
		kjob(args[0],args[1],tjobs);
	}
	else if(strcmp(cmd,"fg")==0){
		fg(args[0],tjobs);
	}
	else if(strcmp(cmd,"bg")==0){
		bg_job(args[0],tjobs);
	}
	else if(strcmp(cmd,"overkill")==0){
		overkill(tjobs);
	}
	else if(strcmp(cmd,"setenv")==0){
		set_env(args[0],args[1]);
	}
	else if(strcmp(cmd,"unsetenv")==0){
		unset_env(args[0]);
	}
	else{
		bg(cmd,ostr,is_bg);
		ff=1;
	}
}

int main()
{
	long long int k,k1,k2;
	f=0;
	free_array(lastdir,500);
	free_array(predir,500);
	free_array(shelldir,500);
	getcwd(shelldir,500);
	getcwd(lastdir,500);
	getcwd(predir,500);
	while(1){
		signal(SIGINT,sigint_handler);
		signal(SIGTSTP,sigtstp_handler);
		run_bg();
		printcommandline(f);	
		take_input();
	}
	return 0;
}