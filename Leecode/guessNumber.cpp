#include "stdlib.h"
#include "stdio.h"

int guess(int num);
int findNumber(int min,int max);
int guessNumber(int n);
int guess(int num){
	if(num==6){
		return 0;
	}else if(num<6){
		return -1;
	}
	return 1;
}

int findNumber(int min,int max){

	int m=(min+max)/2;

	if(guess(m)==0){
		return m;
	}else if(guess(m)==-1){
		return findNumber(min,m);
	}else if(guess(m)==1){
		return findNumber(m,max);
	}

}

int guessNumber(int n){
	return findNumber(1,n);
}