//
// Created by sagi yosef azulay on 21/02/2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"



void readFile(char* filename){
    FILE* fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the number of characters from the first line
    int num_chars = 0;
    char c = fgetc(fp);
    while (c != 't') {
        num_chars = (num_chars * 10) + (c - '0');
        c = fgetc(fp);
    }

    // Move the file pointer to the end of the first line
    fseek(fp, strlen("txt\n"), SEEK_CUR);

    // Reverse the input string in place
    int i = 0, j = num_chars - 1;
    while (i < j) {
        // Move i to the next non-newline character
        while (fseek(fp, i, SEEK_SET) == 0 && fgetc(fp) == '\n') {
            i++;
        }
        // Move j to the next non-newline character
        while (fseek(fp, j, SEEK_SET) == 0 && fgetc(fp) == '\n') {
            j--;
        }
        if (i >= j) {
            break;
        }
        // Swap the characters at i and j
        fseek(fp, i, SEEK_SET);
        c = fgetc(fp);
        fseek(fp, j, SEEK_SET);
        fputc(fgetc(fp), fp);
        fseek(fp, i, SEEK_SET);
        fputc(c, fp);
        fseek(fp, j, SEEK_SET);
        fputc(c, fp);
        i++;
        j--;
    }

    // Write a newline and reversed string to the file
    fprintf(fp, "\n");
    fseek(fp, 0, SEEK_END);
    i = num_chars - 1;
    while (i >= 0) {
        while (fseek(fp, i, SEEK_SET) == 0 && fgetc(fp) == '\n') {
            i--;
        }
        if (i < 0) {
            break;
        }
        fseek(fp, 0, SEEK_END);
        fseek(fp, num_chars - 1 - i, SEEK_CUR);
        fputc(fgetc(fp), fp);
        i--;
    }

    // Close the file
    fclose(fp);
}








int main(){
    char* path="Strings/examples/reversedFileText.txt";
    readFile(path);
    return 1;
}
