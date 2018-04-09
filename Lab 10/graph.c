#include"graph.h"
Graph createGraph(int numV,int* values){
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->list = (int**)malloc(sizeof(int**));
    g->vlist = (Vertex*)malloc(sizeof(Vertex*));
    for(int i=0;i<numV;i++){
        g->list[i] = (int*)malloc(sizeof(int*)*numV);
        g->vlist[i] = (Vertex)malloc(sizeof(struct vertex));
        g->vlist[i]->value = values[i];
        g->vlist[i]->key = i;
        for(int j=0;j<numV;j++){
         if(i!=j){
            g->list[i][j] = 0;
           }
         else{
            g->list[i][j] = 1;
         }
        }
    }
    g->num = numV;
    return g;
}
Vertex* getAdjacent(Graph g,Vertex v){
    int idx = v->key;
    Vertex* v = (Vertex*)malloc(sizeof(Vertex*));
    int k = 0;
    for(int i=0;i<g->num;i++){
        if(g->list[idx][i] == 1 && i!=idx){
            v[k] = g->vList[i];
            k++;
        }
    }
    return v;
}
Graph addEdge(Graph g,Vertex v,Vertex vadj){
    g->list[v->key][vadj->key] = 1;
    return g;
}
int degree(Graph g,Vertex v){
    int idx = v->key;
    int deg = 0;
    for(int i=0;i<g->num;i++){
        if(g->list[idx][i] == 1 && i!=idx){
            deg++;
        }
    }
    return deg;
}
