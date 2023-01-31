#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file1 = fopen("sagi1.txt", "r");
    FILE *file2 = fopen("sagi2.txt", "r");
    FILE *ans = fopen("answer.txt", "w");

    if (file1 == NULL || file2 == NULL || ans == NULL)
        exit(0);

    char *f1 = malloc(1 * sizeof(char));
    char *f2 = malloc(1 * sizeof(char));
    int i, j;

    while (!feof(file1) || !feof(file2))
    {
        i = 0;
        j = 0;

        char c1 = fgetc(file1);
        char c2 = fgetc(file2);

        while (c1 != ' ' && c1 != '\n' && !feof(file1))
        {
            i++;
            f1 = realloc(f1, (i + 1) * sizeof(char));
            *(f1 + i - 1) = c1;
            c1 = fgetc(file1);
        }

        while (c2 != ' ' && c2 != '\n' && !feof(file2))
        {
            j++;
            f2 = realloc(f2, (j + 1) * sizeof(char));
            *(f2 + j - 1) = c2;
            c2 = fgetc(file2);
        }

        *(f1 + i) = '\0';
        *(f2 + j) = '\0';

        if (!strcmp(f1, f2))
        {
            fputs(f1, ans);
            fputc(' ', ans);
        }
        else
        {
            fputs(f1, ans);
            fputc(' ', ans);
            fputs(f2, ans);
            fputc(' ', ans);
        }
    }

    free(f1);
    free(f2);
    fclose(file1);
    fclose(file2);
    fclose(ans);

    return 0;
}