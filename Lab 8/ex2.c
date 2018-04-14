#include"tree.h"
Node traversal(Node tree,int k){
	Node temp = tree;
	while(temp->left!=NULL){
		temp = temp->left;
		printf("%p\n",&temp);
	}
	Node ans = temp;
	int i=1;
	while(i!=k){
		ans = inOrderSuccessor(tree,ans);
		i++;
	}
	return ans;

}
int main(){
	Node tree = createNode(45);
	Node a = createNode(34);
	Node c = createNode(31);
	Node d = createNode(47);
	Node f = createNode(100);
	tree = add(tree,a);
	tree = add(tree,c);
	tree = add(tree,d);
	tree = add(tree,f);
	Node k = traversal(tree,3);
	printf("%d",k->value);
}