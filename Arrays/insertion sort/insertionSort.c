#include <stdio.h>
#include <math.h>
#include "insertionSort.h"

#define size 50


void insertion_sort(int *arr, int len)
{
    int current = 0, j = 0, temp = 0, y = 0;
    for (int step = 1; step < len; step++)
    {
        current = *(arr + step);
        j = step - 1;
        y = 1;
        while (current < *(arr + j) && j >= 0)
        {
            temp = current;
            shift_element(arr + j, 0);
            *(arr + step - y) = temp;
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

void initArr(int *arr, int len)
{
    printf("enter 50 number to see the power of insrtion sort in action!!!\n\n\n go! go! go! insertionsort!!!\n\n\n ");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", arr + i);
    }
 printf("insertion sort is done!\n\n\n ")

}

void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", *(arr + i));
        if (i < len - 1)
        {
            printf(",");
        }
    }
}

int main()
{
    int arr[size];
    initArr(arr, size);
    printArr(arr,size);'
    printf("\n\n\n ")'
    insertion_sort(arr,size);
    printArr(arr,size);


    return 0;
}
