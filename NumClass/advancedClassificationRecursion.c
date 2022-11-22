#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "NumClass.h"

int reverseNum(int n, int temp)
{
    if (n == 0)
        return temp;
    temp = (temp * 10) + (n % 10);

    // hold the reversed num
    return reverseNum(n / 10, temp);
}

int isPalindrome(int n)
{
    int temp = reverseNum(n, 0);
    return (n == temp) ? true : false;
}
int isArmstrongRec(int n, int digits)

{
    if (n == 0)
        return n;

    return (pow(n % 10, digits) + isArmstrongRec(n / 10, digits));
}

int isArmstrong(int n)
{
    int digits = (floor(log10(n)) + 1);
    return (n == isArmstrongRec(n, digits)) ? true : false;
}
