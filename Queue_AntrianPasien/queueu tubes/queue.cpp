#include "queue.h"

// Konstruktor
Queue::Queue() {
    front = rear = -1;
}

bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool Queue::isFull() {
    return (rear == MAX - 1);
}

// Menambahkan pasien ke antrean
void Queue::enqueue(Pasien p) {
    if (isFull()) {
        cout << "Antrean penuh!\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = p;
}

// Menghapus pasien dari antrean
Pasien Queue::dequeue() {
    Pasien dummy = {"", -1, ""};
    if (isEmpty()) {
        cout << "Antrean kosong!\n";
        return dummy;
    }

    Pasien p = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return p;
}

// Menampilkan isi antrean
void Queue::display() {
    if (isEmpty()) {
        cout << "Antrean kosong!\n";
        return;
    }
    cout << "Daftar antrean pasien:\n";
    for (int i = front; i <= rear; i++) {
        cout <<"No.Antrian: " << i - front + 1 << ". Nama: " << arr[i].nama
             << ", Usia: " << arr[i].usia
             << ", Keluhan: " << arr[i].keluhan << endl;
			 
			 }
}
