#include<stdio.h>

#include "../includes/quicksort.h"

void print_int_array(int array[], int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("]");
}

void print_divider() {
    printf("\n-----------------------------------------------\n");
}
int main() {
    printf("Sorting Demo!\n");
    print_divider();
    printf("Quick Sort!\n");

    int array[6] = {5, 1, 8, 9, 4, 2};
    printf("before sort:\n");
    print_int_array(array, 6);

    quicksort(array, 0, 6);

    printf("\nafter sort:\n");
    print_int_array(array, 6);

    print_divider();

    return 1;
}