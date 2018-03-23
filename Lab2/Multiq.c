#include<stdio.h>
#include<stdlib.h>
#include"Multiq.h"
MultiQ createMQ(int num){
    MultiQ q = (MultiQ)malloc(sizeof(MultiQ));
    q->arr = (Queue*)malloc(sizeof(Queue)*num);
    for(int i=0;i<num;i++){
        q->arr[i] = newQ();
    }
    q->start = &(q->arr[0]);
    q->end = &(q->arr[num-1]);
    return q;
}
MultiQ addMQ(MultiQ mq,Task t){
        int i=0;
        while(i!=t->priority){
            i++;
        }
        mq->arr[i-1] = addQ(mq->arr[i-1],t);
        return mq;
}
Task nextMQ(MultiQ mq){
    Queue* temp = &(mq->arr[0]);
    Task t = NULL;
    while(temp!=mq->end){
        temp = &(mq->arr[++i]);
        if(front(*temp)!=NULL){
            t = front(*temp);
        }
    }
    if(temp==mq->end){
        if(isEmpty(*temp)){
            return NULL;
        }
        t = front(*temp);
    }
    return t;
}
MultiQ delNextMQ(MultiQ mq){
    Queue temp = mq->arr[0];
    int i=0;
    while(isEmpty(temp)){
        i++;
        temp = mq->arr[i];
    }
    mq->arr[i] = delQ(mq->arr[i]);
    return mq;
}
int isEmptyMQ(MultiQ mq){
    Queue* temp = &(mq->arr[0]);
    int i=0;
    while(temp!=mq->end){
        if(!isEmpty(*temp)){
            return 0;
        }
        temp = &(mq->arr[++i]);
    }
        if(!isEmpty(*temp)){
            return 0;
        }
    return 1;
}
int sizeMQ(MultiQ mq){
    int count=0;
    Queue* temp = &(mq->arr[0]);
    while(temp!=mq->end){
        int j = length(*temp);
        count+=j;
    }
        int last = length(*temp);
        count+=last;
        return count;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
    return length(mq->arr[p-1]);
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq->arr[p-1];
}
MultiQ loadData (FILE* f,MultiQ mq){
    int tid,p;
    while(fscanf(f,"%d,%d",&tid,&p)!=EOF) {
		mq = addMQ(mq, newnode(tid,p));
	}
}
MultiQ testDel(int num,MultiQ mq){
    while(num-->=0){
        mq = delNextMQ(mq);
    }

}
void print(MultiQ mq) {
	Queue* q=mq->start;
	int count=0;
	/*while(q!=mq->end){
	    printq((*q));
	}*/
	printq((*q));
	printf("\n");
}




