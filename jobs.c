#include "shell.h"
int bg_index;
void bgindex(int cnt){
	bg_index=cnt;
	tjbs(bg_index);
}
void jobs()
{
	int i,j,k;
	//printf("%d\n",bg_index);
	for(i=0;i<bg_index;i++){
		char *arr = malloc(sizeof(char)*200);
		sprintf(arr,"/proc/%d/stat",bg_pids[i]);
		FILE *fd;
		if(!(fd=fopen(arr,"r"))){
			printf("[%d] Done %s\n",i+1,bg_processes[i] );
		}
		else{
			int p;
			char status;
			long unsigned mem;
			fscanf(fd, "%d %*s %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d", &p, &status, &mem);
			fclose(fd);
			if(status == 'T'){
				printf("[%d] Stopped %s\n",i+1,bg_processes[i] );
			}
			else{
				printf("[%d] RUNING %s\n",i+1,bg_processes[i] );
			}

		}
	}
	printf(":')");

}