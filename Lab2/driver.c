#include<stdio.h>
#include<stdlib.h>
#include"Multiq.h"
int main(){
    MultiQ mq = createMQ(10);
    FILE *f;
    f = fopen("input10.txt","r");
    mq = loadData(f,mq);
    printf("%d",mq->arr[0]->front->tid);
}
