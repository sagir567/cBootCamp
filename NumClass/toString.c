#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *toString(int n)
{
    char *str;
    int size = 0;
    if (n < 0)
    {
        n *= -1;
        size = (int)(log10((double)n) + 1);
        str = calloc(size + 2, sizeof(char));
        str[0] = '-';
        if (str == null)
        {
            printf("allocation Error :faild to create employe");
            exit(1);
        }
    }

        else
        {
            size = (int)(log10((double)n) + 1);
            str = calloc(size + 1, sizeof(char));
            if (str == null)
            {
                printf("allocation Error :faild to create employe");
                exit(1);
            }
        }

        for (int i = 0; i < size; i++)
        {
            str[size - i - 1] = (char)(n % 10 + '0');
            n = n / 10;
        }
        printf("str =%s ", str);
    }