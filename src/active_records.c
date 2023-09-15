#include<stdio.h>

int max_ar = 0;
int current_ar = 0;

void inc_ar() {
    current_ar += 1;
    if (current_ar > max_ar) {
        max_ar = current_ar;
    }
}

void dec_ar() {
    current_ar -= 1;
}

void print_ar() {
    printf("MAX ACTIVE RECORDS: %d\n", max_ar);
}