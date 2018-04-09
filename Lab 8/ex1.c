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
Node rotate(Node bt,Node X,Node Y,Node Z,Node parent){
	if(Z->left == Y && Y->left == X){
		Node t1 = Y->right;
		Y->right = Z;
		Z->left = t1;
		parent = Y;
		Y->left->heightbalance = 1;
		Y->rigt->heightbalance = 1;
	}
	else if(Z->right == Y && Y->right==X){
		Node t1 = Y->left;
		Y->left = Z;
		Z->right = t1;
		parent = Y;
		Y->left->heightbalance = 1;
		Y->rigt->heightbalance = 1;
	}
	else if(Z->right == Y && Y->left == X){
		Node t2 = X->right;
		Z->right = X;
		X->right = Y;
		Y->left = t2;
		Node t1 = X->left;
		X->left = Z;
		Z->right = t1;
		parent = X;
		X->left->heightbalance = 1;
		X->rigt->heightbalance = 1;
	}
	else if(Z->left == Y && Y->right == X){
		Node t2 = X->left;
		Z->left = X;
		X->left = Y;
		Y->right = t2;
		Node t1 = X->right;
		X->right = Z;
		Z->left = t1;
		parent = X;
		X->left->heightbalance = 1;
		X->rigt->heightbalance = 1;
	}
	return bt;
}
Node modifiedadd(Node bt,Node add){
	bt = add(bt,add);
	Node Z = add;
	Node X = NULL;
	Node Y = NULL;
	while(Z->heightbalance!=0){
		Z = parent(add);
		Y = Z;
		X = Y;
	}
	rotate(bt,X,Y,Z);
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