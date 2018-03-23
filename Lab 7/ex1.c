#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int hash(char ch[],int a,int tablesize){
	int sum=0;
	int i=0;
	while(ch[i]!='\0'){
		sum = sum + ch[i];
		i++;
	}
	return (((sum)%a)%tablesize);
}
int collisioncount(char** arr,int a,int m,int asize){
	int count = 0;
	int array[asize];
	for(int i=0;i<asize;i++){
		array[i] = 0;
	}
	for(int i=0;i<asize;i++){
		for(int j=i+1;j<asize;j++){
			if(hash(arr[i],a,m)==hash(arr[j],a,m) && array[j]!=1){
				count++;
				array[j] = 1;
			}
		}
	}
	return count;
}
int check(char* str){
	int i=0;
	int flag=1;
	while(str[i]!='\0'){
		if((str[i] > 'Z' || str[i] < 'A') && (str[i]>'z' || str[i] < 'a')){
			flag = 0;
			break;
		}
		i++;
	}
	return flag;
}
char** parsing(FILE* fp,int* siz){
	char temp[60];
	int i=0;
	char** array = (char**)malloc(sizeof(char*)*100);//realloc should be used
	int size = 100;
	int currsize = 0;
	while(fscanf(fp,"%s",temp)!=EOF){
		if(check(temp)==1){
			array[i] = (char*)malloc(sizeof(char)*20);
			strcpy(array[i],temp);
			i++;
			currsize++;
			if(currsize == size){
				array = (char**)realloc(array,sizeof(char*)*size*2);
				size = 2*size;
			}
		}
	}
	printf("%d\n",i);
	*siz = i;
	return array;
}
void profiling(char** array,int a,int m,int asize){
	if(m==5000){
		int a1 = collisioncount(array,5441,5000,asize);
		int a2 = collisioncount(array,6131,5000,asize);
		int a3 = collisioncount(array,7823,5000,asize);
	}
}//hardcoding is allowed, in other words useless function

int main(){
	FILE *fp ;
	fp = fopen("aliceinwonderland.txt","r");
	int* size;
	char** array = parsing(fp,size);
	printf("%d",*size);
	/*for(int i=0;i<*size;i++){
		printf("%s",array[i]);
	}*/
	//int a = collisioncount(array,45471,32133,22703);
	//printf("%d",a);
}

