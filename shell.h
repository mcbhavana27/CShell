#include <sys/utsname.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <pwd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <assert.h>
#include <grp.h>
#include <math.h>
#include <signal.h>

void printcommandline();
void execute_echo();
void execute_cd();
void add_to_history();
void execute_history();
void execute_ls();
void free_array();
void execute_pinfo();
void take_input();
void execute_commands();
void bg();
void run_bg();
void jobs();
void bgindex();
void tjbs();
void kjob();
void fg();
void bg_job();
void overkill();
void set_env();
void unset_env();
int check_redirection();
void redirection();
int check_piping();
void piping();
char bg_processes[100][100];
int bg_ids[100];
int bg_pids[100];
char lastdir[500];
char predir[500];
char shelldir[500];
