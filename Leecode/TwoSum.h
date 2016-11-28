#include "stdlib.h"
#include "stdio.h"

int cmpfunc(const void* a,const void* b);
int* twoSum(int* nums, int numsSize, int target);
int two_sum_test();


int two_sum_test()
{
	int a[]={1,2,4,5,9};
	int* result=twoSum(a,5,10);
	int i;

	for(i=0;i<2;i++){
		printf("%d ",result[i]);
	}
	printf("\n");
	getchar();
	return 0;
}

int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int* twoSum(int* nums, int numsSize, int target) {
	//返回值
	int* result=(int *) malloc(sizeof(int)*2);

	//遍历该数据，每次求差值，查找差值即可
	int i,j;
	for(i=0;i<numsSize;i++){
		int sub=target-nums[i];
		for(j=i+1;j<numsSize;j++){
			if(nums[j]==sub){
				result[0]=i;
				result[1]=j;
				return result;
			}
		}
	}
	return result;
}
