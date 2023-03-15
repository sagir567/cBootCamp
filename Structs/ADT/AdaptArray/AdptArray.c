//
// Created by sagi yosef azulay on 13/03/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "AdptArray.h"
#include "book.h"
#include "book.c"
#include "Person.h"
#include "Person.c"
#include "assert.h"

#define min(a, b) ((a) < (b) ? (a) : (b))


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


int GetAdptArraySize(PAdptArray pArr) {
    if (pArr == NULL) {
        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
        return FAIL;
    }
    return pArr->size;
}


Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pNewElement) {
    if (pArr == NULL) {
        printf("ERROR: EXPECTED: AdtArray type pointer, ACTUAL: NULL");
        return FAIL;
    }

    if (index >= pArr->size) {
        PElement *newArr = (PElement *) calloc(index + 1, sizeof(PElement));
        if (newArr == NULL) {
            return FAIL;
        }
        memcpy(newArr, pArr->arr, min(pArr->size, index) * sizeof(PElement));
        free(pArr->arr);
        pArr->arr = newArr;
        pArr->size = index + 1;
    }

    if (pArr->arr[index] != NULL) {
        pArr->delFunc(pArr->arr[index]);
    }
    pArr->arr[index] = pArr->copyFunc(pNewElement);
    if (pArr->arr[index] == NULL) {
        return FAIL;
    }
    return SUCCESS;
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
    if (pArr-> size == 0) {
        printf("ERROR: ArrayList is empty!!");
        return;
    }
     for(int i=0;i<pArr->size;i++){
        if(pArr->arr[i]!=NULL){
            pArr->printFunc(pArr->arr[i]);
        }
    }

}


PElement GetAdptArrayAt(PAdptArray pArr, int index) {
    if (pArr == NULL) {
        printf("ERROR: EXCEPTED:pointer to AdaptArray , actual: NULL\n");
        return NULL;
    }
    if (index >= pArr->size) {
        printf("ERROR: EXCEPTED: index is out of range,\n");
        return NULL;
    }
    if(pArr->arr[index]==NULL){
        printf("ERROR: EXCEPTED: pElement , actual: NULL\n");
        return NULL;
    }
    PElement element = pArr->copyFunc(pArr->arr[index]);
    pArr->copyFunc(element);
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
	printf("the size is %d\n",GetAdptArraySize(mybooks));  //should print 6
	pbook b = GetAdptArrayAt(mybooks,4); // should return null;
//	assert(b==NULL); // doesn't fail
	b = GetAdptArrayAt(mybooks,3);
    print_book(b); //should print "harry Potter"
	printf("the book is %s\n",b->name); //should print "Harry Potter"
    printf("-----------\n");

    mybooks->printFunc(GetAdptArrayAt(mybooks, 3));
	PrintDB(mybooks);

	pperson p1 = creat_person("Harry","Potter", 934);
	pperson p2 = creat_person("Ron","Weasley", 789);
	PAdptArray HP_caracters = CreateAdptArray(copy_person,delete_person,print_person);
	SetAdptArrayAt(HP_caracters,2,p1);
	SetAdptArrayAt(HP_caracters,8,p2);
	printf("the size is %d\n",GetAdptArraySize(HP_caracters)); // prints 9
	PrintDB(HP_caracters); // prints:
	//first name: Harry last name: Potter id: 934
        //first name: Ron last name: Weasley id: 789

	DeleteAdptArray(mybooks);
	DeleteAdptArray(HP_caracters);
	delete_book(b1);
	delete_book(b2);
	delete_book(b);
	delete_person(p1);
	delete_person(p2);
    return 0;
}






