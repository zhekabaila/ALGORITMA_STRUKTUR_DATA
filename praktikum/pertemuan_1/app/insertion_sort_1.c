#include <stdio.h>

//inisialisasi data

int main(){
  int angka[100], angka_sebelum[100], n;

  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan nilai: \n");

  for(int i = 0; i < n; i++){
    scanf("%d", &angka[i]);
    angka_sebelum[i] = angka[i];
  }


  //looping sebanyak jumlah data-1
	for(int i=1; i<n; i++){
		//looping selama angka ke-j (j sudah di set sebagai i di awal)
		//lebih kecil dari j-1
		for(int j=i; j>0 && angka[j]<angka[j-1]; j--){
			//lakukan swap value
			int temp=angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
		}
	}

	//cetak data
  printf("Sebelum: ");
	for(int i=0; i<n; i++){
		printf("%d ", angka_sebelum[i]);
	}
  printf("\n");

  printf("Sesudah: ");
	for(int i=0; i<n; i++){
		printf("%d ", angka[i]);
	}
  printf("\n");
  
	getchar();
}