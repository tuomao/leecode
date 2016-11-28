#include "stdlib.h"
#include "stdio.h"


typedef struct Node
{
	int key;
	int value;
}Node;


typedef struct HashMap
{
	int size;
	Node** nodes;
}HashMap;


HashMap* createHashMap(int size);
void destoryHashMap(HashMap* hashMap);
void hashSet(HashMap* hashMap,int key,int value);
Node* hashGet(HashMap* hashMap,int key);
void hash_test();

HashMap* createHashMap(int size){
	HashMap* hashMap=(HashMap*)malloc(sizeof(HashMap));
	hashMap->size=size;
	hashMap->nodes=(Node**)calloc(size,sizeof(Node*));
	return hashMap;
}

void destoryHashMap(HashMap* hashMap){
    int i;
	for(i=0;i<hashMap->size;i++){
		Node* node=hashMap->nodes[i];
		free(node);
	}
	free(hashMap->nodes);
	free(hashMap);
}
void hashSet(HashMap* hashMap,int key,int value){

	int hash=abs(key)%hashMap->size;

	Node* node;
	while((node=hashMap->nodes[hash])!=NULL){
		//�����key�Ľڵ��Ѿ����ڣ�����¸ýڵ��ֵ��������
		if(node->key==key){
			node->value=value;
			return;
		}
		//Ѱ����һ�����õ�λ��
		if( hash<hashMap->size){
			hash++;
		}else{
			hash=0;
		}
	}
	//�ڵ㲻����  ��Ѱ����һ�����е��޳�ͻ��λ�ã��½�node
	node=(Node*)malloc(sizeof(Node*));
	node->key=key;
	node->value=value;

	hashMap->nodes[hash]=node;

}
Node* hashGet(HashMap* hashMap,int key){
	int hash=abs(key)%hashMap->size;
	Node* node;
	while ((node=hashMap->nodes[hash])!=NULL)
	{
		if(node->key==key){
			return node;
		}
		if(hash==hashMap->size-1){
			hash=0;
		}else{
			hash++;
		}
	}
	return NULL;
}

void hash_test(){
	HashMap* hashMap=createHashMap(10);
	int a[5]={100,300,29,1,4};

	int i;
	for(i=0;i<5;i++){
		hashSet(hashMap,a[i],a[i]);
	}

	Node* node=hashGet(hashMap,100);
	Node* node1=hashGet(hashMap,300);
	printf("node value is %d \n",node->value);
	printf("node value is %d \n",node1->value);



}
