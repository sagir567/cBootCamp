#include <malloc/_malloc.h>
#include "stdio.h"

#define ROW 10


int *matAvrege(int mat[][10], int n) {
    int *maxInColl = malloc(10 * sizeof(int));
    double average = 0;
    int minRow = 0;
    double minAverage = 9999;
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            average += mat[i][j];
            if (*(maxInColl + j) < *(*(mat + i) + j))
                *(maxInColl + j) = *(*(mat + i) + j);
        }
        average /= 10;
        if (average < minAverage) {
            minAverage = average;
            minRow = i;
        }
        printf("average of row %d is %.2f\n", i, average);
        average = 0;
    }

    for (int i = 0; i < 10; i++) {
        temp = mat[minRow][i];
        mat[minRow][i] = (mat[0][i]);
        mat[0][i] = temp;
    }

    puts("");
    int *res = mat;
    printf("max values for eace collum are: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", *(maxInColl + i));
    }
    puts("\n\n");
    return maxInColl;
}


int main() {

    int mat[][10] = {{5, 6, 10, 11, 9, 8, 7, 6, 5,  4},
                     {2, 3, 4,  5,  6, 7, 8, 9, 10, 11},
                     {1, 1, 2,  3,  4, 5, 6, 7, 8,  5},
                     {1, 2, 3,  4,  5, 6, 7, 8, 9,  10}};

    matAvrege(mat, 4);
    printf("matrix after swap:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {


            printf("%d, ", *(*(mat + i) + j));
        }
        puts("");
    }


    return 0;
}