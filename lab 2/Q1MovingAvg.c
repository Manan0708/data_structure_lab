#include <stdio.h>

void CMA(int arr[], int size, int n) {
    if (n > size) {
        printf("n cannot be greater than the size of the array\n");
        return;
    }

    double sum = 0;
    
    for (int i = 0; i <= size - n; i++) {
        sum = 0;
        for (int j = i; j < i + n; j++) {
            sum += arr[j];
        }
        printf("Moving Average of window %d to %d: %.2lf\n", i + 1, i + n, sum / n);
    }
}

int main() {
    int size, n;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    
    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the window size for moving average (n): ");
    scanf("%d", &n);

    CMA(arr, size, n);

    return 0;
}