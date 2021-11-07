#include "NumClass.h"
#include <stdio.h>
#include <math.h>
int factorial(int);
int isStrong(int);

int isPrime(int x){
	if(x==1){
	return 1;
	}
    int temp = x/2;
    int i;
    for (i=2; i<=temp; i++){
        if (x%i == 0) return 0;
    }
    return 1;
}

int isStrong(int x){
    int result =0,t=x,r=0;
    while(t!=0){
        r = t%10;
	int f = factorial(r);
        result += f;
        t/=10;
    }
    if (x == result)
	{	
		 return 1;
	}
    return 0;

}

int factorial(int x){
    int ans =1;
    for(int i=x;i>0;i--){
    ans*=i;
}
return ans;
}
