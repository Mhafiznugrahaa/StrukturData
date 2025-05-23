#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

int pilihan;

const int SIZE = 31;
struct pasien{
    int id;
    string nama;
    int umur;
    string keluhan;
    string alamat;
};

// Kalau kamu tidak pakai extern di header dan coba deklarasi data[SIZE] langsung di dua file (hash.cpp dan main.cpp), nanti akan error karena duplikat definisi (multiple definition error).
pasien dataa[SIZE]; //Supaya file lain seperti main.cpp atau fungsi lain di hash.cpp bisa mengakses array data ini tanpa duplikasi
bool occupied[SIZE] = {false};

int hashFunction1(string name);
int hashFunction2(string name);
void insert(pasien p);
void search(string name);
void cekIndeks(int index);
void printpasien();

#endif // HASH_H