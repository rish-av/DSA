#include<stdio.h>
#include<stdlib.h>
typedef struct vertex* Vertex;
struct vertex{
    int key;
    int value;
};
typedef struct node* Node;
struct node{
    Vertex v;
    Node next;
};
typedef struct graph* Graph;
struct graph{
    int** list; //adjacency matrix
    int num;
    Vertex* vlist;
    Node* adj; //adjacency list
};
typedef struct queue* Queue;
struct queue{
	Node first;
	int size;
};
Vertex edge(Graph g,int idx);
Graph createGraph(int numV,int* values);
Vertex* getAdjacent(Graph g,Vertex v);
Graph addEdge(Graph g,Vertex v,Vertex vadj);
int degree(Graph g,Vertex v);
Node newNode(Vertex v);
Queue newQueue();
Queue push(Node a,Queue q);
Node pop(Queue q);
int size(Queue q);