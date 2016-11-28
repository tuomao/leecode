#include "stdlib.h"
#include "stdio.h"
bool isPowerOfThree(int n) ;

bool isPowerOfThree(int n) {
	if(n>0){
		while(n>1){
			if(n%3!=0){
				return false;
			}
			n=n/3;
			
		}
		return true;
	}
	return false;
}

void test_isPowerOfThree(){
	printf("3 id %d\n",isPowerOfThree(3)); 
	printf("81 id %d\n",isPowerOfThree(81)); 
	printf("13 id %d\n",isPowerOfThree(13)); 
	printf("153 id %d\n",isPowerOfThree(153)); 
}