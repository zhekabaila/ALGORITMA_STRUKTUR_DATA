#include <stdio.h>

void bubbleSort(char arr[], int length, bool ascending = true) {
    char newArr[length];
    for (int i = 0; i < length; i++)
    {
        newArr[i] = arr[i];
    }
    
    for (int i = 0; i < length; i++) {
        printf("\n");
        if (i < length - 1) {
            printf("Bubble %d: \n", i + 1);
        }
        for (int j = 0; j < length - i - 1; j++)
        {
            printf("[");
            for (int k = 0; k < length; k++)
            {
              printf("%c", arr[k]);
              if (k < length - 1) {
                printf(", ");
              }
            }
            printf("]\n");
            switch (ascending)
            {
            case true:
                if (arr[j] > arr[j + 1])
                {
                    char temporary_char = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temporary_char;
                }
                break;
            case false:
                if (arr[j] < arr[j + 1])
                {
                    char temporary_char = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temporary_char;
                }
                break;
            }
        }
    }
    if (ascending)
    {
        printf("Huruf setelah disorting ASC: \n");
    } else {
        printf("Huruf setelah disorting DESC: \n");
    }
    
    printf("[");
    for (int k = 0; k < length; k++)
    {
      printf("%c", arr[k]);
      if (k < length - 1) {
        printf(", ");
      }
    }
    printf("]\n");
    
    printf("\n");
    printf("\n");
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        arr[i] = newArr[i];
    }
}

int main() {
    char huruf_sebelum_sort[100], huruf[100];
    int length;

    printf("Masukan jumlah huruf: ");
    scanf("%d", &length);
    getchar();

    printf("Masukan huruf yang akan disorting: \n");
    for (int i = 0; i < length; i++) {
        printf("Huruf ke-%d: ", i + 1);
        scanf("%s", &huruf[i]);
        getchar();
        huruf_sebelum_sort[i] = huruf[i];
    }
    printf("\n");
    
    printf("\n");
    printf("Huruf sebelum disorting:\n");
    for (int i = 0; i < length; i++) {
        printf("%c ", huruf_sebelum_sort[i]);
    }
    printf("\n");
    printf("\n");
    
    bubbleSort(huruf, length, true);
    bubbleSort(huruf, length, false);

    return 0;
}