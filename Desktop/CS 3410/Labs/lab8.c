#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Returns the index of the smallest element in int array arr with length len.
 */
int smallest_idx(int *arr, int len) {
    int i;
    int smallest_i = 0;
    int smallest = arr[0];

    // TODO: implement me using a for loop.
    for(i = 1; i < len; i++){
    if(arr[i]<smallest){
    smallest_i = i;
    smallest = arr[i];
    }
    }
    return smallest_i;
}

/**
 * Swaps the values stored at the memory addresses pointed to by a and b.
 */
void swap(int *a, int *b) {
    // TODO: implement me. Remember to declare any needed local variables.
    int bvalue = *b;
    *b = *a; 
    *a = bvalue; 
}

/**
 * Performs an in-place selection sort on int array arr with length len.
 */
void selection_sort(int *arr, int len) {
    int i, swap_idx;

    for (i = 0; i < len; i++) {
        // TODO: use smallest_idx to find index of
        // smallest element in arr starting from index i
        swap_idx = i+ smallest_idx(&arr[i],(len-i));
        // TODO: Swap the element into place
        // Hint: use the '&' ("address of") operator.
        swap(&arr[swap_idx], &arr[i]);
    }
}

/**
 * Prints the int array arr with length len to stdout.
 */
void print_array(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}

/**
 * Fills array arr with random integer elements.
 */
void rand_array(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

int main(int argc, char *argv[]) {
    int arr[20];
    int len;

    // seed the random number generator
    srand(time(NULL));

    for (len = 5; len <= 20; len += 5) {
        rand_array(arr, len);
        puts("Original array:");
        print_array(arr, len);
        selection_sort(arr, len);
        puts("Sorted array:");
        print_array(arr, len);
    }
}
