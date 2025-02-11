// nama file : Alstruk_BubleSort1

#include <stdio.h>

void bubbleSort(int arr[], int n){
  int i, j, tmp;
  printf("\n");
  for(i = 0; i < n; i++){
    printf("\n");
    for(j=0; j < n-i-1; j ++){
      for (int k = 0; k < n; k++)
      {
        printf("%d, ", arr[k]);
      }
      printf("\n");
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
  printf("\n");
}

int main() {
  int array[100], n, i, j;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan nilai: \n");

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }

  bubbleSort(array, n);

  printf("Hasil pengurutan sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}