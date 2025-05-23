#include <iostream>
#include <string>
#include "hash.h"
using namespace std;


// Fungsi hash utama (polynomial rolling)
int hashFunction1(string name) {
    int hash = 0;
    for (int i = 0; i < name.length(); i++) { //Rumus h(k) = k mod m (20 % 5 = 0 -> index 0) 
        hash = (hash * 93 + name[i]) % SIZE; // 31 kali 3 = 93 // 23 % 10 = 3 -> index 3
    }
    // cout << "Daftar1 : " << hash << endl;
    return hash;
}
// Setiap karakter di komputer disimpan sebagai kode angka menurut standar ASCII.
// misal nama = hafiz so name.length of hafiz adalah 5 
//hash 0 h = (0 * 93 + 72) % 31 = 10
//hash 10 a = (1 * 93 + 97) % 31 = 3
//hash 3 f = (7 * 93 + 102) % 31 = 9
//hash 9 i = (0 * 93 + 105) % 31 = 12
//hash 12 z = (0 * 93 + 122) % 31 = 28
//hash1 = 28. index 28 = hafiz

// Fungsi hash alternatif (sederhana)
int hashFunction2(string name) {
    int hash = 0;
    for (int i = 0; i < name.length(); i++) {
        hash = (hash + name[i] * (i + 1)) % SIZE;
    }
    // cout << "Daftar2: " << hash << endl;
    return hash;
}

// Insert nama, mencoba dua fungsi hash
// void insert(string name) {
//     int idx1 = hashFunction1(name);
//     if (!occupied[idx1]) {
//         pasien[idx1] = name;
//         occupied[idx1] = true;
//         // cout << "Pasien bernama '" << name << "' terdaftar di no:" << idx1 << " (Daftar1)" << endl;
//         return;
//     }

//     // Jika bentrok, coba hash kedua
//     int idx2 = hashFunction2(name);
//     if (!occupied[idx2]) {
//         pasien[idx2] = name;
//         occupied[idx2] = true;
//         // cout << "Pasien bernama '" << name << "' terdaftar di no:" << idx1 << " (Daftar2)" << endl;
//         return;
//     }

//     cout << "Gagal menyimpan pasien bernama '" << name << "': dikarenakan daftar nomor bentrok." << endl;
// }

void insert(pasien p) {
    int idx1 = hashFunction1(p.nama);
    if (!occupied[idx1]) {
        dataa[idx1] = p;
        occupied[idx1] = true;
        cout << "Pasien '" << p.nama << "' disimpan di indeks " << idx1 << " (Hash1)" << endl;
        return;
    }

    int idx2 = hashFunction2(p.nama);
    if (!occupied[idx2]) {
        dataa[idx2] = p;
        occupied[idx2] = true;
        cout << "Pasien '" << p.nama << "' disimpan di indeks " << idx2 << " (Hash2)" << endl;
        return;
    }

    cout << "Gagal menyimpan pasien '" << p.nama << "': posisi indeks bentrok!" << endl;
}

// Cari nama
void search(string name) {
    int idx1 = hashFunction1(name);
    if (occupied[idx1] && dataa[idx1].nama == name) {
        cout << "Pasien bernama '" << name << "' terdaftar di nomor " << idx1 << " (Daftar1)" << endl;
        cout << "ID     : " << dataa[idx1].id << endl;
        cout << "Nama   : " << dataa[idx1].nama << endl;
        cout << "Umur   : " << dataa[idx1].umur << endl;
        cout << "Umur   : " << dataa[idx1].keluhan << endl;
        cout << "Alamat : " << dataa[idx1].alamat << endl;

        return;
    }

    int idx2 = hashFunction2(name);
    if (occupied[idx2] && dataa[idx2].nama == name) {
        cout << "Pasien bernama '" << name << "' terdaftar di nomor " << idx2 << " (Daftar2)" << endl;
        cout << "ID     : " << dataa[idx2].id << endl;
        cout << "Nama   : " << dataa[idx2].nama << endl;
        cout << "Umur   : " << dataa[idx2].umur << endl;
        cout << "Umur   : " << dataa[idx2].keluhan << endl;
        cout << "Alamat : " << dataa[idx2].alamat << endl;

        return;
    }

    cout << "Pasien bernama '" << name << "' tidak terdaftar." << endl;
}

// Cek apakah indeks tertentu sudah diisi
void cekIndeks(int index) {
    if (index < 1 || index >= SIZE) {
        cout << "daftar nomor tidak ada (Tolong masukan angka 0 - 30)." << endl;
        return;
    }

    if (occupied[index-1])
        cout << "Daftar nomor " << index << " terisi oleh pasien bernama '" << dataa[index-1].nama << "'" << endl;
    else
        cout << "Daftar nomor " << index << " masih kosong." << endl;
}

// Cetak seluruh tabel
void printpasien() {
    cout << "\n Berikut nama pasien yang sudah terdaftar:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "[" << i+1 << "] ";
        if (occupied[i]) cout << dataa[i].nama;
        else cout << "(tidak ada daftar yang terisi)";
        cout << endl;
    }
}



