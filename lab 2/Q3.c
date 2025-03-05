#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int number;
    int frequency;
} Frequency;

void sortByFrequency(Frequency freq[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (freq[i].frequency < freq[j].frequency) {
            
                Frequency temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }
}

void findFrequencyAndSort(int arr[], int size) {
    Frequency freq[MAX_SIZE];
    int freqCount = 0;

    
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < freqCount; j++) {
            if (freq[j].number == arr[i]) {
                freq[j].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            freq[freqCount].number = arr[i];
            freq[freqCount].frequency = 1;
            freqCount++;
        }
    }

    sortByFrequency(freq, freqCount);

  
    printf("Sorted numbers by frequency:\n");
    for (int i = 0; i < freqCount; i++) {
        for (int j = 0; j < freq[i].frequency; j++) {
            printf("%d ", freq[i].number);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 5, 1, 1, 3, 3, 4, 5, 6, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    findFrequencyAndSort(arr, size);

    return 0;
}