#include "graph.h"
#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

// Definisi variabel global
int adj[MAX_RS][MAX_RS];
bool visited[MAX_RS];
int V;
RumahSakit rumahSakit[MAX_RS]; // gunakan struct

// Inisialisasi graf kosong
void initGraph(int vertices) {
    V = vertices;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
}

// Tambah edge dua arah
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Tampilkan matriks ketetanggaan
void printGraph() {
    cout << "Matriks Ketetanggaan Rumah Sakit:\n   ";
    for (int i = 0; i < V; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nInformasi Detail Rumah Sakit:\n";
    for (int i = 0; i < V; i++) {
        cout << "[" << i << "] " << rumahSakit[i].nama
             << " | Alamat: " << rumahSakit[i].alamat
             << " | Kapasitas: " << rumahSakit[i].kapasitas
             << " | IGD: " << (rumahSakit[i].tersediaIGD ? "Tersedia" : "Tidak")
             << " | Tipe: ";
        switch (rumahSakit[i].tipe) {
            case UMUM: cout << "Umum"; break;
            case KHUSUS: cout << "Khusus"; break;
            case PUSKESMAS: cout << "Puskesmas"; break;
        }
        cout << endl;
    }
}

// Algoritma BFS untuk cari jalur terpendek
void bfsShortestPath(int start, int end) {
    int dist[MAX_RS];
    int parent[MAX_RS];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    queue<int> q;
    dist[start] = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[end]) {
        cout << "Tidak ada jalur rujukan dari " << rumahSakit[start].nama << " ke " << rumahSakit[end].nama << endl;
        return;
    }

    cout << "Jalur rujukan terpendek dari " << rumahSakit[start].nama << " ke " << rumahSakit[end].nama << " = " << dist[end] << " langkah" << endl;
    cout << "Rute: ";

    int path[MAX_RS], count = 0;
    int current = end;
    while (current != -1) {
        path[count++] = current;
        current = parent[current];
    }

    for (int i = count - 1; i >= 0; i--) {
        cout << rumahSakit[path[i]].nama;
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

// DFS untuk cek konektivitas
void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// Mengecek apakah semua rumah sakit saling terhubung
bool isConnected() {
    memset(visited, 0, sizeof(visited));
    dfs(0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

// Mencari jarak terjauh dari satu rumah sakit (BFS)
int bfsFarthestDistance(int start) {
    int dist[MAX_RS];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++) dist[i] = -1;

    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    int maxDist = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                maxDist = max(maxDist, dist[v]);
                q.push(v);
            }
        }
    }

    return maxDist;
}