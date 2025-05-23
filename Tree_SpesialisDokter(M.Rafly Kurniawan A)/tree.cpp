#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "tree.h"

using namespace std;

void tambahAnak(Node* parent, string nilaiAnak) {
    Node* anakBaru = new Node(nilaiAnak);
    parent->children.push_back(anakBaru);
}

void preorder(Node* root, int depth) {
    if (root == NULL) return;
    for (int i = 0; i < depth; ++i) cout << "--";
    cout << root->data << endl;
    for (size_t i = 0; i < root->children.size(); ++i) {
        preorder(root->children[i], depth + 1);
    }
}

void postorder(Node* root, int depth) {
    if (root == NULL) return;
    for (size_t i = 0; i < root->children.size(); ++i) {
        postorder(root->children[i], depth + 1);
    }
    for (int i = 0; i < depth; ++i) cout << "--";
    cout << root->data << endl;
}

Node* cariNode(Node* root, const string& nilai) {
    if (root == NULL) return NULL;
    if (root->data == nilai) return root;
    for (size_t i = 0; i < root->children.size(); ++i) {
        Node* hasil = cariNode(root->children[i], nilai);
        if (hasil != NULL) return hasil;
    }
    return NULL;
}

int hitungKedalaman(Node* root) {
    if (root == NULL) return 0;
    int maxDepth = 0;
    for (size_t i = 0; i < root->children.size(); ++i) {
        int depth = hitungKedalaman(root->children[i]);
        if (depth > maxDepth) maxDepth = depth;
    }
    return maxDepth + 1;
}

void lihatDetail(Node* node) {
    if (node == NULL) {
        cout << "Dokter tidak ditemukan!" << endl;
        return;
    }

    cout << "\nDetail Dokter: " << node->data << endl;
    cout << "Nama Dokter   : " << node->detail.nama << endl;
    cout << "Tanggal Lahir : " << node->detail.tanggal_lahir << endl;
    cout << "Jenis Kelamin : " << node->detail.jenis_kelamin << endl;
    cout << "Umur          : " << node->detail.umur << " tahun" << endl;
}


