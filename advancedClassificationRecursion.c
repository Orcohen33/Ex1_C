#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int len(int);
int newNum(int);
int isArmstrong(int);
int isArmstrongHelp(int ,int);
int isPalindrome(int x);
int firstNum(int);


int poo(int x ,int y){
    if (y==0) return 1;
    return x*poo(x,y-1);
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

int newNum(int x){
    int temp = x/10;
    int length = len(temp);
    int result =0;
    int i;
    int multi=1;
    for (i = 0; i < length-1; i++) {
        result+= (temp%10)*multi;
        multi = multi*10;
        temp =temp/10;
    }
    return result;
}

int firstNum(int x){
    int temp =x;
    while (temp >10){
        temp = temp/10;
    }
    return temp;
}

int isPalindrome(int x){
    if (len(x) == 0 || len(x) == 1)
	{
	 return 1;
	}
    else if (firstNum(x) != x%10)
	{
        return 0;
    	}
	else
	 {
       return isPalindrome(newNum(x));
    	}
}

int isArmstrong(int x){
    int length = len(x);
    int t=x;
    int result = isArmstrongHelp(t , length);
    if (result != x){
        return 0;
    }else {
        return 1;
    }
}

int isArmstrongHelp(int x , int length){
    if (x ==0){
        return 0;
    }  
        return (poo((x%10),length) + isArmstrongHelp(x/10,length));
    
}
