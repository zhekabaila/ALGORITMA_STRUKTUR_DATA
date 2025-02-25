#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int arr[] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    bubbleSort(arr, size);
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if (result != -1) {
        printf("Angka %d ditemukan pada indeks %d setelah pengurutan.\n", target, result);
    } else {
        printf("Angka %d tidak ditemukan dalam array.\n", target);
    }
    
    return 0;
}
