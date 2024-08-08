#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Compute cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radix_sort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Perform counting sort for each digit place
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

int main() {
    // Test case 1
    int arr1[] = {399, 129, 499, 249};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    radix_sort(arr1, n1);
    printf("Sorted array (Test Case 1):\n");
    for (int i = 0; i < n1; i++) {
        printf("%d\n", arr1[i]);
    }

    // Test case 2
    int arr2[] = {99, 149, 349, 299};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    radix_sort(arr2, n2);
    printf("Sorted array (Test Case 2):\n");
    for (int i = 0; i < n2; i++) {
        printf("%d\n", arr2[i]);
    }

    return 0;
}
