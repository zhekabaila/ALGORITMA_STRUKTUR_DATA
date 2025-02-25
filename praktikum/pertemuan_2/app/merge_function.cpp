
#include <stdio.h>
#include <stdlib.h>

// Menggabungkan dua subarray dari arr[].
// Subarray pertama adalah arr[left..mid]
// Subarray kedua adalah arr[mid+1..right]

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

	// Buat array sementara
    int leftArr[n1], rightArr[n2];

    // Salin data ke array sementara
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Gabungkan kembali array sementara ke arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Salin elemen yang tersisa dari leftArr[], jika ada
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Salin elemen yang tersisa dari rightArr[], jika ada
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Subarray yang akan diurutkan berada dalam rentang indeks [kiri-kanan]]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        // Hitung titik tengah
        int mid = left + (right - left) / 2;

       // Urutkan bagian pertama dan kedua
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan bagian yang telah diurutkan
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
      //panggil fungsi 
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
