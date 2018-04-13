#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
typedef struct directory* Directory;
struct directory{
	char* name;
	Directory next;
};
char* concat(char* ch1,char* ch2){
	int l1 = strlen(ch1)-1;
	int l2 = strlen(ch2)-1;
	int l3 = l1+l2+2;
	char* final = (char*)malloc(sizeof(char)*l3);
	int i=0;
	for(i=0;i<l1+1;i++){
		final[i] = ch1[i];
	}
	final[l1+1] = '/';
	i++;
	int j=0;
	for(;i<l3+1;i++){
		final[i] = ch2[j++];
	}
	final[i] = '\0';
	return final;
}
void dft(char* path){
	struct dirent* dir;
	DIR* dp;
	struct stat statbuf;
	if((dp=opendir(path))==NULL){
		return;
	}
	chdir(path);
	while((dir=readdir(dp))!=NULL){
		lstat(dir->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			if(strcmp(".",dir->d_name)==0 || strcmp("..",dir->d_name)==0)
				continue;
			printf("%s\n",dir->d_name);
			dft(dir->d_name);
		}
		else{
			printf("%s\n",dir->d_name);
		}	
	}
	chdir("..");
	closedir(dp);
}
int main(){
	char* path = "/home";
	dft(path);
}