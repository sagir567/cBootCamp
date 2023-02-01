#include"stdio.h"
#include "stdlib.h"

int check_array(int *arr, int n) {
    int max = *arr;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
        int *reminders = malloc(max * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (*(reminders + ((*(arr + i)) % max)) == *(arr + i)) {
                return 0;
            }
            else{
                *(reminders + ((*(arr + i)) % max)) = *(arr + i);
            }
        }
    }
    return 1;
}


int main(){


    int arr[14] = {1,2,3,4,8,6,7,8,9,100,120,130,140,150};
    int n = 14;
    int ans = check_array(arr, n);
    printf("%d", ans);
    return 0;
}