#include <stdio.h>

int selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        int si = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[si]) {
                si = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[si];
        arr[si] = temp;
    }
    return 0;
}



int main() {
    int arr[] = {100,17,1,21,4,23,9,12,18,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    selection(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}