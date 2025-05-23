#include "stack.cpp"

int main()
{
    List S2, S1; //deklarasi List dengan variabel L
    // string nama, nim; //mendeklarasi string
    address P;  //deklarasi address dengan variabel P
    createStack(S2); 
    
    cout << "\n_________________Tumpukan di rak obat pertama______________________" << endl;
    cout << "Nama Obat       |    Tanggal Kadaluarsa    | Harga | Tumpukan ke " << endl;
    cout << "-----------------------------------------------------------------" << endl; 

    push(S2, alokasi("Amoxicillin ", "2026-03-15", 19000, 5)); // paling atas, karena masuk terakhir 
    push(S2, alokasi("Paracetamol ", "2025-12-31", 31000, 4));
    push(S2, alokasi("Loratadine  ", "2025-06-30", 30000, 3));
    push(S2, alokasi("Omeprazole  ", "2025-01-15", 21000, 2));
    push(S2, alokasi("Aspirin     ", "2024-10-01", 20000, 1)); // paling bawah (first in last out) yang sebentar lagi kadaluarsa berada ditumpukan paling atas agar keluar paling awal

    viewList(S2);
    createStack(S1);
    cout << "\n_________________Tumpukan di rak obat ke dua______________________" << endl;
    cout << "Nama Obat       |    Tanggal Kadaluarsa    | Harga | Tumpukan ke " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    push(S1, alokasi("Metformin    ", "2026-04-01", 28000, 5)); // paling atas
    push(S1, alokasi("Vitamin C    ", "2025-11-05", 16000, 4));
    push(S1, alokasi("Ibuprofen    ", "2025-07-20", 25000, 3));
    push(S1, alokasi("Ranitidine   ", "2025-02-10", 22000, 2));
    push(S1, alokasi("Cetirizine   ", "2024-09-15", 18000, 1)); // paling bawah
    viewList(S1);


    // cout << "\n";
    // cout << "            __Setelah di reverse__" << endl;
    // reverseStack(L); //memanggil fungsi prosedur 
    // viewList(L);

    cout << "\n";

    pop(S1, P);
    pop(S2, P);
    pop(S1, P);
    pop(S2, P);

    cout << "       __Setelah tumpukan di rak pertama paling atas diambil__" << endl;
    cout << "Nama Obat       |    Tanggal Kadaluarsa    | Harga | Tumpukan ke " << endl;
    cout << "----------------------------------------------------------" << endl; 
    viewList(S2);
    cout << "       __Setelah tumpukan di rak kedua paling atas diambil__" << endl;
    cout << "Nama Obat       |    Tanggal Kadaluarsa    | Harga | Tumpukan ke " << endl;
    cout << "----------------------------------------------------------" << endl; 
    viewList(S1);

    // cout << "sebelum dibalik" << endl;
    // viewList(L);

    // cout << "\n setelah dibalik" << endl;
    // viewList(L);
    cout<< " "<< endl;
    return 0;
    }