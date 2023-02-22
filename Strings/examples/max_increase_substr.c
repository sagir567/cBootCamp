//
// Created by sagi yosef azulay on 22/02/2023.
//
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
# define NUM_LETTERS 'z'-'a' +1

int max_increase_with_memory_substr_from_start(char* string) {
	int used_letters[NUM_LETTERS] = {};
	char max_letter = *string;
	int max_letter_num = 0;
	while (*string) {
		if (*string >= max_letter) {
			max_letter = *string;
			used_letters[*string -'a'] = 1;
			max_letter_num++;
			}
		else if(used_letters[*string -'a']) {
			max_letter_num++;
		}
		else {
			return max_letter_num;
		}
		string++;
	}
	return max_letter_num;
}


int max_new_increase_substr(char* string) {
	int max_letter_num=0;
	while (*string) {
		int letter_num= max_increase_with_memory_substr_from_start(string);
		if (max_letter_num < letter_num) {
			max_letter_num=letter_num;
			}
		string++;
		}
	return max_letter_num;
}

void print_new_increase_substr(char* string){
    int maxLen=0;
    int max =0;
    int start =0;
    int found[26]={0};
    for(int i=0;i<strlen(string);i++){
        if(found[string[i]-'a']){
            continue;
        }
        max=(string[i]-'a');
        found[i]=1;
        for(int j=i+1;j<strlen(string);j++){
            if(((string[j]-'a')<max)&&(!found[string[j]-'a'])){
                memset(found,0,sizeof (char));
                break;
            }
            if(max<string[j]-'a'){
               max= string[j]-'a';
               found[string[j]-'a'] =1;
            }
            maxLen=(maxLen<(j-i+1))?(j-i+1):maxLen;
            if(maxLen==(j-i+1)){
                start=i;
            }
        }

    }
    for(int i=start;i<start+maxLen;i++){
        printf("%c",string[i]);
    }
    printf("   %d",maxLen);
}




int main(){

    char* str ="abfaaczcak";
    print_new_increase_substr(str);
    printf("\n%d", max_new_increase_substr(str));
    return 1;
}


