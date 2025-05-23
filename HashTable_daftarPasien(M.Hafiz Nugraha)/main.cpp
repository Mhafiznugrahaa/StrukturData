#include <iostream>
#include <string>
#include "hash.cpp"
using namespace std;


int main() {
    insert({1, "Budi", 20, "Demam", "Indramayu"});
    insert({2, "Farhan", 19, "Demam", "Bandung"});
    insert({3, "Hafiz", 21, "Demam", "Indramayu"});
    insert({4, "fahri", 22, "Demam", "Aceh"});
    insert({5, "Lukman", 18, "Demam", "Malang"});
    insert({6, "Ido", 23, "Demam", "Jogjakarta"});
    insert({7, "Zahran", 20, "Demam", "Indramayu"});
    insert({8, "Saip", 19, "Demam", "Bandung"});
    insert({9, "Asep", 18, "Demam", "Aceh"});
do{
    cout << "========================================" << endl;
    cout << "1. melihat nama-nama pasien yang sudah terdaftar" << endl;
    cout << "2. Mencari nama pasien yang sudah terdaftar dan belum" << endl;
    cout << "3. Mengecek daftar pasien yang masih kosong" << endl;
    cout << "4. Keluar dari program" << endl;
    cout << "Silahkan masukan pilihan anda : ";
    cin >> pilihan ;
    cout << "========================================" << endl;


    if (pilihan == 1){
        printpasien();
    } else if(pilihan == 2) {
        string nama;
        cout << "masukan nama pasien yang ingin dicari : ";
        cin >> nama;
        cout << endl;
        search(nama);
        // search(nama);
    } else if(pilihan == 3) {
        int index;
        cout << "Tolong masukan daftar angka 1 - 30, tidak lebih dari 30!!" << endl;
        cout << "Daftar angka ke : ";
        cin >> index;
        cout << endl;
        cekIndeks(index);
        // cekIndeks(index);
    } else if(pilihan !=4) {
        cout << "pilihan tidak ada!!";
    }
} while (pilihan != 4);
    
    return 0;
}