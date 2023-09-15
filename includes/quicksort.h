#pragma once
#include<stdio.h>

int partition(int array[], int p, int r) {
    int x = array[r];
    int i = p-1;
    int temp = 0;
    for (int j = p; j < r; j++) {
        if (array[j] <= x) {
            i += 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;
    return i+1;
}

void quicksort(int array[], int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quicksort(array, p, q-1);
        quicksort(array, q+1, r);
    }
}

