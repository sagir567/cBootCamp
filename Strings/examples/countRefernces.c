#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "ctype.h"


char *countRefernces(char *str, char ch) {
    int letters=0, nums=0, requested=0;
    char* res =(char*) calloc(0, sizeof(*res));
    char temp;
    if (res == NULL) {
        printf("Error: memory allocation failed");
        exit(0);
    }
    int j=0;

    for(int i=0;*(str+ i);i++){

        if(str[i]>=32 && str[i]<=47)
            continue;

        temp = *(str+i);
        if(temp==ch){
            requested++;
        }
         if(isalpha(temp)){
            letters++;
        }
         if(isdigit(temp)){
            nums++;
        }


         j++;
        res = realloc(res,(j)*sizeof(*res));
        if(res==NULL){
            printf("Error: memory allocation failed");
            exit(0);
        }
    *(res+j-1)=temp;
    }
    j++;
    res = realloc(res,j*sizeof(res));
    if(res==NULL){
        printf("Error: memory allocation failed");
        exit(0);
    }

    *(res +j-1) = 0;
    printf("The number of letters is: %d\nthe number of digits is %d\nthe number of %c is %d\n", letters, nums, ch, requested);
    printf("the new string is %s", res);
    return res;

}




int main() {

char* str ="abc def ghg 123 456";
    countRefernces(str, 'g');
    return 1;
}