#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "NumClass.h"

int isStrong(int n){
    int factorial[] ={1,1,2,6,24,120,720,5040,40320,362880};
    int temp =n;

    while(n!=0){

    temp-=factorial[n%10];
    n/=10;

    }
    return (temp ==0) ? true : false;
}

int isPrime(int n){
    
    for (int i=2;i<=sqrt(n);i++ ){
        if((n%i)==0){
            return 0;
        }
    } return 1;
}


