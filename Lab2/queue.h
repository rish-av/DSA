#include<stdio.h>
typedef struct queue* Queue;
typedef struct node* Node;
struct queue{
	int length;
	Node front;
	Node tail;
};
struct node{
    int tid;
    int priority;
    Node next;
};
Queue newQ();
int isEmpty();
Queue delQ(Queue q);
Node front(Queue q);
Queue addQ(Queue q,Node e);
int length(Queue q);
void printq(Queue q);
Node newnode(int k, int j);
