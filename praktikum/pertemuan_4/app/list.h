#ifndef LIST_H
#define LIST_H

#include <stdbool.h> // untuk bool
#include <stdlib.h>
#include <string.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

/* Tipe data Mahasiswa */
typedef struct {
    long long nim;
    char nama[50];
} infotype;

/* Address adalah pointer ke elemen list */
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

/* Definisi list */
typedef struct {
    address First;
} List;

/* Prototype Fungsi */
bool IsEmpty(List *L);
void CreateList(List *L);
address Alokasi(infotype X);
void Dealokasi(address P);
address Search(List L, long long nim);
bool FSearch(List L, address P);
address SearchPrec(List L, long long nim, address *Prec);
void InsertAscending(List *L, infotype X);
void PrintList(List L);
void FindNameByNIM(List L, long long nim);
void DeleteByNIM(List *L, long long nim);

#endif
