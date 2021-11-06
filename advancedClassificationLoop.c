#include "NumClass.h"
#include <stdio.h>
#include <math.h>



int len(int );
int isPalindrome(int x){ 
    int temp=x;
    int compare =0;
    int moudle =0;
    while (temp !=0){
        moudle = temp%10;
        compare = (compare*10)+moudle;
        temp = temp/10;
    }
    if (compare != x){
        return 0;
    }else {
        return 1;
    }
}


int isArmstrong(int x){
    int length= len(x);
    int temp =x;
    int i;
    int compare =0;
    for (i = 0; i < length; i++){
	int digit = temp%10;
        compare+= (int)pow((int)digit , (int)length);
        temp= temp/10;
    }
    if (compare != x){
        return 0;
    }else{
        return 1;
    }
}

int len(int x){
    int temp = x;
    int counter =0;
    while (temp !=0){
        temp = temp/10;
        counter++;
    }
    return counter;
}
