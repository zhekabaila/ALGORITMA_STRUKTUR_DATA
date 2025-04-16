#include <stdio.h>

int main() {
    char huruf[36];
    
    for (int i = 0; i < 26; i++) {
        huruf[i] = 'a' + i;
    }

    for (int i = 0; i < 10; i++) {
        huruf[26 + i] = '0' + i;
    }

    char pita[] = {'a', 'k', 'u', ' ', 'i', 'n', 'i', ' ', 'p', 'i', 'n', 't', 'a', 'r', '.'};
    // char pita[] = {'z', ' ', ' ', 'b', 'b', 'b', '.'};
    // char pita[] = {'.'};
    // char pita[] = {' ', ' ', ' ', ' ', ' ', ' ', '.'};
    // char pita[] = {' ', ' ', 's', 'i', 's', 'f', 'o', 'r', '3', '.'};

    int panjangPita = sizeof(pita) / sizeof(pita[0]);
    int globalTotal = 0;

    for (int i = 0; i < 36; i++)
    {
        int totalHuruf = 0;
        int posisiHuruf[panjangPita];
        for (int j = 0; j < panjangPita; j++)
        {
            if (huruf[i] == pita[j]) {
                posisiHuruf[totalHuruf] = j + 1;
                totalHuruf += 1;
                globalTotal += 1;
            }
        }
        if (totalHuruf > 0) {
            printf("%c:\n", huruf[i]);
            for (int k = 0; k < totalHuruf; k++) {
                printf("%d \n", posisiHuruf[k]);
            }
            printf("Muncul %d kali", totalHuruf);
            printf("\n\n");
        }
    }

    if (globalTotal < 1 && panjangPita < 2) {
        printf("Pita kosong, tidak ada isinya\n");
    }
    
    return 0;
}