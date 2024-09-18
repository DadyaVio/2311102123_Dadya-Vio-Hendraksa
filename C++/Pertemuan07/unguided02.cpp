#include <iostream>

using namespace std;

// Node untuk menyimpan data dan pointer ke node berikutnya
struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue { // Class Queue untuk menyimpan data antrian dan operasi-operasinya 
private:
    Node* front; // Node depan dari antrian
    Node* rear;  // Node belakang dari antrian

public: 
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong 
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() { // Destruktor untuk membersihkan antrian 
        clearQueue(); // Panggil fungsi clearQueue() untuk membersihkan antrian 
    }

    // Fungsi untuk menambahkan data ke antrian
    void enqueue_2123(const string& nama, const string& nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (isEmpty_2123()) { // Jika antrian kosong maka front dan rear menunjuk ke newNode yang baru dibuat 
            front = rear = newNode;
        } else { // Jika antrian tidak kosong maka rear menunjuk ke newNode yang baru dibuat
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << "Mahasiswa dengan Nama: " << nama << " dan NIM: " << nim << " ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void pop_2123() { // Fungsi pop() sama dengan fungsi dequeue() pada guided01.cpp
        if (isEmpty_2123()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front; // Simpan node front ke dalam variabel temp untuk dihapus nantinya
        front = front->next; // Geser front ke node selanjutnya

        cout << "Mahasiswa dengan Nama: " << temp->nama << " dan NIM: " << temp->nim << " dihapus dari antrian." << endl;
        delete temp;

        // Jika setelah penghapusan antrian menjadi kosong
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue_2123() {
        if (isEmpty_2123()) { // Jika antrian kosong maka tampilkan pesan "Data antrian:" dan tampilkan pesan "(kosong)"
            cout << "Data antrian:" << endl;
            for (int i = 1; i <= 5; ++i) { // Tampilkan pesan "(kosong)" sebanyak 5 kali karena maksimal antrian adalah 5 
                cout << i << ". (kosong)" << endl;
            }
            return;
        }

        cout << "Data antrian:" << endl;
        Node* current = front; // Simpan front ke dalam variabel current
        int i = 1;
        while (current != nullptr) { // Selama current tidak menunjuk ke nullptr maka tampilkan data antrian yang ada
            cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            i++;
        }
        for (; i <= 5; ++i) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
            cout << i << ". (kosong)" << endl;
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
        return count;
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue() {
        while (!isEmpty_2123()) { // Selama antrian tidak kosong maka hapus elemen antrian dengan memanggil fungsi pop()
            pop_2123();
        }
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue 
    queue.enqueue_2123("Andi", "2311102123");
    queue.enqueue_2123("Maya", "2311102124");
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;
    queue.pop_2123();
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;
    queue.pop_2123();
    queue.displayQueue_2123();
    cout << "Jumlah antrian = " << queue.countQueue_2123() << endl;

    return 0;
}