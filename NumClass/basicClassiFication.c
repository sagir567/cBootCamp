#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
    
    for (int i=2;i<n;i++ ){
        if((n%i)==0){
            return 0;
        }
    } return 1;
}


void main(){

// int n =0;
// scanf("%d",&n);

// printf("%d",isStrong(n));




//     start:
//     printf("insert valid number and i will chack if it's a prime number or not\ninsert -1 to exit\n");
//     int n=0;
//     scanf("%d",&n);
//    if(n==-1){
//     goto end;
//    }
   
//     if(isPrime(n)==1)
//         printf("%d is prime!\n\n\n",n);
    
//     else printf("%d is not prime!\n\n\n",n);

//     goto start;
//     end:
}