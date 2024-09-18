#include <iostream>

using namespace std;

const int maksimalQueue = 5;  // Maksimal antrian adalah 5

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
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong
        front = nullptr;
        rear = nullptr;
    }

    // Fungsi untuk menambahkan data ke antrian
    void enqueue_2123(const string& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (isEmpty_2123()) { // Jika antrian kosong maka front dan rear menunjuk ke newNode yang baru dibuat 
            front = rear = newNode;
        } else { // Jika antrian tidak kosong maka rear menunjuk ke newNode yang baru dibuat
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << data << " ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void dequeue_2123() {
        if (isEmpty_2123()) { // Jika antrian kosong maka tampilkan pesan "Antrian kosong" dan kembalikan nilai void
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front; // Simpan node front ke dalam variabel temp untuk dihapus nantinya 
        front = front->next; // Geser front ke node selanjutnya 

        cout << temp->data << " dihapus dari antrian." << endl; // Tampilkan data yang dihapus dari antrian 
        delete temp; // Hapus node yang disimpan di variabel temp

        // Jika setelah penghapusan antrian menjadi kosong
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue_2123() {
        if (isEmpty_2123()) { // Jika antrian kosong maka tampilkan pesan "Data antrian:" dan tampilkan pesan "(kosong)"
            cout << "Data antrian:" << endl;
            for (int i = 0; i < maksimalQueue; i++) {
                cout << i + 1 << ". (kosong)" << endl;
            }
        } else { // Jika antrian tidak kosong maka tampilkan data antrian yang ada
            cout << "Data antrian:" << endl;
            Node* current = front;
            int i = 1;
            while (current != nullptr) { // Selama current tidak menunjuk ke nullptr maka tampilkan data antrian yang ada 
                cout << i << ". " << current->data << endl;
                current = current->next;
                i++;
            }
            for (; i <= maksimalQueue; i++) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
                cout << i << ". (kosong)" << endl;
            }
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty_2123() {
        return front == nullptr;
    }

    // Fungsi untuk mengembalikan jumlah elemen dalam antrian
    int countQueue_2123() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) { // Selama current tidak menunjuk ke nullptr maka hitung jumlah elemen dalam antrian
            count++;
            current = current->next;
        }
        return count; // Kembalikan jumlah elemen dalam antrian
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue() {
        while (!isEmpty_2123()) { // Selama antrian tidak kosong maka hapus elemen dalam antrian
            dequeue_2123(); // Hapus elemen dalam antrian 
        } 
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue
    queue.enqueue_2123("Andi");
    queue.enqueue_2123("Maya");
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;
    queue.dequeue_2123();
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;
    queue.dequeue_2123();
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;

    return 0;
}