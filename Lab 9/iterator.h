#include<stdio.h>
#include<stdlib.h>
typedef struct iterator_array* Iterator_A;
typedef struct iterator_list* Iterator_list;
typedef struct element* Element;
typedef struct node* Node;
struct element{
	Node tree;
	Element next;
};	
struct iterator_array{
	Element* array;
	int  currentidx;
	int  maxidx;
};
struct iterator_list{
	Element head;
	Element current;
};
struct node{
	Iterator_list it;
	int value;
};
int hasMoreElements_list(Iterator_list it);
Element getNextElement_list(Iterator_list it);
int hasMoreElements_array(Iterator_A it);
Element getNextElement_array(Iterator_A it);
Iterator_A createIterator_array(int c);
void createIterator_list(Node n,int c);
