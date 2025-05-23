#include <iostream>
#include <string>
#include "tree.cpp"

using namespace std;

void tampilkanMenu() {
    cout << "\n=== Sistem Dokter Spesialis ===" << endl;
    cout << "1. Tampilkan Traversal Preorder" << endl;
    cout << "2. Tampilkan Traversal Postorder" << endl;
    cout << "3. Lihat Detail Dokter Spesialis" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    Node* root = new Node("Spesialisasi Dokter");

    // Tambah spesialisasi
    tambahAnak(root, "Dokter Umum");
    tambahAnak(root, "Dokter Gigi");
    tambahAnak(root, "Dokter Anak");
    tambahAnak(root, "Dokter Spesialis Jantung");    

    // Tambah layanan untuk setiap dokter
    tambahAnak(cariNode(root, "Dokter Umum"), "Pemeriksaan Fisik");
    tambahAnak(cariNode(root, "Dokter Umum"), "Konsultasi Umum");

    tambahAnak(cariNode(root, "Dokter Gigi"), "Pembersihan Gigi");
    tambahAnak(cariNode(root, "Dokter Gigi"), "Tambal Gigi");

    tambahAnak(cariNode(root, "Dokter Anak"), "Imunisasi");
    tambahAnak(cariNode(root, "Dokter Anak"), "Konsultasi nutrisi anak");

    tambahAnak(cariNode(root, "Dokter Spesialis Jantung"), "Pemeriksaan jantung");
    tambahAnak(cariNode(root, "Dokter Spesialis Jantung"), "Konsultasi Jantung");
    
    
    // Isi manual detail dokter
    Node* DokterUmum = cariNode(root, "Dokter Umum");
    DokterUmum->detail = {"Harun","01-05-1980", "Laki-laki", 45};

    Node* DokterGigi = cariNode(root, "Dokter Gigi");
    DokterGigi->detail = {"Kartika","15-03-1985", "Perempuan", 40};

    Node* DokterAnak = cariNode(root, "Dokter Anak");
    DokterAnak->detail = {"Kiki","10-10-1994", "Perempuan", 47};

    Node* DokterJantung = cariNode(root, "Dokter Spesialis Jantung");
    DokterJantung->detail = {"Handoko","20-07-1991", "Laki-laki", 50};
    
    
    int pilihan;
    string dokter;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                cout << "\nTraversal Preorder:\n";
                preorder(root);
                break;
            case 2:
                cout << "\nTraversal Postorder:\n";
                postorder(root);
                break;
            case 3:
                cout << "Masukkan dokter spesialis: ";
                getline(cin, dokter);
                lihatDetail(cariNode(root, dokter));
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
