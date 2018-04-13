#include<stdio.h>
#include<stdlib.h>
typedef struct heap* Heap;
struct heap{
	int size;
	int* arr;
};
void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
Heap minheapify(Heap h,int i){
	int left = 2*i+1;
	int right = 2*i + 2;
	int minidx = i;
	if(left < h->size && h->arr[left]<h->arr[minidx]){
		minidx = left;
	}
	if(right < h->size && h->arr[right]<h->arr[minidx]){
		minidx = right;

	}
	swap(&(h->arr[i]),&(h->arr[minidx]));
	return minheapify(h,minidx);
}
Heap makeheap(int size,int* values){
	Heap h = (Heap)malloc(sizeof(struct heap));
	h->arr = (int*)malloc(sizeof(int)*size);
	h->size = size;
	for(int i=0;i<size;i++){
		h->arr[i] = values[i];
	}
	return minheapify(h,0);
}
int main(){
	int arr[] = {7,6,3,4,5,1};
	Heap h = makeheap(6,arr);
	for(int i=0;i<6;i++){
		printf("%d",h->arr[i]);
	}
}
