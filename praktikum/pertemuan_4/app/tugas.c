#include <stdio.h>
#include <stdbool.h>

void printArray(int integerArr[], char stringArr[], int arrayLength, bool isNumber, char methodName[]) {
    printf("\nHasil pengurutan %s sebagai berikut: \n", methodName);
    printf("[");
      for(int i = 0; i < arrayLength; i++){
        printf(isNumber ? "%d" : "%c", isNumber ? integerArr[i] : stringArr[i]);
        if (i < arrayLength - 1) printf(", ");
      }
      printf("]\n");
      printf("\n");
}

void menu () {
    printf("+-------------------------------------------+\n");
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

void bubbleSort(int integerArr[], char stringArr[], int arrayLength, bool isNumber, bool isAscending){

    for(int i = 0; i < arrayLength; i++){
        for(int j = 0; j < arrayLength - i - 1; j++){
            if (isNumber == 1) {
                if(isAscending == 1 ? (integerArr[j] > integerArr[j + 1]) : integerArr[j] < integerArr[j + 1]){
                    int numberTmp = integerArr[j];
                    integerArr[j] = integerArr[j + 1];
                    integerArr[j + 1] = numberTmp;
                }
            } else {
                if(isAscending == 1 ? (stringArr[j] > stringArr[j + 1]) : stringArr[j] < stringArr[j + 1]){
                    char stringTmp = stringArr[j];
                    stringArr[j] = stringArr[j + 1];
                    stringArr[j + 1] = stringTmp;
                }
            }
        }
      }

      printArray(integerArr, stringArr, arrayLength, isNumber, "Bubble Sort");
}

void insertionSort(int integerArr[], char stringArr[], int arrayLength, bool isNumber, bool isAscending){
    for(int i = 1; i < arrayLength; i++){
        if (isNumber == 1){
            for (int j = i; j > 0 && isAscending == 1 ? integerArr[j]<integerArr[j-1]: integerArr[j]>integerArr[j-1]; j--){
                //lakukan swap value
                int temp=integerArr[j-1];
                integerArr[j-1]=integerArr[j];
                integerArr[j]=temp;
            }
        } else {
            for (int j = i; j > 0 && isAscending == 1? stringArr[j]<stringArr[j-1]: stringArr[j]<stringArr[j-1]; j--){
                //lakukan swap value
                char temp=stringArr[j-1];
                stringArr[j-1]=stringArr[j];
                stringArr[j]=temp;
            }
        }
	}

     printArray(integerArr, stringArr, arrayLength, isNumber, "Insertion Sort");
}

void merge(int integerArr[], char stringArr[], int left, int mid, int right, bool isNumber, bool isAscending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    if (isNumber) {
        int leftArr[n1], rightArr[n2];

        // Salin data ke array sementara
        for (i = 0; i < n1; i++)
            leftArr[i] = integerArr[left + i];
        for (j = 0; j < n2; j++)
            rightArr[j] = integerArr[mid + 1 + j];

        // Gabungkan kembali array sementara ke integerArr[left..right]
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (isAscending ? (leftArr[i] <= rightArr[j]) : (leftArr[i] >= rightArr[j])) {
                integerArr[k] = leftArr[i];
                i++;
            } else {
                integerArr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Salin elemen yang tersisa
        while (i < n1) {
            integerArr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            integerArr[k] = rightArr[j];
            j++;
            k++;
        }
    } else {
        char leftArr[n1], rightArr[n2];

        // Salin data ke array sementara untuk huruf
        for (i = 0; i < n1; i++)
            leftArr[i] = stringArr[left + i];
        for (j = 0; j < n2; j++)
            rightArr[j] = stringArr[mid + 1 + j];

        // Gabungkan kembali array sementara ke stringArr[left..right]
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (isAscending ? (leftArr[i] <= rightArr[j]) : (leftArr[i] >= rightArr[j])) {
                stringArr[k] = leftArr[i];
                i++;
            } else {
                stringArr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Salin elemen yang tersisa
        while (i < n1) {
            stringArr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            stringArr[k] = rightArr[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int integerArr[], char stringArr[], int left, int right, bool isNumber, bool isAscending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(integerArr, stringArr, left, mid, isNumber, isAscending);
        mergeSort(integerArr, stringArr, mid + 1, right, isNumber, isAscending);

        merge(integerArr, stringArr, left, mid, right, isNumber, isAscending);
    }
}

void swap(void* a, void* b, bool isNumber) {
    if (isNumber) {
        int temp = *(int*)a;
        *(int*)a = *(int*)b;
        *(int*)b = temp;
    } else {
        char temp = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = temp;
    }
}

int partition(void* arr, int low, int high, bool isNumber, bool isAscending) {
    if (isNumber) {
        int* intArr = (int*)arr;
        int pivot = intArr[high];  
        int i = low - 1;  

        for (int j = low; j < high; j++) {
            if (isAscending ? (intArr[j] < pivot) : (intArr[j] > pivot)) {
                i++;
                swap(&intArr[i], &intArr[j], isNumber);
            }
        }
        swap(&intArr[i + 1], &intArr[high], isNumber);
        return i + 1;
    } else {
        char* charArr = (char*)arr;
        char pivot = charArr[high];  
        int i = low - 1;  

        for (int j = low; j < high; j++) {
            if (isAscending ? (charArr[j] < pivot) : (charArr[j] > pivot)) {
                i++;
                swap(&charArr[i], &charArr[j], isNumber);
            }
        }
        swap(&charArr[i + 1], &charArr[high], isNumber);
        return i + 1;
    }
}

void quickSort(void* arr, int low, int high, bool isNumber, bool isAscending) {
    if (low < high) {
        int pi = partition(arr, low, high, isNumber, isAscending);

        quickSort(arr, low, pi - 1, isNumber, isAscending);
        quickSort(arr, pi + 1, high, isNumber, isAscending);
    }
}

void selectionSort(int integerArr[],char stringArr[], int n, bool isNumber, bool Ascending){
  int i, j, posisi, swap;
  for(i = 0; i < (n-1); i++){
    posisi = i;
    for (j = i + 1; j < n; j++){
        if (isNumber == 1){
            if(Ascending == 1 ? integerArr[posisi] > integerArr[j] : integerArr[posisi] < integerArr[j]){
        posisi = j;
      }
        }else {
            if(Ascending == 1 ? stringArr[posisi] > stringArr[j] : stringArr[posisi] < stringArr[j]){
        posisi = j;
      }
        }
    }
    if(posisi != i){
        if (isNumber == 1){
            swap = integerArr[i];
      integerArr[i] = integerArr[posisi];
      integerArr[posisi] = swap;
      }else{
        swap = stringArr[i];
      stringArr[i] = stringArr[posisi];
      stringArr[posisi] = swap;

        }
    }
  }
  printArray(integerArr, stringArr, n, isNumber, "Insertion Sort");
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
                printArray(integerArr, stringArr, arrayLength, isNumber == 'y', "Merge Sort");
                break;
            case 4:
                if (isNumber == 'y') {
                    quickSort(integerArr, 0, arrayLength-1, isNumber == 'y', isAscending == 'y');
                } else {
                    quickSort(stringArr, 0, arrayLength-1, isNumber == 'y', isAscending == 'y');
                }
                printArray(integerArr, stringArr, arrayLength, isNumber == 'y', "Quick Sort");
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