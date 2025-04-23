#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
    List L;
    CreateList(&L);
    
    // Membuat data mahasiswa
    Mahasiswa mhs;
    mhs.nim = 24700624706;
    strcpy(mhs.nama, "Agung Putra");
    
    // Menambahkan data mahasiswa ke linked list
    InsVFirst(&L, mhs);
    
    // Menampilkan isi linked list
    printf("Isi Linked List:\n");
    PrintInfo(L);
    
    return 0;
}