#include <iostream>
using namespace std;

// Node untuk menyimpan data dan pointer ke node berikutnya
struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue {
private:
    Node* front; // Node depan dari antrian
    Node* rear;  // Node belakang dari antrian

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        clearQueue();
    }

    // Fungsi untuk menambahkan data ke antrian
    void enqueue(const string& nama, const string& nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << "Mahasiswa dengan Nama: " << nama << " dan NIM: " << nim << " ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void pop() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        cout << "Mahasiswa dengan Nama: " << temp->nama << " dan NIM: " << temp->nim << " dihapus dari antrian." << endl;
        delete temp;

        // Jika setelah penghapusan antrian menjadi kosong
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Fungsi untuk menampilkan elemen di depan antrian
    void displayFront() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }
        cout << "Mahasiswa di depan antrian: Nama = " << front->nama << ", NIM = " << front->nim << endl;
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk mengembalikan jumlah elemen dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Antrian mahasiswa telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue("Andi", "12345");
    queue.enqueue("Maya", "67890");
    queue.displayQueue();
    queue.displayFront();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    queue.pop();
    queue.displayQueue();
    queue.displayFront();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.displayQueue();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;

    return 0;
}
