#include "shell.h"

void overkill(int x)
{
	int i;
	for(i=0;i<x;i++){
		kill(bg_pids[i],9);
	}
	printf(":')");
	return ;

}