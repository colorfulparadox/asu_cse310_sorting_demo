#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "../includes/quicksort.h"

void print_int_array(int array[], int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_divider() {
    printf("\n-----------------------------------------------\n");
}

FILE* open_file(char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("COULD NOT OPEN [%s]\n", file_name);
        exit(0);
    }
    return fp;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("MISSING SORT TYPE! [quicksort, _, _]\n");
        return 1;
    }
    if (argc < 3) {
        printf("MISSING FILE PATH!\n");
        return 1;
    }

    char *sort_type = argv[1];
    char *file_name = argv[2];
    FILE *fp = open_file(file_name);
    
    int size = 0;

    int c = 1;
    while (fscanf(fp, "%d", &c) == 1) {
        size += 1;
    }

    if (size <= 0) {
        printf("INPUT FILE [%s] DID NOT HAVE VALID DATA!\n", file_name);
        return 0;
    }
    fclose(fp);

    int array[size];
    fp = open_file(file_name);
    int i = 0;
    while (fscanf(fp, "%d", &array[i]) == 1) {
        i += 1;
    }
    fclose(fp);

    printf("Sorting Demo!\n");

    if (strcmp(sort_type, "quicksort") == 0) {
        printf("QUICKSORT\n");
        printf("BEFORE:\n");
        print_int_array(array, size);
        printf("AFTER:\n");
        quicksort(array, 0, size);
        print_int_array(array, size);
    } else {
        printf("INVALID SORT TYPE [%s]\n", sort_type);
    }

    return 0;
}