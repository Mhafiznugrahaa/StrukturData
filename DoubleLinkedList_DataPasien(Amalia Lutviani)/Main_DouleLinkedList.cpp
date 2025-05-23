#include "DoubleLinkedList.cpp"

int main() {
    List L;
    address P;

    // Inisialisasi list kosong
    createList(L);
    cout << "List awal (kosong):\n";
    viewList(L);
    cout << "\n\n";
    
    // Menambahkan pasien ke awal list
    cout << "Menambahkan pasien ke awal:\n";
    Pasien p1 = {"3212155812020002", "Andi", 18, "Demam Berdarah"};
    Pasien p2 = {"2023236678900765", "Budi", 5, "Ephilepshi"};
    Pasien p3 = {"2045500854321566", "Citra", 4, "Drownsyndrome"};
    insertFirst(L, alokasi(p1));
    insertFirst(L, alokasi(p2));
    insertFirst(L, alokasi(p3));
    cout << "Setelah menambahkan 3 pasien:\n";
    viewList(L);
    cout << "\n\n";

    // Mencari pasien berdasarkan NIK
    cout << "Mencari pasien dengan NIK '3212155812020002': ";
    address ditemukan = findByNIK(L, "3212155812020002");
    if (ditemukan != Nil) {
        cout << "Ditemukan: " << info(ditemukan).nama << endl;
    } else {
        cout << "Tidak ditemukan\n";
    }

    // Menyisipkan sebelum pasien dengan NIK tertentu
    cout << "\nMenyisipkan pasien sebelum 'Budi':\n";
    Pasien p4 = {"2023014", "Nina", 24, "Magh"};
    address target = findByNIK(L, "2023236678900765"); // NIK Budi
    if (target != Nil) {
        insertBefore(L, alokasi(p4), target);
        cout << "Setelah menyisipkan sebelum Budi:\n";
        viewList(L);
    }

    // Menghapus pasien sebelum Budi
    cout << "\nMenghapus pasien sebelum 'Budi':\n";
    if (target != Nil && prev(target) != Nil) {
        delBefore(L, P, target);
        cout << "Pasien yang dihapus: " << info(P).nama << endl;
        dealokasi(P);
        viewList(L);
    }

    // Menambahkan pasien ke akhir list
    cout << "\nMenambahkan pasien ke akhir:\n";
    insertLast(L, alokasi({"4056788321976300", "Diana", 20, "Asam Lambung"}));
    insertLast(L, alokasi({"4212189765325001", "Eko", 22, "Insomnia"}));
    viewList(L);
    cout << "\n\n";

    // Menghapus pasien pertama
    cout << "Menghapus pasien pertama:\n";
    delFirst(L, P);
    dealokasi(P);
    viewList(L);
    cout << "\n\n";

    // Menghapus pasien terakhir
    cout << "Menghapus pasien terakhir:\n";
    delLast(L, P);
    dealokasi(P);
    viewList(L);
    cout << "\n\n";

    // Menampilkan isi list terakhir
    cout << "Data pasien saat ini:\n";
    viewList(L);

    return 0;
}