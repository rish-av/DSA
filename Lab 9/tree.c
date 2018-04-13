#include"tree.h"
#include<time.h>
#define max 5
void buildtree(Node n,int value,int height,int c){
	if(height==max){
		n->value = value;
		return;
	}
	int elemnum = 1;
	n->value = value;
	//printf("%d\t \n",n->value);
	createIterator_list(n,c);
	Iterator_list ls = n->it;
	//printf("%p - %p\n",&(n->it->current->tree),&(n->it->head->tree));
	srand(time(NULL));
	while(hasMoreElements_list(ls)){
		Element e = getNextElement_list(ls);
		elemnum++;
		c = rand()%11;
		buildtree(e->tree,value*5+elemnum,height+1,c); //create gaps for distinct values to set in
	}
	//printf("\n");
}
Node createTree(int c){
	Node root = (Node)malloc(sizeof(struct node));
	buildtree(root,4,0,c);
	return root;
}
int isEmptyTree(Node t){	
	if(t==NULL){
		return 1;
	}
	return 0;
}

int getRootVal(Node t){
	return t->value;
}
Iterator_list getChildren(Node t){
	return t->it;
}