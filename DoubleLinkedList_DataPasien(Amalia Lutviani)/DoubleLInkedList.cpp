#include "DoubleLinkedList.h"

void createList(List &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address alokasi(infotype data) {
    address P = new ElmList;
    info(P) = data;
    next(P) = Nil;
    prev(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (first(L) == Nil) {
        first(L) = last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    if (first(L) == Nil) {
        insertFirst(L, P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertBefore(List &L, address P, address Succ) {
    if (Succ == first(L)) {
        insertFirst(L, P);
    } else {
        address Prec = prev(Succ);
        next(Prec) = P;
        prev(P) = Prec;
        next(P) = Succ;
        prev(Succ) = P;
    }
}

void delFirst(List &L, address &P) {
    P = first(L);
    if (next(P) == Nil) {
        first(L) = last(L) = Nil;
    } else {
        first(L) = next(P);
        prev(first(L)) = Nil;
        next(P) = Nil;
    }
}

void delLast(List &L, address &P) {
    P = last(L);
    if (first(L) == last(L)) {
        first(L) = last(L) = Nil;
    } else {
        last(L) = prev(P);
        next(last(L)) = Nil;
        prev(P) = Nil;
    }
}

void delBefore(List &L, address &P, address Succ) {
    P = prev(Succ);
    if (P != Nil) {
        if (P == first(L)) {
            delFirst(L, P);
        } else {
            address Prec = prev(P);
            next(Prec) = Succ;
            prev(Succ) = Prec;
            next(P) = Nil;
            prev(P) = Nil;
        }
    }
}

address findByNIK(List L, string nik) {
    address P = first(L);
    while (P != Nil) {
        if (info(P).nik == nik)
            return P;
        P = next(P);
    }
    return Nil;
}

void viewList(List L) {
    if (first(L) == Nil) {
        cout << "Data pasien kosong.\n";
        return;
    }
    cout << "\n=== Daftar Pasien ===\n";
    address P = first(L);
    while (P != Nil) {
        cout << "- NIK: " << info(P).nik
             << ", Nama: " << info(P).nama
             << ", Usia: " << info(P).usia
             << ", Diagnosa: " << info(P).diagnosa << endl;
        P = next(P);
    }
}