#include"treetravers.h"
void visit(Node n){
	printf("%d\t",n->value);
}
Iterator_list identifyNodes(CurrentSet cr){
	return getChildren(cr->set);
}
CurrentSet addmorenodes(CurrentSet cr,Iterator_list it){
	if(cr==NULL){
		return NULL;
	}
		CurrentSet set = cr;
		while(set->next!=NULL){
			set = set->next;
		}
		while(hasMoreElements_list(it)){
			set->next = (CurrentSet)malloc(sizeof(struct currentset));
			set->next->set = getNextElement_list(it)->tree;
			//printf("%d",set->next->set->value);
			set = set->next;
		}
		return cr;
}
Node selectNextNode(CurrentSet cr){
	return cr->set;
}
void bft(Node tree){
	CurrentSet cr = (CurrentSet)malloc(sizeof(struct currentset));
	cr->set = tree;
	//printf("%p + %p",&(cr->set->it->current->tree),&(tree->it->current->tree));
	while(cr!=NULL){
		visit(cr->set);
		Iterator_list temp = identifyNodes(cr);
		//printf("%d",temp->current->tree->value);
		cr = addmorenodes(cr,temp);
		cr = cr->next;
	}
}
