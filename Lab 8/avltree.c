#include"avltree.h"
void preOrder(Node root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int height(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = height(node->left);
       int rDepth = height(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}
Node rotate(Node bt,Node x,Node y,Node z,Node parent){
	Node a;
	Node b;
	Node c;
	Node t0;
	Node t3;
	Node t1;
	Node t2;
	if(z->left==y && y->left==x){
		c = z;
		b = y;
		a = x;
		t0 = x->left;
		t3 = z->left;
		t1 = x->right;
		t2 = y->left;
	}
	else if(z->left==y && y->right==x){
		c = z;
		a = y;
		b = x;
		t0 = z->right;
		t3 = y->right;
		t1 = x->left;
		t2 = x->right;
	}
	else if(z->right==y && y->left==x){
		a = z;
		b = x;
		c = y;
		t0 = y->right;
		t3 = z->left;
		t1 = x->left;
		t2 = x->right;
	}
	else{
		c = x;
		b = y;
		a = z;
		t0 = z->left;
		t1 = y->left;
		t2 = x->left;
		t3 = x->right;
	}
	if(parent->left==z){
		parent->left = b;
		b->left = a;
		b->right = c;
		a->left = t0;
		a->right = t1;
		c->left = t2;
		c->right = t3;
	}
	if(parent->right==z){
		parent->right = b;
		b->left = a;
		b->right = c;
		a->left = t0;
		a->right = t1;
		c->left = t2;
		c->right = t3;
	}
	int h0 = height(t0);
	int h1 = height(t1);
	int h2 = height(t2);
	int h3 = height(t3);
	a->heightbalance = h1-h0;
	c->heightbalance = h3-h2;
	int h4 = h0;
	int h5 = h3;
	if(h1>h0){
		h4 = h1;
	}
	if(h2>h3){
		h5 = h2;
	}
	b->heightbalance = h5-h4;
}
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
Node balance(Node tree,Node insert){
	Node x;
	Node y;
	Node z;
	Node temp = insert;
	while(temp!=NULL){
		x = y;
		y = temp;
		if(temp!=NULL && (temp->heightbalance<-1 || temp->heightbalance>1)){
			z = temp;
			rotate(tree,x,y,z,parent(tree,x));
			break;
		}
		temp = parent(tree,temp);
	}
	
	
}
Node addm(Node tree, Node a){
	if(tree==NULL){
		tree = a;
		tree->heightbalance = 0;
		return tree;
	}
	Node temp = tree;
	while(temp!=NULL){
	if(temp->value>a->value){
		if(temp->left==NULL){
			temp->left = a;
			break;
		}
		temp = temp->left;
	}
	else if(temp->value<a->value){
		if(temp->right==NULL){
			temp->right = a;
			break;
		}
		temp = temp->right;
	}
	}
	Node x = a;
	Node y = parent(tree,x);
	Node z = parent(tree,y);
	while(z!=NULL){
	int h1 = height(z->left);
	int h2 = height(z->right);
	int diff = h2-h1;
	z->heightbalance = diff;
	if(parent(tree,z)!=NULL && (diff<-1 || diff>1)){
		rotate(tree,x,y,z,parent(tree,z));
	}
	x = y;
	y = z;
	z = parent(tree,z);

	}
	return tree;
}
void deletem(Node tree,Node value){

}