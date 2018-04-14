#include"avltree.h"
int main(){
	Node tree = createNode(45);
	Node t;
	t = addm(t,tree);
	Node a = createNode(60);
	Node c = createNode(37);
	Node d = createNode(35);
	Node f = createNode(100);
	t = addm(t,a);
	t = addm(t,c);
	t = addm(t,d);
	//t = addm(t,f);
	preOrder(tree);
}