#include <iostream>
#include "graph.cpp" // Menggunakan definisi dan implementasi graph

using namespace std;

int main() {
    initGraph(6);

    // Mengisi data rumah sakit (nama, alamat, kapasitas, IGD, tipe)
    rumahSakit[0] = {"RS A", "Jl. Mawar 1", 100, true, UMUM};
    rumahSakit[1] = {"RS B", "Jl. Melati 2", 80, true, PUSKESMAS};
    rumahSakit[2] = {"RS C", "Jl. Kenanga 3", 120, false, UMUM};
    rumahSakit[3] = {"RS D", "Jl. Dahlia 4", 90, true, KHUSUS};
    rumahSakit[4] = {"RS E", "Jl. Anggrek 5", 70, false, PUSKESMAS};
    rumahSakit[5] = {"RS F", "Jl. Cempaka 6", 150, true, UMUM};

    // Menambahkan koneksi antar rumah sakit
    addEdge(0, 1); // RS A ke RS B
    addEdge(0, 2); // RS A ke RS C
    addEdge(1, 3); // RS B ke RS D
    addEdge(2, 3); // RS C ke RS D
    addEdge(3, 4); // RS D ke RS E
    addEdge(4, 5); // RS E ke RS F

    // Menampilkan graf dan informasi
    printGraph();

    // Mengecek konektivitas
    cout << "\nCek konektivitas antar rumah sakit: ";
    if (isConnected())
        cout << "Semua rumah sakit saling terhubung.\n";
    else
        cout << "Terdapat rumah sakit yang tidak terhubung.\n";

    // Menampilkan jalur terpendek dari RS A ke RS F
    cout << "\nRujukan pasien dari RS A ke RS F:\n";
    bfsShortestPath(0, 5);

    // Menampilkan jarak rujukan terjauh dari RS A
    cout << "\nJarak rujukan terjauh dari RS A: ";
    cout << bfsFarthestDistance(0) << " langkah\n";

    return 0;
}