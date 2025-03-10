#include <stdio.h>
#include <stdbool.h>

void printArray(int integerArr[], char stringArr[], int arrayLength, bool isNumber) {
    printf("[");
    for (int i = 0; i < arrayLength; i++) {
        if (isNumber) {
            printf("%d", integerArr[i]);
        } else {
            printf("%c", stringArr[i]);
        }
        if (i < arrayLength - 1) printf(", ");
    }
    printf("]");
    printf("\n");
}

void printQuickSort(void* arr, int size, bool isNumber) {
    printf("[");
    if (isNumber) {
        int* intArr = (int*)arr;
        for (int i = 0; i < size; i++) {
            printf("%d", intArr[i]);
            if (i < size - 1) printf(", ");
        }
    } else {
        char* charArr = (char*)arr;
        for (int i = 0; i < size; i++) {
            printf("%c", charArr[i]);
            if (i < size - 1) printf(", ");
        }
    }
    printf("]");
    printf("\n");
}

void menu () {
    printf("\n+-------------------------------------------+\n");
    printf("|            Pilih Metode Sorting           |\n");
    printf("+-------------------------------------------+\n");
    printf("| [1] Bubble Sort                           |\n");
    printf("| [2] Insertion Sort                        |\n");
    printf("| [3] Merge Fungsi                          |\n");
    printf("| [4] Quick Fungsi                          |\n");
    printf("| [5] Selection Fungsi                      |\n");
    printf("| [0] Keluar                                |\n");
    printf("+-------------------------------------------+\n");
}

void bubbleSort(int integerArr[], char stringArr[], int arrayLength, bool isNumber, bool isAscending) {
    printf("\nProses Sorting:\n");
    for (int i = 0; i < arrayLength - 1; i++) {
        printf("Bubble ke-%d:\n", i + 1);
        bool swapped = false;  // Untuk mendeteksi apakah terjadi pertukaran dalam iterasi ini
        
        for (int j = 0; j < arrayLength - i - 1; j++) {
            if (isNumber) {
                if ((isAscending && integerArr[j] > integerArr[j + 1]) || 
                    (!isAscending && integerArr[j] < integerArr[j + 1])) {
                    
                    // Swap angka
                    int temp = integerArr[j];
                    integerArr[j] = integerArr[j + 1];
                    integerArr[j + 1] = temp;
                    swapped = true;

                    // Menampilkan array setelah pertukaran
                    printArray(integerArr, stringArr, arrayLength, isNumber);
                }
            } else {
                if ((isAscending && stringArr[j] > stringArr[j + 1]) || 
                    (!isAscending && stringArr[j] < stringArr[j + 1])) {
                    
                    // Swap huruf
                    char temp = stringArr[j];
                    stringArr[j] = stringArr[j + 1];
                    stringArr[j + 1] = temp;
                    swapped = true;

                    // Menampilkan array setelah pertukaran
                    printArray(integerArr, stringArr, arrayLength, isNumber);
                }
            }
        }

        // Jika dalam satu iterasi tidak ada perubahan, berarti array sudah terurut
        if (!swapped) {
            printf("Array sudah terurut, menghentikan proses lebih awal.\n");
            break;
        }
    }

    // Menampilkan hasil akhir
    printf("\nHasil Akhir Setelah Bubble Sort:\n");
    printArray(integerArr, stringArr, arrayLength, isNumber);
}

void insertionSort(int integerArr[], char stringArr[], int arrayLength, bool isNumber, bool isAscending) {
    printf("\nProses Sorting:\n");
    
    for (int i = 1; i < arrayLength; i++) {
        if (isNumber) {
            int key = integerArr[i];
            int j = i - 1;

            printf("Iterasi ke-%d: Menyisipkan %d\n", i, key);

            // Geser elemen ke kanan untuk memberi ruang bagi elemen yang akan disisipkan
            while (j >= 0 && (isAscending ? integerArr[j] > key : integerArr[j] < key)) {
                integerArr[j + 1] = integerArr[j];
                j--;
                
                // Menampilkan array setelah pergeseran
                printArray(integerArr, stringArr, arrayLength, isNumber);
            }

            integerArr[j + 1] = key;

        } else {
            char key = stringArr[i];
            int j = i - 1;

            printf("Iterasi ke-%d: Menyisipkan %c\n", i, key);

            // Geser elemen ke kanan untuk memberi ruang bagi elemen yang akan disisipkan
            while (j >= 0 && (isAscending ? stringArr[j] > key : stringArr[j] < key)) {
                stringArr[j + 1] = stringArr[j];
                j--;

                // Menampilkan array setelah pergeseran
                printArray(integerArr, stringArr, arrayLength, isNumber);
            }

            stringArr[j + 1] = key;
        }

        // Menampilkan array setelah satu iterasi selesai
        printf("Setelah Iterasi ke-%d:\n", i);
        printArray(integerArr, stringArr, arrayLength, isNumber);
    }

    // Menampilkan hasil akhir
    printf("\nHasil Akhir Setelah Insertion Sort:\n");
    printArray(integerArr, stringArr, arrayLength, isNumber);
}

void merge(int integerArr[], char stringArr[], int left, int mid, int right, bool isNumber, bool isAscending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    printf("\nMenggabungkan: ");
    printf("[");
    for (int i = left; i <= right; i++) {
        if (isNumber) {
            printf("%d", integerArr[i]);
        } else {
            printf("%c", stringArr[i]);
        }
        if (i < (right + 1) - 1) printf(", ");
    }
    printf("]");
    printf("\n");


    if (isNumber) {
        int leftArr[n1], rightArr[n2];

        // Salin data ke array sementara
        for (i = 0; i < n1; i++) leftArr[i] = integerArr[left + i];
        for (j = 0; j < n2; j++) rightArr[j] = integerArr[mid + 1 + j];

        // Menggabungkan kembali array sementara ke integerArr
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (isAscending ? (leftArr[i] <= rightArr[j]) : (leftArr[i] >= rightArr[j])) {
                integerArr[k] = leftArr[i++];
            } else {
                integerArr[k] = rightArr[j++];
            }
            k++;
        }

        // Salin sisa elemen
        while (i < n1) integerArr[k++] = leftArr[i++];
        while (j < n2) integerArr[k++] = rightArr[j++];

    } else {
        char leftArr[n1], rightArr[n2];

        // Salin data ke array sementara untuk huruf
        for (i = 0; i < n1; i++) leftArr[i] = stringArr[left + i];
        for (j = 0; j < n2; j++) rightArr[j] = stringArr[mid + 1 + j];

        // Menggabungkan kembali array sementara ke stringArr
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (isAscending ? (leftArr[i] <= rightArr[j]) : (leftArr[i] >= rightArr[j])) {
                stringArr[k] = leftArr[i++];
            } else {
                stringArr[k] = rightArr[j++];
            }
            k++;
        }

        // Salin sisa elemen
        while (i < n1) stringArr[k++] = leftArr[i++];
        while (j < n2) stringArr[k++] = rightArr[j++];
    }

    printf("Setelah Merge: ");
    printf("[");
    for (int i = left; i <= right; i++) {
        if (isNumber) {
            printf("%d", integerArr[i]);
        } else {
            printf("%c", stringArr[i]);
        }
        if (i < (right + 1) - 1) printf(", ");
    }
    printf("]");
    printf("\n");

}

// Fungsi rekursif Merge Sort
void mergeSort(int integerArr[], char stringArr[], int left, int right, bool isNumber, bool isAscending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        printf("\nMembagi: ");
        printf("[");
        for (int i = left; i <= right; i++) {
            if (isNumber) {
                printf("%d", integerArr[i]);
            } else {
                printf("%c", stringArr[i]);
            }
            if (i < (right + 1) - 1) printf(", ");
        }
        printf("]");
        printf("\n");
    

        mergeSort(integerArr, stringArr, left, mid, isNumber, isAscending);
        mergeSort(integerArr, stringArr, mid + 1, right, isNumber, isAscending);

        merge(integerArr, stringArr, left, mid, right, isNumber, isAscending);
    }
}

void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapChar(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}


// Fungsi partition untuk QuickSort
int partition(void* arr, int low, int high, bool isNumber, bool isAscending) {
    if (isNumber) {
        int* intArr = (int*)arr;
        int pivot = intArr[high];  
        int i = low - 1;  

        printf("\nPartitioning: \n");
        printQuickSort(arr, high + 1, isNumber);
        
        for (int j = low; j < high; j++) {
            if (isAscending ? (intArr[j] < pivot) : (intArr[j] > pivot)) {
                i++;
                swapInt(&intArr[i], &intArr[j]);
                printQuickSort(arr, high + 1, isNumber);
            }
        }
        swapInt(&intArr[i + 1], &intArr[high]);
        printQuickSort(arr, high + 1, isNumber);
        return i + 1;
    } else {
        char* charArr = (char*)arr;
        char pivot = charArr[high];  
        int i = low - 1;  

        printf("\nPartitioning: ");
        printQuickSort(arr, high + 1, isNumber);
        
        for (int j = low; j < high; j++) {
            if (isAscending ? (charArr[j] < pivot) : (charArr[j] > pivot)) {
                i++;
                swapChar(&charArr[i], &charArr[j]);
                printQuickSort(arr, high + 1, isNumber);
            }
        }
        swapChar(&charArr[i + 1], &charArr[high]);
        printQuickSort(arr, high + 1, isNumber);
        return i + 1;
    }
}

// Fungsi rekursif QuickSort
void quickSort(void* arr, int low, int high, bool isNumber, bool isAscending) {
    if (low < high) {
        int pi = partition(arr, low, high, isNumber, isAscending);
        printf("\nPivot: %d\n", pi);

        quickSort(arr, low, pi - 1, isNumber, isAscending);
        quickSort(arr, pi + 1, high, isNumber, isAscending);
    }
}

void selectionSort(int integerArr[], char stringArr[], int n, bool isNumber, bool Ascending) {
    int i, j, posisi;
    for (i = 0; i < (n - 1); i++) {
        posisi = i;
        for (j = i + 1; j < n; j++) {
            if (isNumber) {
                if (Ascending ? integerArr[posisi] > integerArr[j] : integerArr[posisi] < integerArr[j]) {
                    posisi = j;
                }
            } else {
                if (Ascending ? stringArr[posisi] > stringArr[j] : stringArr[posisi] < stringArr[j]) {
                    posisi = j;
                }
            }
        }
        if (posisi != i) {
            if (isNumber) {
                int temp = integerArr[i];
                integerArr[i] = integerArr[posisi];
                integerArr[posisi] = temp;
            } else {
                char temp = stringArr[i];
                stringArr[i] = stringArr[posisi];
                stringArr[posisi] = temp;
            }
        }

        // Menampilkan proses sorting di setiap iterasi
        printf("Iterasi %d: ", i + 1);
        printArray(integerArr, stringArr, n, isNumber);
    }

    printf("\nHasil Akhir Setelah Selection Sort:\n");
    printArray(integerArr, stringArr, n, isNumber);
}

int main() {
    int pilihan;

    do {
        int integerArr[100];
        char stringArr[100];

        char isAscending;
        char isNumber;
        int arrayLength;

        menu();

        printf("Pilih menu yang ingin dipilih (1-5) > ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 0) return 0;
        
        printf("Apakah anda ingin mengurutkan secara ascending? (y/t) > ");
        scanf("%c", &isAscending);
        getchar();

        printf("Apakah anda ingin menyorting angka? (y/t) > ");
        scanf("%c", &isNumber);
        getchar();

        printf("Masukan panjang array > ");
        scanf("%d", &arrayLength);
        getchar();
        
        for (int i = 0; i < arrayLength; i++) {
            printf("Index ke-%d > ", i);
            if (isNumber == 'y') {
                scanf("%d", &integerArr[i]);
            } else {
                scanf(" %c", &stringArr[i]);  // Spasi sebelum %c agar scanf mengabaikan newline sebelumnya
            }
            getchar();
        }
        

        switch (pilihan) {
            case 1:
                bubbleSort(integerArr, stringArr, arrayLength, isNumber == 'y', isAscending == 'y');
                break;
            case 2:
                insertionSort(integerArr, stringArr, arrayLength, isNumber == 'y', isAscending == 'y');
                break;
            case 3:
                mergeSort(integerArr, stringArr, 0 , arrayLength - 1, isNumber == 'y', isAscending == 'y');
                printf("\nHasil Akhir Setelah Merge Sort:\n");
                printf("[");
                for (int i = 0; i <= arrayLength; i++) {
                    if (isNumber == 'y') {
                        printf("%d", integerArr[i]);
                    } else {
                        printf("%c", stringArr[i]);
                    }
                    if (i < (arrayLength) - 1) printf(", ");
                }
                printf("]\n");
                break;
            case 4:
                if (isNumber == 'y') {
                    quickSort(integerArr, 0, arrayLength-1, isNumber == 'y', isAscending == 'y');
                } else {
                    quickSort(stringArr, 0, arrayLength-1, isNumber == 'y', isAscending == 'y');
                }
                printf("\nHasil Akhir Setelah Quick Sort:\n");printf("[");
                for (int i = 0; i <= arrayLength; i++) {
                    if (isNumber == 'y') {
                        printf("%d", integerArr[i]);
                    } else {
                        printf("%c", stringArr[i]);
                    }
                    if (i < (arrayLength) - 1) printf(", ");
                }
                printf("]");
                printf("\n");
                break;
            case 5:
                selectionSort(integerArr, stringArr, arrayLength, isNumber == 'y', isAscending == 'y'); 
                break;
            case 0:
                    return 0;
            default:
                printf("Pilihan yang anda masukkan salah.\n");
        }
    } while (pilihan != 0);

    return 0;
}