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
Node add(Node tree,Node e);
Node find(Node tree,Node search);
Node inorder(Node tree,Node del);
Node delete(Node tree,Node del);
Node createNode(int value);
void traverse(Node tree);
Node parent(Node tree,Node a);
struct node * minValue(struct node* node);
struct node * inOrderSuccessor(struct node *root, struct node *n);