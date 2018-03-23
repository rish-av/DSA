#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
typedef struct multiq* MultiQ;
struct multiq{
    Queue* arr;
    Queue* start;
    Queue* end;
};
typedef Node Task;
typedef int Priority;
MultiQ createMQ(int num); // creates a list of num Queues, each of which is empty.
MultiQ addMQ(MultiQ mq, Task t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
Task nextMQ(MultiQ mq); // returns the front of the non-empty Queue in mq
MultiQ delNextMQ(MultiQ mq); // deletes the front of the non-empty Queue in
int isEmptyMQ(MultiQ mq); // tests whether all the Queues in mq are
int sizeMQ(MultiQ mq); // returns the total number of items in
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);
void print(MultiQ mq);
MultiQ loadData (FILE* f,MultiQ mq);
MultiQ testDel(int num,MultiQ mq);
