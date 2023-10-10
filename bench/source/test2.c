#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[1000];
    int n = 1000;

    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    bubbleSort(arr, n);

    printf("Bubble sort done\n");

    return 0;
}
