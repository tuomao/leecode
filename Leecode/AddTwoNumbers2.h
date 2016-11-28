#ifndef ADDTWONUMBERS2_H_INCLUDED
#define ADDTWONUMBERS2_H_INCLUDED

#include "stdlib.h"
#include "stdio.h"


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void test_add_two_number2();
struct ListNode* arrayToList(int* arr,int len);
void printList(struct ListNode* list);


void printList(struct ListNode* list){
    while(list!=NULL){
        printf("%d",list->val);
        list=list->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* p1=l1;
    struct ListNode* p2=l2;
    struct ListNode* sum=NULL;
    struct ListNode* tempNode=NULL;


    int carry=0;//进位
    while(p1!=NULL || p2!=NULL){

        int temp=0;
        if(p1!=NULL){
            temp+=p1->val;
            p1=p1->next;
        }
        if(p2!=NULL){
            temp+=p2->val;
            p2=p2->next;
        }
        temp+=carry;

        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val=temp%10;
        node->next=NULL;
        carry=temp/10;

        if(tempNode==NULL){
            tempNode=node;
            sum=tempNode;

        }else{
            tempNode->next=node;
            tempNode=node;
        }
    }

    //如果还有进位，则再新建一个节点
    if(carry!=0){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val=carry;
        node->next=NULL;
        tempNode->next=node;
    }

    return sum;

}
struct ListNode* arrayToList(int* arr,int len){

    struct ListNode* list=NULL;
    struct ListNode* temp=NULL;

    int i;
    for(i=0;i<len;i++){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val=*(arr+i);
        node->next=NULL;

        //当开始节点没有的时候，则将该节点赋值给开始节点
        if(temp==NULL){
            temp=node;
            list=temp;
        }else{
            temp->next=node;
            temp=node;
        }
    }
    return list;

}




void test_add_two_number2(){
    int a[]={4,5,8};
    int b[]={6,4,3};

    struct ListNode* l1=arrayToList(a,3);
    struct ListNode* l2=arrayToList(b,3);

    struct ListNode* result=addTwoNumbers(l1,l2);

    printList(l1);
    printList(l2);
    printList(result);
}





#endif // ADDTWONUMBERS2_H_INCLUDED
