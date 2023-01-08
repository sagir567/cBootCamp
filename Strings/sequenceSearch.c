#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sequenceSearch.h"

#define LINE 256
#define WORD 30

int substring(char *str1, char *str2)
{

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int counter = len2;

    if (len1 < len2)
    {
        return 0;
    }

    for (int i = 0; i < len1; i++)
    {
        if (counter == 0)
        {
            return 1;
        }
        if (*(str1 + i) == *(str2 + (i % len2)))
        {
            counter--;
        }
        else
        {
            counter = len2;
        }
    }

    return 0;
}

int getword(char w[])
{
    char temp;
    w[WORD];
    for (int i = 0; i < WORD; i++)
    {
        scanf("%c", &temp);
        if (temp == EOF || (temp == '\n') || (temp == '\t') || (temp == ' '))
        {
            return (i);
        }
        else
        {
            *(w + i) = temp;
        }
    }
    return WORD;
}

int getLine(char s[])
{
    char temp;
    for (int i = 0; i < LINE; i++)
    {
        scanf("%c", &temp);
        if (temp == EOF || (temp == '\n'))
        {
            return (i);
        }
        else
        {
            *(s + i) = temp;
        }
    }

    return LINE;
}

int similar (char *s, char *t, int n){

    if(strcmp(s,t)==0){
    return 1;
    } 

    if((strlen(s)-strlen(t))>n) return 0;

    int j=0;
    
  for(int i=0;i<strlen(s);i++){
    if(*(s+i) == *(t+j)){
        j++;
    }
    else{
        n--;
    }
    
    
  }
  if(n<0)return 0;
    return 1;
    



}

void print_lines(char * str){
int status =1;
int len;
int row =1;
char line[256];
char *pline = line;

while(status){
    int len =getLine(line);
    if(substring(line , str)){
        printf("%s",line);
    }

}



}
int main()
{
    // char a[5] = {'p', 'c'};
    char s[256];
    scanf("cat a\n\nthis is a text file\n\nlooking for the word cat\nthe program should print also cats\nand crat and lcat but it shouldn’t print the word caats",&s);
    char *pointer1 = s;

    char t[256];
    scanf("cat",&t);
    char *pointer2 = t;
    print_lines(t);

    
   

    return 0;
}