#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int main(){
    int num1,num2;
    printf("insert two number to represent the range ");
    scanf("%d %d",&num1,&num2);
    
    int status =4;
    while (status > 0){
        switch (status)
        {
        case 4:
            printf("the prime numbers are:");
            
            break;
        
        case 3:
            printf("the strong numbers are:");
            break;
        
        case 2: 

        printf("the armstrong numbers are:");
        break;
        
        case 1:

        printf("the palindrome numbers are:");
        break;

        }
        for (int i=num1; i<=num2;i++){

            if(status ==4 && isPrime(i)) printf("%d, ",i);
            else if(status ==3 && isStrong(i)) printf("%d, ",i);
            else if(status ==2 && isArmstrong(i)) printf("%d, ",i);
            else if(status ==1 && isPalindrome(i)) printf("%d, ",i);
                      
        }
        printf("\n");
         status--;  

        


    }

return 0;
}