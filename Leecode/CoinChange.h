#include "stdlib.h"
#include "stdio.h"
#include <math.h>
int coinChange(int* coins, int coinsSize, int amount);

int coinChange(int* coins, int coinsSize, int amount) {
	int* a=(int*)malloc(sizeof(int)*(amount+1));
	
	// 初始化数组
	a[0]=0;
	for(int i=1;i<=amount;i++){
		a[i]=-1;
	}


	for(int i=1;i<=amount;i++){
		for(int j=0;j<coinsSize;j++){
			if(coins[j]-i==0){
				a[i]=1;
			}else if(i-coins[j]>0&&a[i-coins[j]]!=-1){
				if(a[i]==-1){
					a[i]=a[i-coins[j]]+1;
				}else if(a[i-coins[j]]+1<a[i]){
					a[i]=a[i-coins[j]]+1;
				}
			}
		}
	}
	return a[amount];
}

void test_coinChange(){
	int coins[]={1,2,5};
	int amount=11;
	int result=coinChange(coins,3,11);
	printf("%d\n",result);
}