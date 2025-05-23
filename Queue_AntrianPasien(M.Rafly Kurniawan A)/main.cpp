#include "queue.cpp"
#include <limits> // Untuk clear buffer

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void tambahPasien(Queue &antrean) {
    if (antrean.isFull()) {
        cout << "Antrean sudah penuh!\n";
        return;
    }

    Pasien p;
    cout << "\nMasukkan data pasien:\n";
    
    cout << "Nama: ";
    getline(cin, p.nama);
    
    cout << "Usia: ";
    while (!(cin >> p.usia)) {
        cout << "Input tidak valid. Masukkan usia (angka): ";
        clearInputBuffer();
    }
    clearInputBuffer();
    
    cout << "Keluhan: ";
    getline(cin, p.keluhan);
    
    antrean.enqueue(p);
    cout << "Pasien berhasil ditambahkan ke antrean!\n";
}

void panggilPasien(Queue &antrean) {
    Pasien diperiksa = antrean.dequeue();
    if (diperiksa.nama == "" && diperiksa.usia == -1 && diperiksa.keluhan == "") {
        cout << "\nTidak ada pasien yang diperiksa karena antrean kosong.\n";
    } else {
        cout << "\nPasien yang diperiksa:\n";
        cout << "Nama: " << diperiksa.nama << ", Usia: " << diperiksa.usia
             << ", Keluhan: " << diperiksa.keluhan << endl;
    }
}

void tampilkanMenu() {
    cout << "\n=== SISTEM ANTREAN PASIEN ===\n";
    cout << "1. Tambah Pasien\n";
    cout << "2. Panggil Pasien Berikutnya\n";
    cout << "3. Lihat Antrean Saat Ini\n";
    cout << "4. Lihat Semua Pasien yang Pernah Ditambahkan\n";
    cout << "5. Keluar\n";
    cout << "Pilihan: ";
}

int main() {
    Queue antrean;
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        clearInputBuffer();
        
        switch(pilihan) {
            case 1:
                tambahPasien(antrean);
                break;
            case 2:
                panggilPasien(antrean);
                break;
            case 3:
                cout << "\nStatus Antrean Saat Ini:\n";
                antrean.display();
                break;
            case 4:
                antrean.displayHistory();
                break;
            case 5:
                cout << "Terima kasih. Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
