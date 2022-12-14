#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "NumClass.h" 


   int isArmstrong(int n){

    int power =  (log10(n)+1);
    int temp = n;
    while (n!=0){
        temp-= pow((double)(n%10),(double)power);
        n=n/10;
    }
    return (temp ==0)?true:false;
   }


int isPalindrome(int n){
    int clone =n;
    int temp =0;

    while (clone!=0){
        temp= temp*10 +clone%10;
        clone/=10;
    }
    return (n==temp) ? 1 :0;
  
}


