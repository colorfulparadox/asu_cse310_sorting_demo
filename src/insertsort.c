#include "../includes/active_records.h"

void insertsort(int a[], int len) {
    inc_ar();
    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i - 1;
        
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;
    }
    dec_ar();
}