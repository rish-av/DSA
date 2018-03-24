#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node* Node;
struct node{
	int value;
	Node left;
	Node right;
	int heightbalance;
};
int generate(int min,int max){
	srand(time(NULL));
	return (rand()%21)+150;
}
void printbt(Node bt){
 	if(bt!=NULL){
		printbt(bt->left);
		printf("%d\t",bt->value);
		printbt(bt->right);
 	}
}
Node newnode(int value){
	Node new = (Node)malloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->value = value;
	return new;
}
Node add(Node bt,Node new){
	int temp = new->value;
	if(bt==NULL){
		bt = new;
		return bt;
	}
	if(temp>bt->value){
		bt->right = add(bt->right,new);
	}else if(temp<=bt->value){
		bt->left = add(bt->left,new);
	}
	return bt; // remember to not ulter the root node at any cost!!!!
}

Node createbt(int size){
	int value = generate(0,size);
	Node bt = newnode(value);
	for(int i=0;i<size;i++){
		Node in = newnode(i+2);
		bt = add(bt,in);
		//printbt(bt);
		//printf("\n");
	}
	return bt;
}
Node inorder(Node bt){
	if(bt->left!=NULL){
		return inorder(bt->left);
	}
}
Node find(Node bt,Node new){
	int temp = new->value;
	if(bt->value==temp){
		return bt;
	}
	else if(temp>bt->value){
		return find(bt->right,new);
	}else{
		return find(bt->left,new);
	}
}
void delete(Node bt,Node del){
	if(del->right==NULL && del->left==NULL){
		free(del);
		return;
	}
	if(del->right!=NULL && del->left==NULL){
		Node temp = inorder(del->right);
		del->value = temp->value;
		free(temp);
		return;
	}
	if(del->right==NULL && del->left!=NULL){
		del->value = del->left->value;
		free(del->left);
		return;
	}
	if(del->right!=NULL && del->left!=NULL){
		Node temp = inorder(del->right);
		del->value = temp->value;
		free(temp);
		return;
	}
}

//AVL operations, study this first

void rotate(Node bt,Node X,Node Y,Node Z){

}
Node modifiedadd(){

}
Node modifieddelete(){
	
}

//ex2
int rankquery(Node bt,int k){

}
int* rangequery(Node bt,int range[]){

}
int main(){
	Node bt = createbt(10);
	printbt(bt);
	delete(bt,bt);
	printf("\n");
	printbt(bt);
	//Node temp = bt->left;
	//printf("%d",temp->value);
}