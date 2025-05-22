#include "queue.cpp"

int main() {
    Queue antrean;

    // Tambahkan pasien antrean.enqueue
    antrean.enqueue({"Rafly", 19, "sariawan"});
    antrean.enqueue({"azhar", 45, "struk"});
    antrean.enqueue({"cipto", 24, "Batuk"});
    antrean.enqueue({"ahmettt", 25, "ambeyen"});
    
    antrean.display();
    antrean.dequeue();
    // Panggil pasien pertama
    Pasien diperiksa = antrean.dequeue();
	if (diperiksa.nama == "" && diperiksa.usia == -1 && diperiksa.keluhan == "") {
	    // Tidak ada pasien yang bisa diperiksa
	    cout << "\nTidak ada pasien yang diperiksa karena antrean kosong.\n";
	} else {
	    cout << "\nPasien yang diperiksa:\n";
	    cout << "Nama: " << diperiksa.nama << ", Usia: " << diperiksa.usia
	         << ", Keluhan: " << diperiksa.keluhan << endl;
	}


    // Tampilkan antrean setelah di periksa
    cout << "\nAntrean setelah pemeriksaan:\n";
    antrean.display();

return 0;
}
