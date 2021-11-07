#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int poo(int,int);
int len(int);
int isArmstrong(int);
int isArmstrongHelp(int,int);
int isPalindrome(int);
int reverse(int);


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

int reverse(int x){

int digit =(int)log10(x);
if(x==0){
   return 0;
}
return ((x%10 * pow(10,digit)) +reverse(x/10));

}

int isPalindrome(int x){
    if(x== reverse(x))
{
return 1;
}
return 0;
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
