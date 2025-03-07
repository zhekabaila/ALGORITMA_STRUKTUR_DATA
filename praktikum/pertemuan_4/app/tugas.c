#include <stdio.h>
#include <stdbool.h>

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

      printf("Hasil pengurutan sebagai berikut: \n");
      for(int i = 0; i < arrayLength; i++){
        if (isNumber) {
            printf("%d, ", integerArr[i]);
        } else {
            printf("%c, ", stringArr[i]);
        }
      }
      printf("\n");
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
                case 0:
                    return 0;
            default:
                printf("Pilihan yang anda masukkan salah.\n");
        }
    } while (pilihan != 0);

    return 0;
}
