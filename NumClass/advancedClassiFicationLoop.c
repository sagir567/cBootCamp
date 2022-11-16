#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int countDigits(int n){
    int count =0;
    while (n!=0){
        n=n/10;
        count++;
    }
    return count;
}
   int isArmstrong(int n){
    int power =  countDigits(n);
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


void main(){
    int n=0;
    scanf("%d",&n);
    printf("%d" ,isArmstrong(n));

}