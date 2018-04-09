#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
typedef struct queue* Queue;
struct queue{
	Node first;
	int size;
};
Node newNode(Vertex v);
Queue newQueue();
Queue push(Node a,Queue q);
Node pop(Queue q);
int size(Queue q);
