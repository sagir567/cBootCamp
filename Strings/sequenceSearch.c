#include <stdio.h>
#include <stdlib.h>
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

    for (int i = 0; i < WORD; i++)
    {
        int b = scanf("%c", &temp);
        if (b == -1)
        {

            *(w + i) = EOF;
            return i;
        }
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
            *(s + i) = temp;
            return (i);
        }
        else
        {
            *(s + i) = temp;
        }
    }

    return LINE;
}

int similar(char *s, char *t, int n)
{

    if (strcmp(s, t) == 0)
    {
        return 1;
    }

    if ((strlen(s) - strlen(t)) > n)
        return 0;

    int j = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (*(s + i) == *(t + j))
        {
            j++;
        }
        else
        {
            n--;
        }
    }
    if (n < 0)
        return 0;
    return 1;
}

void print_lines(char *str)
{
    char *line;
    line = (char *)calloc(LINE, sizeof(char));
    int len = 0;

    do
    {
        memset(line, '\0', len);
        len = getLine(line);

        if (substring(line, str))
        {
            printf("%s", line);
        }

    } while ((*(line + len) != EOF));
}

void print_similar_words(char *str)
{
    char *word;
    word = (char *)calloc(LINE, sizeof(char));
    int len = 0;
    do
    {
        memset(word, '\0', len);
        len = getword(word);

        if (similar(word, str, 1) == 1)
        {
            printf("is similer: %s\n", word);
        }

    } while (*(word + len) != EOF);
}

int main()
{
    char *line;
    line = (char *)calloc(LINE, sizeof(char));
    strcpy(line, "cats");
    char *word;
    word = (char *)calloc(LINE, sizeof(char));
    strcpy(word, "cat");

    print_similar_words(word);

    return 0;
}