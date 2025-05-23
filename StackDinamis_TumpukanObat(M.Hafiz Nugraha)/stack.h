#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED
#include <iostream>

//definisi perintah
#define Nil NULL
#define harga(p) p->harga //ngambil data
#define Obat(p) p->Obat //ngambil data
#define kadaluarsa(p) p->kadaluarsa //ngambil data
#define tumpukan_ke(p) p->tumpukan_ke //ngambil data
#define next(p) p->next //ambil alamat selanjutnya
#define top(L) L.top

using namespace std;
/*
    Type infotype : integer
    Type address  : pointer to ElmList
    Type ElmList <
	Obat : infotype
	next : address																					
    >
    Type List : < First : address >
*/

// definisi untuk data dan pointer address
typedef string infotype; //mendeklarasi tipe data infotype dengan integer
typedef struct ElmList *address; //elemen list disimpan di alamat pointer

// definisi struktur dari element
struct ElmList{ //deklarasi elemen list dengan tipe data struck
    double harga;
    infotype Obat;  //menyimpan data Obat
    string kadaluarsa;
    int tumpukan_ke;

    address next;
};

// definisi list
struct List{
    address top; //sama
    // struct ElmList *top; //menyimpan alamat elemen list pertama 
};

// deklarasi primitif fungsi
void createStack(List &L);
/*  I.S. Sembarang List
    F.S. terbentuk list kosong */

address alokasi(infotype data, string isi, double h, int ke);//membuat elemen baru
/*  I.S. terdefinisi suatu data yang akan dialokasikan ke memori
    F.S. mengaklokasikan P yang menunjuk pada element baru */
// address findElm(List L, infotype x);

void push(List &L, address P);
// void pop(List &L, address P);
// void insertAfter(List &L, address P, address Prec);

void pop(List &L, address &P);
// void delLast(List &L, address &P);
// void delAfter(List &L, address &P, address Prec);
/*  I.S. L sembarang bisa masih kosong atau terisi,
    p alamat element yang telah dialokasikan pada fungsi utama*/
/*  F.S. menempatkan element P awal list*/

void viewList(List L);
// /*  I.S. Sembarang List
//     F.S. menampilkan isi dari list */

void reverseStack(List &L);
void dealokasi(address &P);
/*  I.S. Element P
    F.S. element P dealokasi */
// void reverseStack(List &L); 
//membalikan urutan stack dari bawah ke atas



#endif // SINGLELINKEDLIST_H_INCLUDED
