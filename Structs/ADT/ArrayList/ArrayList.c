#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct ArrayList_* PAdptArray;
typedef enum Result {FAIL = 0, SUCCESS};
typedef void* PElement;
typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);



typedef struct ArrayList_{

    DEL_FUNC delFunc;
    COPY_FUNC copyFunc;
     int size;
     PElement* arr;
}ArrayList;



PAdptArray CreateArrayList(DEL_FUNC delFunc_, COPY_FUNC copyFunc_) {
    PAdptArray PArr =(PAdptArray)malloc(sizeof(ArrayList));
    if(PArr==NULL){
        printf("ERROR");
        return NULL;
    }
    PArr->size =0;
    PArr->arr=NULL;
    PArr->delFunc= delFunc_;
    PArr->copyFunc=copyFunc_;
    return PArr;
}
enum Result SetAdptArrayAt(PAdptArray pArr, int index , PElement pNewElement){


        if(pArr == NULL){
            printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
            return FAIL;
        }
        PElement* newArr;
        if (index>=pArr->size){
            if((newArr= (PElement*)calloc(index+1,sizeof (PElement)))==NULL){
                return FAIL;
            }
           pArr->arr= realloc(pArr->arr,(index+1)*sizeof (PElement));
            memcpy(pArr->arr,newArr,(pArr->size) * sizeof (PElement));
            free(newArr);
            pArr->size =(index>= pArr->size)?(index+1):pArr->size;
            return SUCCESS;
        }
        pArr->arr[index]=NULL;
        pArr->delFunc(pArr->arr[index]);
        pArr->arr[index]= pNewElement;
}
//enum Result SetAdptArrayAt(PAdptArray pArr,int index ,PElement pNewElement){
//
//
//    if(pArr == NULL){
//        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
//        return FAIL;
//    }
//    PElement* newArr;
//    if (index>=pArr->size){
//        if((newArr= (PElement*)calloc(index+1,sizeof (PElement)))==NULL){
//            return FAIL;
//        }
//        memcpy(newArr,pArr->arr,(pArr->size) * sizeof (PElement));
//        free(pArr->arr);
//        pArr->arr=newArr;
//
//    }
//    pArr->arr[index]=NULL;
//    pArr->delFunc(pArr->arr[index]);
//    pArr->arr[index]= pNewElement;
//    pArr->arr[index]=pArr->copyFunc(pNewElement);
//
//    pArr->size =(index>= pArr->size)?(index+1):pArr->size;
//    return SUCCESS;
//}
void DeleteArrayList(PAdptArray pArr){
    if(pArr ==NULL){
        return;
    }
    int i;
    for (i=0;i<pArr->size;i++){
        pArr->delFunc(pArr->arr[i]);
    }
    free(pArr->arr);
    free(pArr);

}

void deleteElement(PAdptArray pArr, PElement pElement){
//
    free(pElement);
//    if(pArr==NULL){
//        printf("ERROR: EXCEPTED:Arraylist type pointer , actual: NULL");
//        return;
//    }
//
//
//    for (int i=0; i< pArr->size; i++){
//        if(pArr->arr[i]==pElement){
//            pArr->arr[i]=NULL;
//            printf("element have deleted");
//            return;
//        }
//    }
//    printf("element does not exist in the arraylist");
}
void PrintArrayList(PAdptArray pArr){
    if(pArr==NULL){
        printf("ERROR: ArrayList is empty!!");
        return;
    }
    int i;
    for (i=0;i<pArr->size;i++){
        printf("%d",pArr->arr[i]);
    }
}




PElement deepCopy(PElement e){
    PElement newElement;
    newElement= malloc(sizeof (PElement));
    memcpy(newElement,e,1*sizeof e);
    return newElement;
}



int main(){
   DEL_FUNC *Delete =&deleteElement;
   COPY_FUNC *Copy =&deepCopy;
    PAdptArray arr = CreateArrayList(Delete, Copy);
int num = 3;
    PElement pElement = (PElement)num;
    SetAdptArrayAt(arr, 0, pElement);
//    num = 4;
//    SetAdptArrayAt(arr,1,&num);
//    num = 5;
//    SetAdptArrayAt(arr,2,&num);
//    num = 6;



//     SetAdptArrayAt(arr,3,&num);
    PrintArrayList(arr);
    DeleteArrayList(arr);

    return 1;
}






