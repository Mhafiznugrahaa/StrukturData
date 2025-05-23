#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector> // Untuk menyimpan history
using namespace std;

const int MAX = 5; // Ukuran maksimal antrean

struct Pasien {
    string nama;
    int usia;
    string keluhan;
};

struct Queue {
    Pasien arr[MAX]; // Array untuk menyimpan pasien
    int front, rear;
    vector<Pasien> history; // Untuk menyimpan semua pasien yang pernah ditambahkan

    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(Pasien p);
    Pasien dequeue();
    void display();
    void displayHistory(); // Fungsi baru untuk menampilkan history
};

#endif
