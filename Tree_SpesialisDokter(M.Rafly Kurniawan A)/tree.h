#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct untuk detail dokter spesialis
struct detail_dokter {
	string nama;
    string tanggal_lahir;
    string jenis_kelamin;
    int umur;
};

struct Node {
    string data;
    vector<Node*> children;
    detail_dokter detail; // Tambahan informasi detail

    Node(string val) : data(val) {}
};

// Fungsi-fungsi yang digunakan
void tambahAnak(Node* parent, string nilaiAnak);
void preorder(Node* root, int depth = 0);
void postorder(Node* root, int depth = 0);
Node* cariNode(Node* root, const string& nilai);
int hitungKedalaman(Node* root);
void lihatDetail(Node* node);

#endif

