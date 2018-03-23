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
typedef struct node* Node;
struct node{
	char* string;
	int count;
	Node next;
};
typedef struct hashtable* Hashtable;
struct hashtable{
	int elementcount;
	int insertioncost;
	int queryingcost;
	int tablesize;
	Node* array;
};
Hashtable createTable(int tablesize){
	Hashtable ht = (Hashtable)malloc(sizeof(struct hashtable));
	ht->elementcount = 0;
	ht->insertioncost = 0;
	ht->queryingcost = 0;
	ht->tablesize = tablesize;
	ht->array = (Node*)malloc(sizeof(Node*)*ht->tablesize);
	for(int i=0;i<tablesize;i++){
		ht->array[i] = (Node)malloc(sizeof(struct node));
		ht->array[i]->count = 0;
		ht->array[i]->next = NULL;
	}
	return ht;
}
void insert(char** array,int j,Hashtable ht){
	char* string = array[j];
	int i = hash(string,ht->tablesize+3,ht->	tablesize);
	if(ht->array[i]->count==0){
		ht->array[i]->count++;
		ht->array[i]->string = string;
		ht->elementcount++;
		return;
	}
	else{
		Node temp = ht->array[i];
		Node new = (Node)malloc(sizeof(struct node));
		new->string = string;
		while(temp->next!=NULL){
			if(strcmp(string,temp->string)==0){
				temp->count++;
				return;
			}
			temp = temp->next;
			ht->insertioncost++;
		}
		temp->next = new;
		new->next = NULL;
	}
}
int insertAll(char** array,Hashtable ht,int arraysize){
	for(int i=0;i<arraysize;i++){
		insert(array,i,ht);
	}
	return ht->insertioncost;
}
Node lookup(Hashtable ht,char* string){
	int i = hash(string,ht->tablesize+3,ht->tablesize);
	Node temp = ht->array[i];
	while(temp!=NULL){
		if(strcmp(temp->string,string)==0){
			return temp;
		}
		ht->queryingcost++;
	}
	return NULL;
}
int loopupall(Hashtable ht, int m, char** array){ // to be done in the same way as insertall operation was done
	int lsize = (ht->tablesize)*m;
	for(int i=0;i<lsize;i++){
		Node temp1 = lookup(ht,array[i]);
	}
	temp = ht->queryingcost;
	ht->queryingcost = 0;
	return temp;
}
int main(){
	Hashtable ht = createTable(11);
	char* array[6];
	for(int i=0;i<6;i++){
		array[i] = "rishav";
	}
	int a = insertAll(array,ht,6);
	//printf("%d",ht->array[hash("rishav",14,11)]->count);
}