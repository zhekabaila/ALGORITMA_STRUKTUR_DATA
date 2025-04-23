#include "list.h"
#include <stdio.h>
#include <string.h>

bool IsEmpty(List *L) {
    return First(*L) == Nil;
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, long long nim) {
    address P = First(L);
    while (P != Nil) {
        if (info(P).nim == nim)
            return P;
        P = next(P);
    }
    return Nil;
}

bool FSearch(List L, address P) {
    address Q = First(L);
    while (Q != Nil) {
        if (Q == P)
            return true;
        Q = next(Q);
    }
    return false;
}

address SearchPrec(List L, long long nim, address *Prec) {
    *Prec = Nil;
    address P = First(L);
    while (P != Nil && info(P).nim != nim) {
        *Prec = P;
        P = next(P);
    }
    return P;
}

void InsertAscending(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(L) || info(First(*L)).nim > X.nim) {
            next(P) = First(*L);
            First(*L) = P;
        } else {
            address Q = First(*L);
            while (next(Q) != Nil && info(next(Q)).nim < X.nim) {
                Q = next(Q);
            }
            next(P) = next(Q);
            next(Q) = P;
        }
    }
}

void PrintList(List L) {
    if (IsEmpty(&L)) {
        printf("Data kosong\n");
        return;
    }
    
    address P = First(L);
    while (P != Nil) {
        printf("NIM: %lld, Nama: %s\n", info(P).nim, info(P).nama);
        P = next(P);
    }
}

void FindNameByNIM(List L, long long nim) {
    address P = Search(L, nim);
    if (P != Nil) {
        printf("Nama dengan NIM %lld: %s\n", nim, info(P).nama);
    } else {
        printf("NIM %lld tidak ditemukan dalam data\n", nim);
    }
}

void DeleteByNIM(List *L, long long nim) {
    address P, Prec;
    P = SearchPrec(*L, nim, &Prec);
    if (P != Nil) {
        if (Prec == Nil) { // elemen pertama
            First(*L) = next(P);
        } else {
            next(Prec) = next(P);
        }
        Dealokasi(P);
    }
}

int main() {
    List Mahasiswa;
    CreateList(&Mahasiswa);

    bool isRunning = true;

    while (isRunning) {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus Mahasiswa\n");
        printf("3. Cari Mahasiswa\n");
        printf("4. Tampilkan Semua Mahasiswa\n");
        printf("5. Keluar\n");

        int choice;
        printf("Pilih menu: ");
        scanf("%d", &choice);

        infotype newMahasiswa;
        long long deleteNim;
        long long searchNim;

        switch (choice) {
            case 1: 
                printf("Masukkan NIM: ");
                scanf("%lld", &newMahasiswa.nim);
                getchar();

                printf("Masukkan Nama: ");
                fgets(newMahasiswa.nama, sizeof(newMahasiswa.nama), stdin);
                newMahasiswa.nama[strlen(newMahasiswa.nama) - 1] = '\0';

                InsertAscending(&Mahasiswa, newMahasiswa);
                break;
            case 2:
                printf("Masukkan NIM: ");
                scanf("%lld", &deleteNim);
                getchar();

                if (IsEmpty(&Mahasiswa)) {
                    printf("Data kosong, tidak ada yang dapat dihapus\n");
                } else {
                    DeleteByNIM(&Mahasiswa, deleteNim);
                    printf("Data berhasil dihapus\n");
                }
                break;
            case 3:
                printf("Masukkan NIM: ");   
                scanf("%lld", &searchNim);
                getchar();

                if (IsEmpty(&Mahasiswa)) {
                    printf("Data kosong, tidak ada yang dapat dicari\n");
                } else {
                    FindNameByNIM(Mahasiswa, searchNim);
                }
                break;
            case 4:
                PrintList(Mahasiswa);
                break;
            case 5:
                isRunning = false;
        }
    }
    return 0;
}
