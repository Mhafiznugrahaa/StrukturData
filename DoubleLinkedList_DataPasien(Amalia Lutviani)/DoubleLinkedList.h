#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(p) p->info
#define next(p) p->next
#define prev(p) p->prev
#define first(L) L.first
#define last(L) L.last

// Struktur data pasien
struct Pasien {
    string nik;
    string nama;
    int usia;
    string diagnosa;
};

typedef Pasien infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Primitif dasar
void createList(List &L);
address alokasi(infotype data);
void dealokasi(address &P);

// Operasi insert
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertBefore(List &L, address P, address Succ);

// Operasi delete
void delFirst(List &L, address &P);
void delLast(List &L, address &P);
void delBefore(List &L, address &P, address Succ);

// Operasi pencarian dan tampil
address findByNIK(List L, string nik);
void viewList(List L);

#endif