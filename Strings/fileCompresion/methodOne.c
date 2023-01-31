#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file1 = fopen("sagi1.txt", "r");
    FILE *file2 = fopen("sagi2.txt", "r");
    FILE *ans = fopen("answer.txt", "w");

    if (file1 == NULL || file2 == NULL || ans == NULL)
        exit(0);

    char *f1 = NULL;
    char *f2 = NULL;
    int size = 0;
    int read1, read2;

    while ((read1 = fscanf(file1, "%ms", &f1)) == 1 || (read2 = fscanf(file2, "%ms", &f2)) == 1)
    {
        if (read1 == 1 && read2 == 1)
        {
            if (!strcmp(f1, f2))
            {
                fprintf(ans, "%s ", f1);
            }
            else
            {
                fprintf(ans, "%s %s ", f1, f2);
            }
            free(f1);
            free(f2);
            f1 = NULL;
            f2 = NULL;
        }
        else if (read1 == 1)
        {
            fprintf(ans, "%s ", f1);
            free(f1);
            f1 = NULL;
        }
        else if (read2 == 1)
        {
            fprintf(ans, "%s ", f2);
            free(f2);
            f2 = NULL;
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(ans);
    return 0;
}



