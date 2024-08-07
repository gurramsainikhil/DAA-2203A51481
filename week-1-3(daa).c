#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void parse_input(const char *input, int *arr, int *size) {
    const char *ptr = input;
    char buffer[16]; 
    int num, count = 0;
    
    while (*ptr) {
        if (sscanf(ptr, "%d", &num) == 1) {
            arr[count++] = num;
            while (*ptr && *ptr != ',') ptr++;
        }
        if (*ptr == ',') ptr++;
    }
    *size = count;
}

int main() {
    const char *input1 = "87,67,21,59,99,46,84,32,43,12,90,23";


    int arr[100]; 
    int size;

    printf("Enter orders Priority Number:\n");
    printf("%s\n", input1); 
    parse_input(input1, arr, &size);

    qsort(arr, size, sizeof(int), compare);

    printf("\nAfter Sorting Orders Priority:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
