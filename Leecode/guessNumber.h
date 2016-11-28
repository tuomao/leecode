#include "stdlib.h"
#include "stdio.h"

int guess(int num);
int findNumber(int min,int max);
int guessNumber(int n);
int guNumber=1;
int guess(int num){
	if(num==guNumber){
		return 0;
	}else if(num>guNumber){
		return -1;
	}
	return 1;
}

int findNumber(int left,int right){

	int m=left/2+right/2;
	if(left%2==1&&right%2==1){
		m+=1;
	}
	if(guess(m)==0){
		return m;
	}else if(guess(m)==-1){
		return findNumber(left,m);
	}else if(guess(m)==1){
		return findNumber(m+1,right);
	}
	return 0;

}

int guessNumber(int n){
	return findNumber(1,n);
}

void test_guess_number(){
	int n=guNumber;
	int result=guessNumber(n);
	printf("number is %d",result);
}