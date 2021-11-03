#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int main(){
int small=1,big=1;
scanf("%d",&small);
scanf("%d",&big);
if(big<small){
int temp = small;
small = big;
big=temp;
}

int i=small;
printf("isPrime :");
	while(i!=big+1){
	if(isPrime(i)==1){
	printf("%d ,",i);
	}
	i++;
	}
i=small;
printf("\n\nisStrong :");
        while(i!=big+1){
        if(isStrong(i)==1){
        printf("%d ,",i);
        }
        i++;
        }
i=small;

printf("\n\nisArmstrong :");
	while(i!=big+1){
	if(isArmstrong(i)==1){
	printf("%d ,",i);
	}
	i++;
	}
i=small;
printf("\n\nisPalindrome :");
	while(i!=big+1){
	if(isPalindrome(i)==1){
	printf("%d ,",i);
	}
	i++;
	}
	printf("\n");
}
