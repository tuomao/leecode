#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED


#include "stdlib.h"
#include "stdio.h"
#include <string.h>

#define DEFAULT 10000000

typedef struct Heap{
    int size;
    int len;
    int* data;
}Heap;

/**
n ����ĳ���
**/
Heap* createHeap(int size,int* data,int n);

// k ����Ҫ���Ľڵ�
void swim(Heap* heap,int k);

//k ��Ҫ�³��Ľڵ�
void sink(Heap* heap,int k);

bool insert(Heap* heap,int d);

// ɾ���Ѷ���Ԫ�أ����ضѶ���Ԫ��
int deleteTop(Heap* heap);

void heapsort(int* a,int n);

void test_heap();
void test_heap_insert();


void destoryHeap(Heap* heap);
Heap* createHeap(int size,int* data,int n);


Heap* createHeap(int size,int* data,int n){
    Heap* heap=(Heap*)malloc(sizeof(Heap*));
    heap->size=size;
    heap->len=n;


    //Ϊheap����ռ�
    int* d=(int*)calloc(heap->size,sizeof(int));
    heap->data=d;

    //��heap�����ݽ��и�ֵ
    //ע�⣺�ѵ������Ǵ�λ��1��ʼ������
    int i;
    for(i=0;i<n;i++){
        d[i+1]=data[i];
    }

    //�Ӷ�n/2���ڵ㿪ʼ�����¶��ϵĴ�����
    for(i=heap->len/2;i>=1;i--){
        sink(heap,i);
    }
    return heap;
}

void swim(Heap* heap,int k){

    while(k>1&&heap->data[k] > heap->data[k/2]){
        int temp=heap->data[k/2];
        heap->data[k/2]=heap->data[k];
        heap->data[k]=temp;

		k=k/2;
    }

}
void sink(Heap* heap,int k){
    while(2*k <= heap->len){//������ߵ��ӽڵ����

        int j=k*2;
		//�����ұߵ��ӽڵ����
        // ѡȡ�ӽڵ�Ĵ���
        if(j+1<=heap->len && heap->data[j]<heap->data[j+1]){
           j++;
        }

        // ������߱�������ִ��sink������С�����
        if(heap->data[j]>heap->data[k]){
            int temp=heap->data[k];
            heap->data[k]=heap->data[j];
            heap->data[j]=temp;
        }else{
            break;
        }
		k=j;
    }
}

bool insert(Heap* heap,int d){

    if(heap->size < heap->len){
        return false;
    }
    heap->len++;
    heap->data[heap->len]=d;

    swim(heap,heap->len);
    return true;
}

int deleteTop(Heap* heap){
    if(heap->len>0){
        //  ���ص�ֵ
        int d=heap->data[1];

        //�����һ��Ԫ���ƶ����Ѷ�
        heap->data[1]=heap->data[heap->len];
		heap->data[heap->len]=DEFAULT;
        heap->len--;

        // �ӶѶ���ʼ�³�
        sink(heap,1);

        return d;
    }
    return 0;
}



void heapsort(int* a,int n){
	
    Heap* heap= createHeap(n+1,a,n);

    int i;
    for(i=n-1;i>=0;i--){

        // ÿ�η���heap�����ֵ
        a[i]=deleteTop(heap);
    }

	destoryHeap(heap);

}


void test_heap(){
	
	
    int a[100];

	for(int i=0;i<100;i++){
		a[i]=rand()%100;
	}

    heapsort(a,100);

    int i;
	
    for(i=0;i<100;i++){
        printf("%d ",a[i]);
    }
	
	
}

void destoryHeap(Heap* heap){

	
	free(heap->data);
	free(heap);	
}

void test_heap_insert(){
	int a[6]={4,6,2,8,9,1};
	Heap* heap= createHeap(12,a,6);
	insert(heap,10);
	destoryHeap(heap);
}

#endif // HEAP_H_INCLUDED
