#include"iterator.h"
int hasMoreElements_list(Iterator_list it){
	if(it == NULL ){
		return 0;
	}
	if(it->current==NULL){
		it->current = it->head;
		return 0;
	}
	return 1;
}
Element getNextElement_list(Iterator_list it){
	if(hasMoreElements_list(it)){
		Element e = (Element)malloc(sizeof(struct element));
		e->tree = it->current->tree;
		e->next = NULL;
		it->current = it->current->next;
		return e;
	}
	return NULL;
}
int hasMoreElements_array(Iterator_A it){
	if(it->currentidx<it->maxidx){
		return 1;
	}
	return 0;
}
Element getNextElement_array(Iterator_A it){
	if(hasMoreElements_array(it)){
		Element e = it->array[it->currentidx];
		it->currentidx++;
		return e;
	}
	return NULL;
}
Iterator_A createIterator_array(int c){

}
void createIterator_list(Node n,int c){
	Iterator_list it = (Iterator_list)malloc(sizeof(struct iterator_list));
	it->head = (Element)malloc(sizeof(struct element));
	it->head->tree = (Node)malloc(sizeof(struct node));
	it->current = it->head;
	//printf("%p - %p\n",&(it->current->next),&(it->head->next));
	Element temp = it->head;
	int i = 0;
	while(i<=c){
		temp->next = (Element)malloc(sizeof(struct element));
		temp->next->tree = (Node)malloc(sizeof(struct node));
		temp = temp->next;
		i++;
	}
	//temp=NULL;
	n->it = it;
}