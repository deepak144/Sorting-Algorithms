#include <stdio.h>

void concure(int arr[], int si, int mid, int ei) {
    int merged[ei - si + 1];  // Create a merged array for the sorted result
    int index1 = si;   // For indexing the left half
    int index2 = mid + 1;  // For indexing the right half
    int x = 0;  // Index for merged array

    // Merging the two halves
    while (index1 <= mid && index2 <= ei) {
        if (arr[index1] <= arr[index2]) {
            merged[x++] = arr[index1++];
        } else {
            merged[x++] = arr[index2++];
        }
    }

    // Copy the remaining elements from the left half (if any)
    while (index1 <= mid) {
        merged[x++] = arr[index1++];
    }

    // Copy the remaining elements from the right half (if any)
    while (index2 <= ei) {
        merged[x++] = arr[index2++];
    }

    // Copy the merged array back to the original array
    for (int i = 0, j = si; i < x; i++, j++) {
        arr[j] = merged[i];  // Copy merged elements back into the original array
    }
}

// Function to divide the array into two halves and recursively sort them
void divide(int arr[], int si, int ei) {
    if (si >= ei) {
        return;  // Base case: if there's one or no elements in the array
    }

    int mid = si + (ei - si) / 2;  // Calculate the middle index

    // Recursively divide the array into two halves
    divide(arr, si, mid);      // Left half
    divide(arr, mid + 1, ei);  // Right half

    // Merge the two sorted halves
    concure(arr, si, mid, ei);
}

int main() {
    int arr[9] = {3, 8, 0, 23, 47, 2, 7, 12, 34};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    // Call the divide function to perform merge sort
    divide(arr, 0, size - 1);

    // Print the sorted array
    for (int i = 0; i < size; i++) {  // Print elements from 0 to size-1
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
