#include <stdio.h>

//inisialisasi array angka sebanyak 15 data
int angka[]={7,7,4,6,8,2,5,9,4,5,3,1,1,7,8};

//fungsi bubble sort ascending
void bubbleSortAsc(){
	//mengulang sebanyak 14 kali sebanyak n-1 data
	for(int i=0; i<15-1; i++){
		for(int j=0; j<15-1; j++){
			//jika angka index x+1 lebih kecil dari angka index x
			if(angka[j+1]<angka[j]){
				//tampung angka index x ke temp
				int temp=angka[j];
				//ubah angka index x menjadi angka index x+1
				angka[j]=angka[j+1];
				//ubah angka index x+1 menjadi angka temp
				angka[j+1]=temp;
			}
		}
	}
}

void bubbleSortDesc(){
	//mengulang sebanyak 14 kali sebanyak n-1 data
	for(int i=0; i<15-1; i++){
		for(int j=0; j<15-1; j++){
			//jika angka index x+1 lebih besar dari angka index x
			if(angka[j+1]>angka[j]){
				//tampung angka index x ke temp
				int temp=angka[j];
				//ubah angka index x menjadi angka index x+1
				angka[j]=angka[j+1];
				//ubah angka index x+1 menjadi angka temp
				angka[j+1]=temp;
			}
		}
	}
}

int main(){
	printf("Sebelum Sorting : \n");
	for(int i=0; i<15; i++){
		printf("%d ", angka[i]);
	}
	bubbleSortAsc();
	printf("\n\nSetelah Sorting Ascending : \n");
	for(int i=0; i<15; i++){
		printf("%d ", angka[i]);
	}
	bubbleSortDesc();
	printf("\n\nSetelah Sorting Descending : \n");
	for(int i=0; i<15; i++){
		printf("%d ", angka[i]);
	}
	getchar();
	return 0;
}