#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
Queue newQ(){
	Queue q = (Queue)malloc(sizeof(Queue));
	q->front = NULL;
	q->tail = NULL;
	q->length = 0;
	return q;
}
int isEmpty(Queue q){
	if(q->length == 0){
		return 0;
	}
		return 1;
}
Queue delQ(Queue q){
	if(q->front == NULL){
		return q;
	}
	Node temp = q->front;
	q->front = q->front->next;
	q->length--;
	free(temp);
	return q;
 }
Node front(Queue q){
    return q->front;
}
Queue addQ(Queue q, Node e){
    if(q->front==NULL){
        q->front = e;
        q->length++;
        return q;
    }
    e->next = q->tail;
    q->tail = e;
    q->length++;
    return q;
}
int length(Queue q){
    return q->length;
}
void printq(Queue q){
    Node temp = q->front;
    while(temp!=NULL){
        printf("%d-->",temp->tid);
        temp = temp->next;
    }
}
Node newnode(int k, int j) {
	Node e = (Node) malloc(sizeof(Node));
	e->next=NULL;
	e->tid=k;
	e->priority=j;
	return e;
}
