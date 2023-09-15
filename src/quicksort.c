#include "../includes/quicksort.h"
#include "../includes/active_records.h"

int max_size = 0;

void print_array_with_highlight(int array[], int p, int r, int index) {
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

int array_contains(int item, int array[], int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] == item) {
            return 1;
        }
    }
    return 0;
}

void print_array_with_highlights(int array[], int p, int r, int index[]) {
    printf("[ ");
    for (int i = p; i < r; i++) {
        if (array_contains(i, index, 2) == 1) {
            printf("|%d| ", array[i]);
            continue;
        }
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_array(int array[], int r) {
    printf("[ ");
    for (int i = 0; i < r; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int partition(int array[], int p, int r, char *info) {
    inc_ar();

    int x = array[r];
    int i = p-1;
    int temp = 0;

    if (p < r) {
        printf("p: %d, r: %d\n", i, r);
        printf("PIVOT HIGHLIGHT [STATUS: %s]: ", info);
        print_array_with_highlight(array, 0, max_size, r-1);
    }

    for (int j = p; j <= r-1; j++) {
        if (array[j] < x) {
            i += 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            printf("   ITEMS MOVED: ");
            int highlights[2] = {j, i};
            print_array_with_highlights(array, 0, max_size, highlights);

        }
    }
    temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;

    printf("MOVE PIVOT: ");
    int highlights[2] = {i+1, r-1};
    print_array_with_highlights(array, 0, max_size, highlights);

    dec_ar();

    return i+1;
}

void quicksort_helper(int array[], int p, int r, char *info) {
    inc_ar();
    if (p < r) {
        int q = partition(array, p, r, info);
        quicksort_helper(array, p, q-1, "LEFT");
        quicksort_helper(array, q+1, r, "RIGHT");
    }
    dec_ar();
}

void quicksort(int array[], int p, int r) {
    max_size = r;
    quicksort_helper(array, p, r, "FIRST");
}