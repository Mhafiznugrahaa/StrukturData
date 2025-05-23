#include<iostream>
using namespace std;

int main(){
    string pilihhapus;
    int usia;
    int daftar;
    string tigaDimensi[2][5][4]; // 2 rs, 5 baris, 4 kolom
    int jumlahbaris[2] = {0, 0}; //indeks 1-1 || indeks 2-1
    int angka, indeks, angkaBaru, buatdata;
    int jumlahkolom = 0;
    int hapusBaris, hapusKolom; 
    int pilihan;
    int UpdateBaris, UpdateKolom;
    string nilaiBaru;

    do{
        cout << "\n=== Array 3 Dimensi ===\n";
        cout << "1. Create (Tambah Data Pasien)\n";
        cout << "2. Read (Lihat Data Pasien)\n";
        cout << "3. Update (Ubah Data Pasien)\n"; 
        cout << "4. Delete (Hapus Data Pasien)\n";
        cout << "5. Keluar\n";


        // cout << "____________________________________\n" << endl;
        cout << "Masukan pilihan anda : ";
        cin >> pilihan;

    if (pilihan > 0 && pilihan <=5)
    {
        cout <<"_____________________________________" << endl;
    if(pilihan == 1){
            cout << "Pilih cabang rumah sakit, masukan (1) untuk Rumah sakit Kijang Kencana Cabang pertama, dan (2) untuk Cabang yang ke-2 : ";
            cin >> indeks;
            if (indeks == 1 || indeks == 2){
                int baris = jumlahbaris[indeks-1];
                if (jumlahbaris[indeks-1] < 5)
                {
                    cout << "Masukan daftar nomor Pasien : ";
                    cin >> daftar; tigaDimensi[indeks-1][baris][0] = to_string(daftar);
                    cout << "Masukan nama pasien : ";
                    cin.ignore();
                    getline(cin, tigaDimensi[indeks-1][baris][1]);
                    cout << "Masukan usia pasien : ";
                    cin >> usia; tigaDimensi[indeks-1][baris][2] = to_string(usia);
                    cout << "Masukan keluhan pasien : ";
                    cin.ignore();
                    getline (cin, tigaDimensi[indeks-1][baris][3]);
                    // jumlahkolom++; // yang jadi patokan itu jumlah kolom nya, karena kalo kolom satu habis kolom dua yang bakal keisi

                    jumlahbaris[indeks-1]++;
                }
        }
        else{
            cout << "Data penuh" << endl;
        }
    }
    else if(pilihan == 2){ //Read
        if (jumlahkolom <= 2){
            cout << "Berikut isi data-data pasien di Rumah sakit Kencana Indah dan Rumah sakit Jaya Pura" << endl;
            // cout << "Rumah sakit yang anda pilih adalah rumah sakit jayapura : ";
            for (int l = 0; l < 2; l++) //2 rs
            {
                if (l == 0)
                {
                    cout << "____________________________________\n" << endl;
                    cout << "data di rumah sakit kencana indah cabang 1\n";
                    // cout << "____________________________________\n" << endl;
                } else {
                    cout << "____________________________________\n" << endl;
                    cout << "\ndata di rumah sakit kencana indah cabang 2\n";
                    // cout << "____________________________________\n" << endl;
                }
                
                cout << "ID | Nama  | Usia | Keluhan\n";

                for(int j = 0; j < jumlahbaris[l]; j++){ 
                    for (int i = 0; i < 4; i++){
                        cout << tigaDimensi[l][j][i] << "  | "; 
                    }
                    cout << endl;
                }
            }
            
        }
        else{
            cout <<"Tidak ada data yang ditemukan" << endl;
        }
        
    }
    else if(pilihan == 3){ //UPDATE
        cout << "Pilih Cabang Rumah Sakit yang ingin diupdate, ketik (1) untuk Rumah Sakit cabang pertama dan (2) untuk Rumah sakit cabang kedua" << endl;
        cout << "Cabang ke :";
        cin >> indeks;
        if (indeks-1 >= 0 && indeks-1 < 2)
        {
            cout << "Masukan nomor pasien yang ingin diupdate pastikan hanya memasukan baris 1-" << jumlahbaris[indeks-1] << endl;
            cout << "Baris ke : ";
            cin >> UpdateBaris;
            cout << "Pilih kolom yang ingin diupdate:\n";
            cout << "1. Nomor Pasien\n";
            cout << "2. Nama\n";
            cout << "3. Usia\n";
            cout << "4. Keluhan\n";
            cout << "Masukkan pilihan kolom (1 - 4): ";
            cin >> UpdateKolom;

            // Validasi indeks
            if (UpdateKolom >= 1 && UpdateKolom <=4) {
                cin.ignore(); // Penting sebelum getline
                cout << "Masukkan nilai baru: ";
                
                // Untuk nama atau keluhan, gunakan getline agar bisa multi kata
                if (UpdateKolom == 2 || UpdateKolom == 4) {
                    getline(cin, nilaiBaru);
                } else {
                    cin >> nilaiBaru;
                }

                tigaDimensi[indeks-1][UpdateBaris - 1][UpdateKolom - 1] = nilaiBaru;
                cout << "Data berhasil diupdate!\n";
            } else {
                cout << "Indeks tidak valid!\n";
            }
                
        }else {
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
    else if (pilihan == 4){ //delete
        cout << "Apakah anda ingin menghapus salah satu pasien? (ya/tidak): ";
        cin >> pilihhapus;

        if (pilihhapus == "ya") {
            cout << "Masukkan cabang Rumah sakit pasien yang ingin dihapus, ketik (1) untuk Rumah Sakit Kencana indah cabang 1 dan (2) untuk Rumah sakit Kencana indah cabang 2 " << endl;
            cout << "Cabang: ";
            cin >> indeks;

            // Validasi indeks
            if (indeks-1 >= 0 && indeks-1 <2) {
                cout << "Masukan baris pasien yang ingin dihapus pastikan hanya memasukan baris 1-" << jumlahbaris[indeks-1] << "!!"<< endl;
                cout << "Baris ke: ";
                cin >> hapusBaris; 

                if (hapusBaris >= 1 && hapusBaris <= jumlahbaris[indeks-1]) {
                for (int i = hapusBaris - 1; i < jumlahbaris[indeks-1] - 1; i++) {
                    for (int j = 0; j < 4; j++) {
                        tigaDimensi[indeks-1][i][j] = tigaDimensi[indeks-1][i + 1][j];
                    }
                }
                for (int j = 0; j < 4; j++) {
                    tigaDimensi[indeks-1][jumlahbaris[indeks-1] - 1][j] = "-";
                }
                jumlahbaris[indeks-1]--; // Kurangi jumlah baris
                cout << "Data berhasil dihapus!\n";
            } else {
                cout << "Baris tidak valid!\n";
            }
                // tigaDimensi[hapusBaris - 1][hapusKolom - 1] = "Dihapus"; //sebagai tanda data dihapus kita jadikan 0
            } else {
                cout << "pilihan salah!, tolong hanya pilih cabang 1 dan 2 saja\n";
            }
        }
    }
        
    } else{
        cout << "pilihan tidak valid!!" << endl;
    }
    }while (pilihan !=5);   
}


    // cout << "Masukan indeks yang ingin dikeluarkan___________________ pilih indeks ke 1-" << jumlahkolom << endl;
    // cin >> angka;
    // if(angka <=jumlahkolom){
        //     cout << "Elemen dalam indeks yang dikeluarkan adalah : " << tigaDimensi[angka-1] << endl;
        // }