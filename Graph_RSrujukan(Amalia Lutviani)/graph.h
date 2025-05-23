#ifndef GRAPH_H
#define GRAPH_H

#include <string>

const int MAX_RS = 100;

// Matriks ketetanggaan dan penanda kunjungan
extern int adj[MAX_RS][MAX_RS];
extern bool visited[MAX_RS];
extern int V;

// Enum untuk tipe rumah sakit
enum TipeRS {
    UMUM,
    KHUSUS,
    PUSKESMAS
};

// Struct untuk menyimpan data rumah sakit
struct RumahSakit {
    std::string nama;
    std::string alamat;
    int kapasitas;
    bool tersediaIGD;
    TipeRS tipe;
};

// Array untuk menyimpan informasi rumah sakit
extern RumahSakit rumahSakit[MAX_RS];

// Fungsi-fungsi terkait graph
void initGraph(int vertices);
void addEdge(int u, int v);
void printGraph();
void bfsShortestPath(int start, int end);
bool isConnected();
int bfsFarthestDistance(int start);

#endif // GRAPH_H