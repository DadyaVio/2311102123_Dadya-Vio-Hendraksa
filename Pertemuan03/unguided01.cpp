#include <iostream> // mengatur input output
#include <iomanip> // mengatur layout output
#include <string> // mengatur string

using namespace std; // menggunakan standar library

// Deklarasi Struct Node
struct Node {
    string Nama_2123;
    int Umur_2123;
    Node* next; // Pointer next
};

Node* head = nullptr; // Deklarasi head
Node* tail = nullptr; // Deklarasi tail

// Inisialisasi Linked List
void inisialisasi_2123() {
    head = nullptr;
    tail = nullptr;
}

// Mengecek apakah linked list kosong
bool apakah_kosong_2123() {
    return head == nullptr;
}

// Menambah data di depan linked list
void tambah_depan_2123(string Nama, int Umur) {
    Node* newNode = new Node; // Membuat node baru
    newNode->Nama_2123 = Nama; // Menambahkan data Nama
    newNode->Umur_2123 = Umur; // Menambahkan data Umur
    newNode->next = head; // Pointer next menunjuk ke head
    head = newNode; // Head menunjuk ke newNode

    if (tail == nullptr) {
        tail = newNode;
    }
}

// Menambah data di belakang linked list
void tambah_belakang_2123(string Nama, int Umur) {
    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;
    newNode->next = nullptr; // Pointer next menunjuk ke nullptr

    if (apakah_kosong_2123()) {
        head = tail = newNode; // Jika kosong, head dan tail menunjuk ke newNode
    } else {
        tail->next = newNode; // Pointer next tail menunjuk ke newNode
        tail = newNode; // Tail menunjuk ke newNode
    }
}

// Menambah data di tengah linked list berdasarkan posisi data
void tambah_tengah_2123(string Nama, int Umur, int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) { // Jika posisi kurang dari sama dengan 1 atau linked list kosong maka tambah di depan linked list
        cout << "Posisi tidak valid atau list kosong, Maka di tambah ke depan." << endl;
        tambah_depan_2123(Nama, Umur);
        return;
    }

    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;

    Node* current = head; // Pointer current menunjuk ke head linked list sekarang
    int currentPosition = 1; // Inisialisasi posisi saat ini adalah 1 (head) linked list sekarang

    while (current->next != nullptr && currentPosition < Posisi - 1) { // Looping sampai posisi sebelum posisi yang diinginkan (Posisi - 1)
        current = current->next; // Pointer current menunjuk ke node selanjutnya
        currentPosition++; // Posisi saat ini bertambah
    }

    newNode->next = current->next; // Pointer next newNode menunjuk ke node setelah current
    current->next = newNode; // Pointer next current menunjuk ke newNode
}

// Menghapus data di depan linked list
void hapus_depan_2123() {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* temp = head; // Pointer temp menunjuk ke head 
    head = head->next; // Pointer head menunjuk ke node selanjutnya
    delete temp; // Menghapus node temp (node head sebelumnya)

    if (head == nullptr) {
        tail = nullptr;
    }
}

// Menghapus data di belakang linked list
void hapus_belakang_2123() {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    if (head == tail) {
        delete head; // Menghapus node head
        head = tail = nullptr; // Jika head dan tail sama, maka head dan tail menunjuk ke nullptr
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next; // Pointer current menunjuk ke node selanjutnya
    }
    delete tail;
    tail = current; // Pointer tail menunjuk ke node sebelumnya (node yang baru terakhir)
    tail->next = nullptr; // Pointer next tail menunjuk ke nullptr
}

// Menghapus data di tengah linked list berdasarkan posisi data
void hapus_tengah_2123(int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* current = head; // Pointer current diinisialisasi head
    Node* previous = nullptr; // Pointer previous diinisialisasi nullptr
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) {
        cout << "Posisi tidak ada, Maka tida ada yang dihapus" << endl;
        return;
    }

    previous->next = current->next; // Pointer next previous menunjuk ke node setelah current (node yang dihapus)
    delete current; // Menghapus node current (node yang dihapus)

    if (previous->next == nullptr) {
        tail = previous; // Jika node yang dihapus adalah node terakhir, maka tail menunjuk ke node sebelumnya (node yang baru terakhir)
    }
}

// Mengubah data di depan linked list
void ubah_depan_2123(string Nama, int Umur) {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    head->Nama_2123 = Nama;
    head->Umur_2123 = Umur;
}

// Mengubah data di belakang linked list
void ubah_belakang_2123(string Nama, int Umur) {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    tail->Nama_2123 = Nama;
    tail->Umur_2123 = Umur;
}

// Mengbah data di tengah linked list berdasarkan posisi data
void ubah_tengah_2123(string Nama, int Umur, int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat diubah." << endl;
        return;
    }

    Node* current = head;
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) { // Looping sampai posisi yang diinginkan
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) { // Jika posisi tidak ada maka tidak ada yang diubah
        cout << "Posisi tidak ada, Maka tidak ada yang diubah" << endl;
        return;
    }

    current->Nama_2123 = Nama;
    current->Umur_2123 = Umur;
}

// Tampilkan isi data linked list
void display() {
    if (apakah_kosong_2123()) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    cout << left << setw(10) << "|Nama|" << right << setw(5) << " |Umur|" << endl; // Memberikan penjelasan label pada data
    while (current != nullptr) {
        cout << left << setw(10) << current->Nama_2123 << right << setw(5) << current->Umur_2123 << endl; // Meluruskan data sesuai label
        current = current->next;
    }
}

int main() {
    inisialisasi_2123(); // Inisialisasi linked list

    // Menambahkan data ke linked list sesuai permintaan user
    cout << "\n||||||-------Program data link list by Dadya Vio Hendraksa_2123-------||||||" << endl;
    tambah_depan_2123("John", 19); 
    tambah_belakang_2123("Jane", 20);
    tambah_belakang_2123("Michael", 18);
    tambah_belakang_2123("Yusuke", 19);
    tambah_belakang_2123("Akechi", 20);
    tambah_belakang_2123("Hoshino", 18);
    tambah_belakang_2123("Karin", 18);

    // Menampilkan isi linked list sebelum operasi
    cout << "-----List data sebelum operasi dilakukan (A)-----" << endl;
    display(); // Menampilkan data
    cout << endl;

    // Operasi menghapus data Akechi
    cout << "-----Menghapus data 'Akechi' (B)-----" << endl;
    hapus_tengah_2123(5); // Menghapus data Akechi pada posisi 5
    display();
    cout << endl;

    // Operasi menambahkan data Futaba di antara John dan Jane
    cout << "-----Menambahkan data 'Futaba' diantara 'John' dan 'Jane' (C)-----" << endl;
    tambah_tengah_2123("Futaba", 18, 2); // Memasukkan data Futaba di posisi 2
    display();
    cout << endl;

    // Operasi menambahkan data Igor di awal
    cout << "-----Menambahkan data 'Igor' didepan (D)-----" << endl;
    tambah_depan_2123("Igor", 20);
    display();
    cout << endl;

    // Operasi mengubah data Michael menjadi Reyn
    cout << "-----Menghubah data 'Michael' menjadi 'Reyn' dan Tampilan seluruh data (E dan F)-----" << endl;
    ubah_tengah_2123("Reyn", 18, 5); // Michael pada posisi 5
    display();
    cout << endl;

    return 0;
}