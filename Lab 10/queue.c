#include"queue.h"
Queue push(Node a,Queue q){
	if(q->first==NULL){
		q->first = a;
		q->size++;
	}
	else{
		Node temp = q->first;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = a;
		q->size++;
	}
	return q;
}
Node pop(Queue q){
	if(q->first==NULL){
		return NULL;
	}
	else{
		Node temp = q->first;
		q->first = q->first->next;
		q->size--;
		return temp;
	}
	
}
int size(Queue q){
	return q->size;
}
Queue newQueue(){
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->first = NULL;
	q->size = 0;
}
Node newNode(Vertex v){
	Node a = (Node)malloc(sizeof(struct node));
	a->v = v;
	a->next = NULL;
	return a;
}