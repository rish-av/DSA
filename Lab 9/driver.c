#include"treetravers.h"
int main(){
	Node tree = createTree(2);
	//int a = hasMoreElements_list(tree->it);
	Element e = getNextElement_list(tree->it);
	//printf("%d",a);
	//Iterator_list it = getChildren(tree);
	bft(tree);
	//printf("%d",tree->it->head->next->tree->it->head->tree->value);
	//generic(tree);
	//printf("%d",e->tree->value);
}
