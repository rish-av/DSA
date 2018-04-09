#include"graph.h"
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



Graph map(Graph g){
	int size = g->num;
	for(int i=0;i<size;i++){
		g->adj[i]->v->key = i;
	}
	return g;
}
Graph createGraph(int numV,int* values){
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->adj = (Node*)malloc(sizeof(struct node)*numV);
    g->num = numV;
    for(int i=0;i<numV;i++){
        g->adj[i] = (Node)malloc(sizeof(struct node));
        g->adj[i]->v = (Vertex)malloc(sizeof(struct vertex));
        g->adj[i]->v->value = values[i];
    }
    return map(g);
}
Vertex* getAdjacent(Graph g,Vertex v){
    Vertex* vlist = (Vertex*)malloc(sizeof(Vertex)*g->num);
    Node temp = g->adj[v->key];
    int k=0;
    while(temp->next!=NULL){
    	vlist[k] = (Vertex)malloc(sizeof(struct vertex));
        vlist[k] = temp->next->v;
        temp = temp->next;
        k++;
    }
    vlist[k] = (Vertex)malloc(sizeof(struct vertex));
    vlist[k] = temp->v;
    return vlist;
}
Graph addEdge(Graph g,Vertex v,Vertex vadj){
    Node temp = g->adj[v->key];
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (Node)malloc(sizeof(struct node));
    temp->next->v = vadj;
    return g;
}
int degree(Graph g,Vertex v){
    Node temp = g->adj[v->key];
    int deg = 0;
    while(temp->next!=NULL){
        deg++;
        temp = temp->next;
    }
    return deg;
}
void bfs(Graph g){
	Queue q = newQueue();
	int size = g->num;
	int visited[size];
	for(int i=0;i<size;i++){
		visited[i] = 0;
	}
	q = push(g->adj[0],q);
	while(q->size!=0){
		Node temp = pop(q);
		if(visited[temp->v->key]!=1){
		printf("%d-->",temp->v->value);
		visited[temp->v->key] = 1;
		}
	 	Vertex* list = getAdjacent(g,temp->v);
	 	int j = degree(g,temp->v);
	 	//printf("%d",j);
	 	while(j>0){
	 		//printf("%d",list[j]->key);
	 		if(visited[list[j]->key]!=1){
	 		Node a = newNode(list[j]);
	 		visited[list[j]->key] = 1;
	 		printf("%d-->",list[j]->value);
	 		//printf("%d",j);
	 		q = push(a,q);
	 		}
	 		j--;
	 	}
	}
}
Vertex edge(Graph g,int idx){
	return g->adj[idx]->v;
}

int main(){
	int arr[] = {12,7,65,19,18,20,25};
	Graph g = createGraph(7,arr);
	for(int i=1;i<g->num-1;i++){
		g = addEdge(g,edge(g,0),edge(g,i));
	}
		g = addEdge(g,edge(g,2),edge(g,6));
		g = addEdge(g,edge(g,5),edge(g,6));
	//printf("%d",degree(g,g->adj[0]->v));
	bfs(g);
}