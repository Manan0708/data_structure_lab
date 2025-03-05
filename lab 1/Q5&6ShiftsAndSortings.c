#include <stdio.h>

int main() {
    int n,temp, i;

    printf("Enter the size of the array:  ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int j = a[0];
    for (i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = j;

    printf("Array after left shift:  ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
        
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nThe array after sorting in increasing order is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    for (i = 0; i < n-1; i ++) { 
        for (j = 0 ; j < n-1-i; j ++) {  
            if (j%2!=0  && a[j] > a[j+2]) {
                temp = a[j];
                a[j] = a[j+2];
                a[j+2] = temp;
            }
        }
    }
    printf("\nThe array after sorting the elements at odd indices is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }


    return 0;
}