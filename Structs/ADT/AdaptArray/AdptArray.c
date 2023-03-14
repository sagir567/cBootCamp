//
// Created by sagi yosef azulay on 13/03/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "AdptArray.h"
#include "book.h"


typedef struct AdptArray_ {
    DEL_FUNC delFunc;
    COPY_FUNC copyFunc;
    PRINT_FUNC printFunc;
    int size;
    PElement *arr;
} AdptArray;

typedef AdptArray *PAdptArray;


PAdptArray CreateAdptArray(COPY_FUNC copyFunc_, DEL_FUNC delFunc_, PRINT_FUNC printFunc_) {
    PAdptArray PArr = (PAdptArray) malloc(sizeof(AdptArray));
    if (PArr == NULL) {
        printf("ERROR");
        return NULL;
    }
    PArr->size = 0;
    PArr->arr = NULL;
    PArr->delFunc = delFunc_;
    PArr->copyFunc = copyFunc_;
    PArr->printFunc = printFunc_;
    return PArr;
}


int GetAdptArraySize(PAdptArray pArr){
    if(pArr == NULL){
        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
        return FAIL;
    }
    return pArr->size;
}

Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pNewElement) {


    if (pArr == NULL) {
        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
        return FAIL;
    }
    PElement *newArr;
    if (index >= pArr->size) {
        if ((newArr = (PElement *) calloc(index + 1, sizeof(PElement))) == NULL) {
            return FAIL;
        }
        pArr->arr = realloc(pArr->arr, (index + 1) * sizeof(PElement));
        memcpy(pArr->arr, newArr, (pArr->size) * sizeof(PElement));
        free(newArr);
        pArr->size = (index >= pArr->size) ? (index + 1) : pArr->size;
        return SUCCESS;
    }
    pArr->arr[index] = NULL;
    pArr->delFunc(pArr->arr[index]);
    pArr->arr[index] = pNewElement;
    return  SUCCESS;
}


void DeleteAdptArray(PAdptArray pArr) {
    // handle NULL pointer
    if (pArr == NULL) {

        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
        return;
    }

    for (int i = 0; i < pArr->size; i++) {
        pArr->delFunc(pArr->arr[i]); // delete each element using the DEL_FUNC pointer
    }

    free(pArr->arr); // free the array memory
    free(pArr); // free the AdptArray struct memory
}



void PrintDB(PAdptArray pArr) {
    if (pArr == NULL) {
        printf("ERROR: ArrayList is empty!!");
        return;
    }
    int i;
    for (i = 0; i < pArr->size; i++) {
        pArr->printFunc(pArr->arr[i]);
    }
}


PElement GetAdptArrayAt(PAdptArray pArr, int index) {
    if (pArr == NULL) {
        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
        return NULL;
    }
    if (index >= pArr->size) {
        printf("ERROR: EXCEPTED: index is in the range of the arraylist , actual: index is out of range");
        return NULL;
    }
    return pArr->arr[index];


}


PElement deepCopy(PElement e) {
    PElement newElement;
    newElement = malloc(sizeof(PElement));
    memcpy(newElement, e, 1 * sizeof e);
    return newElement;
}


int main() {
    pbook b1 = creat_book("harry Potter",12345) ;
	pbook b2= creat_book("C intro", 45678) ;
	PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
	SetAdptArrayAt(mybooks,3,b1);
	SetAdptArrayAt(mybooks,5,b2);
    return 1;
}






