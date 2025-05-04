#include "list.h"
#include <stdio.h>
#include <string.h>

//! NO. 1
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

    //! NO. 2
    infotype firstNewMahasiswa = {24700624706, "Agung Putra"};
    InsertAscending(&Mahasiswa, firstNewMahasiswa);

    //! NO. 3
    infotype secondNewMahasiswa[] = {
        {247006022812, "Helva"},
        {247006022809, "Andreas"},
        {247006022801, "Bram"},
    };

    int secondNewMahasiswaLength = sizeof(secondNewMahasiswa) / sizeof(secondNewMahasiswa[0]);
    for (int i = 0; i < secondNewMahasiswaLength; i++) {
        InsertAscending(&Mahasiswa, secondNewMahasiswa[i]);
    }

    //! NO. 4
    printf("List Mahasiswa \n");
    PrintList(Mahasiswa);
    
    long long searchNim;
    long long deleteNim;

    //! NO. 5
    printf("\nSearch NIM \n");
    printf("input nim = ");
    scanf("%lld", &searchNim);
    getchar();
    FindNameByNIM(Mahasiswa, searchNim);

    //! NO. 6
    printf("\nDelete NIM \n");
    printf("input nim = ");
    scanf("%lld", &deleteNim);
    getchar();
    DeleteByNIM(&Mahasiswa, deleteNim);

    printf("\nList Mahasiswa \n");
    PrintList(Mahasiswa);

    return 0;
}
