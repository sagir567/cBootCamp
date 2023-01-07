#include <stdio.h>
#include <math.h>
#include "insertionSort.h"


void insertion_sort(int* arr , int len){
    int current=0,j=0,temp=0,y=0;
    for (int step = 1; step < len; step++) {
        current = *(arr + step);
        j = step - 1;
        y=1;
        while (current < *(arr+j) && j >= 0) {
            temp = current;
            shift_element(arr + j,0);
            *(arr + step-y)=temp;
            --j;
            y++;
        }
   
    }  
     
}
void shift_element(int *arr, int i)
{
    for (int j = i; j >= 0; j--)
    {
        *(arr + j + 1) = *(arr + j);
    }
}


void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", *(arr+i));
        if (i < len - 1) {
            printf(",");
        }
    }
}

int main()
{
    int test[] = {80, 9, 2, 1, 1,3};
    printArr(test, 6);
    printf("\n");
    insertion_sort(test, 6);

    printArr(test, 6);

    return 0;
}
