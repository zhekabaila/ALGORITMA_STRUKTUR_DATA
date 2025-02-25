
#include <stdio.h>
#include <stdlib.h>

int sequential(int arr[], int length, int value) {
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value) {
            return i;
        }
    }
}

int main() {
    int angka[] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int length = sizeof(angka) / sizeof(angka[0]);
    int search = 9;
    
    int value = sequential(angka, length, search);
    
    if (value) {
        printf("%d ditemukan pada indeks ke-%d.\n", search, value);
    } else {
        printf("nilai tidak ditemukan pada array\n");
    }
    
    return 0;
}
