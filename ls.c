#include "shell.h"
typedef struct files_data
{
	char file_permissions[20];
	nlink_t file_nhlinks;
	char file_uown[1000];
	char file_gown[1000];
	off_t file_size;
	char file_mtime[100];
	char file_name[1000];
}file;
long long int i,j,p;
void execute_ls(char s[],int l,int a){
	if(strlen(s)==0)
		strcpy(s,"./");
	struct stat st;
	file* files=(file*)malloc(100*sizeof(file));
	i=0;
	DIR *dir;
	struct dirent *dent;
	char * buff;
	if(s[0]=='~'){
		strcpy(s,shelldir);
	}
	dir = opendir(s);
	stat(s,&st);
	char * path=s;
	if(dir != NULL){
		while((dent = readdir(dir))!=NULL){
			struct stat st;
			char f[1000];
			strcpy(f,path);
			if(f[strlen(f)-1]!='/')
				strcat(f,"/");
			strcpy(files[i].file_name,dent->d_name);
			strcat(f,files[i].file_name);
			int x=stat(f,&st);
			if(x==-1){
				perror("error:");
				break;
			}
			char xy;
			if(S_ISREG(st.st_mode))
				xy='-';
			else if(S_ISBLK(st.st_mode))
				xy='b';
			else if(S_ISDIR(st.st_mode))
				xy='d';
			else if(S_ISCHR(st.st_mode))
				xy='c';
			else if(S_ISFIFO(st.st_mode))
				xy='p';
			else if(S_ISLNK(st.st_mode))
				xy='l';
			else
				xy='s';
			files[i].file_permissions[0]=xy;

			if(S_IRUSR & st.st_mode)
				files[i].file_permissions[1]='r';
			else
				files[i].file_permissions[1]='-';
			if(S_IWUSR & st.st_mode)
				files[i].file_permissions[2]='w';
			else
				files[i].file_permissions[2]='-';
			if(S_IXUSR & st.st_mode)
				files[i].file_permissions[3]='x';
			else
				files[i].file_permissions[3]='-';
			if(S_IRGRP & st.st_mode)
				files[i].file_permissions[4]='r';
			else
				files[i].file_permissions[4]='-';
			if(S_IWGRP & st.st_mode)
				files[i].file_permissions[5]='w';
			else
				files[i].file_permissions[5]='-';
			if(S_IXGRP & st.st_mode)
				files[i].file_permissions[6]='x';
			else
				files[i].file_permissions[6]='-';

			if(S_IROTH & st.st_mode)
				files[i].file_permissions[7]='r';
			else
				files[i].file_permissions[7]='-';

			if(S_IWOTH & st.st_mode)
				files[i].file_permissions[8]='w';
			else
				files[i].file_permissions[8]='-';

			if(S_IXOTH & st.st_mode)
				files[i].file_permissions[9]='x';
			else
				files[i].file_permissions[9]='-';

			files[i].file_nhlinks=st.st_nlink;
			strcpy(files[i].file_uown,getpwuid(st.st_uid)->pw_name);
			strcpy(files[i].file_gown,getgrgid(st.st_gid)->gr_name);
			files[i].file_size=st.st_size;
			strftime(files[i].file_mtime, 100, "%b %d %H:%M", localtime(&st.st_mtime));
			i++;
			for(j=0;j<1000;j++)
				f[j]='\0';
		}
		for(j=0;j<i;j++){
			if(a==0){
				if(files[j].file_name[0]=='.'){
					continue;
				}
			}
			if(l==1){
				printf("%s %lu %s %s %ld %s ",files[j].file_permissions,files[j].file_nhlinks,files[j].file_uown,files[j].file_gown,files[j].file_size,files[j].file_mtime);
			}
			printf("%s\n", files[j].file_name);
		}
		//printf(":')");
	}
	else{
		perror("error:");
		//printf(":'(");
	}
}