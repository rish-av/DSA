#include"tree.h"
Node parent(Node tree,Node a){
	Node pair = tree;
	if(pair==NULL){
		return NULL;
	}
	if(pair->left==NULL && pair->right==NULL){
		return NULL;
	}
	if((pair->left!=NULL && pair->left->value == a->value )|| (pair->right!=NULL && pair->right->value == a->value)){
		return pair;
	}
	if(pair->value>a->value){
		return parent(pair->left,a);
	}
	else{
		return parent(pair->right,a);
	}
}
Node add(Node tree,Node e){ //head pointer must not be changed!!
	if(tree==NULL){
		tree = e;
	}
	else if(tree->value>e->value){
		tree->left = add(tree->left,e);
	}
	else if(tree->value<e->value){
		tree->right = add(tree->right,e);
	}
	return tree;
}
Node find(Node tree,Node search){
	if(tree==NULL || tree->value==search->value){
		return tree;
	}
	else if(tree->value>search->value){
		return find(tree->left,search);
	}
	else{
		return find(tree->right,search);
	}
}
Node minValue(struct node* node) {
  struct node* current = node;
  
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}
Node inOrderSuccessor(struct node *root, struct node *n)
{
  // step 1 of the above algorithm 
  if( n->right != NULL )
    return minValue(n->right);
 
  // step 2 of the above algorithm
  struct node *p = parent(root,n);
  while(p != NULL && n == p->right)
  {
     n = p;
     p = parent(root,p);
  }
  return p;
}

Node delete(Node tree,Node del){
	if(tree==NULL) return NULL;
	if(tree->value > del->value){
		tree->left = delete(tree->left,del);
	}
	if(tree->value<del->value){
		tree->right = delete(tree->right,del);
	}
	else{
		if(tree->left == NULL){
			Node temp = tree->right;
			free(tree);
			return temp;
		}
		else if(tree->right==NULL){
			Node temp = tree->left;
			free(tree);
			return temp;
		}
		Node a = inOrderSuccessor(tree,del);
		tree->value = del->value;
		tree->right = delete(tree->right,a);
	}
	return tree;
}
Node createNode(int value){
	Node tree = (Node)malloc(sizeof(struct node));
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	tree->heightbalance = 0;
	return tree;
}
void traverse(Node tree){
	if(tree==NULL){
		return;
	}
	traverse(tree->left);
	printf("%d-->",tree->value);
	traverse(tree->right);
}
