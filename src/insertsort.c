#include "../includes/active_records.h"

void print_arr_with_highlight(int array[], int p, int r, int index) {
    printf("[ ");
    for (int i = p; i < r; i++) {
        if (i == index) {
            printf("|%d| ", array[i]);
            continue;
        }
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void insertsort(int a[], int len) {
    inc_ar();
    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i - 1;
        
        printf("j: %d, i: %d, key: %d\n", j, i, key);
        printf("key highlight: ");
        print_arr_with_highlight(a, 0, len, i);

        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;

        printf("after iter: ");
        print_arr_with_highlight(a, 0, len, len+2);
    }
    dec_ar();
}