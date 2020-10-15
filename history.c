#include "shell.h"
long long int n=0,i,k,k1;
char commands[10000][1000];
long long int max(long long int a,long long int b){
	if(a>b)
		return a;
	else
		return b;
}
void add_to_history(char arr[]){
	//commands[n]=arr;
	strcpy(commands[n],arr);
	n++;
}
void execute_history(char arr[]){
	long long int j=0;
	while(arr[j]==' ')
		j++;
	j+=7;
	char  num[100];
	for(i=0;i<100;i++)
		num[i]='\0';
	k=strlen(arr)-1;
	while(arr[j]==' ')
		j++;
	while(k>j &&(arr[k]==' ' || arr[k]=='\n' )){
		arr[k]='\0';
		k--;
	}
	k1=0;
	k=0;
	for(i=j;i<strlen(arr);i++){
		if(arr[i]>='0' && arr[i]<='9'){
				num[k]=arr[i];
			k++;
		}
		else if(arr[i]=='\n')
			break;
		else{
			k1=1;
			break;
		}
	}
	//printf("%s\n",num);
	if(k1==1){
		printf("cannot execute history command\n");
		printf(":'(");
	}
	else{
		if(strlen(num)!=0){
			k1=atoll(num);
			for(i=max(0,(n-k1));i<n;i++){
				printf("%s",commands[i]);
			}
		}
		else{
			for(i=max(0,n-10);i<n;i++)
				printf("%s",commands[i] );

		}
		printf(":')");
	}

}