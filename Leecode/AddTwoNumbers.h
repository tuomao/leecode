#include "stdlib.h"
#include "stdio.h"



typedef struct ListNode {
	int val;
	ListNode *next;
}ListNode;


ListNode* numberToList(int num);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
unsigned long listToNum(ListNode* list);

int test_add_two_number();



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	unsigned long v1=listToNum(l1);
	unsigned long v2=listToNum(l2);
	unsigned long sum=v1+v2;

	ListNode* result=numberToList(sum);
	return result;
}


unsigned long listToNum(ListNode* list){
	int base=1;
	ListNode* node=list;
	unsigned long result=0;
	while(node!=NULL){
		result+=(node->val)*base;
		node=node->next;
		base=base*10;
	}
	return result;
}

ListNode* numberToList(int num){

	ListNode* startNode;

	ListNode* temp=NULL;

	//初始化 startNode
	int val=num%10;
	num=num/10;
	startNode=(ListNode*)malloc(sizeof(ListNode*));
	startNode->val=val;
	startNode->next=NULL;

	//将startNode 赋值给prenode
	temp=startNode;


	while(num!=0){
		int val=num%10;
		num=num/10;

		//构造next node
		ListNode* next=(ListNode*)malloc(sizeof(ListNode*));
		next->val=val;
		next->next=NULL;

		//将next的值赋值给temp
		temp->next=next;
		temp=next;
	}
	return startNode;
}


int test_add_two_number(){

	unsigned long n1=9;
	unsigned long n2=9999999991;
	ListNode* l1=numberToList(n1);
	ListNode* l2=numberToList(n2);

	ListNode* result=addTwoNumbers(l1,l2);

	printf("result is %d",listToNum(result));
	return 0;
}
