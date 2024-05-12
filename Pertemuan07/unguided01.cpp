#include <iostream>
using namespace std;

// Node untuk menyimpan data dan pointer ke node berikutnya
struct Node {
    string data;
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

    // Fungsi untuk menambahkan data ke antrian
    void enqueue(const string& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << data << " ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        cout << temp->data << " dihapus dari antrian." << endl;
        delete temp;

        // Jika setelah penghapusan antrian menjadi kosong
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Data antrian teller:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << endl;
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
            dequeue();
        }
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}