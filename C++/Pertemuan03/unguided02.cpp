#include <iostream> // mengatur input output
#include <iomanip> // mengatur layout output
#include <string> // mengatur string

using namespace std; // menggunakan standar library

class Node { // Deklarasi Class Node untuk Double Linked List
public: // Deklarasi Public untuk Class Node agar bisa diakses di luar class Node
    string Nama_Produk; 
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList { // Deklarasi Class DoublyLinkedList untuk Double Linked List
public: // Deklarasi Public untuk Class DoublyLinkedList agar bisa diakses di luar class DoublyLinkedList
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
 
    void tambah_produk_2123(string Nama_Produk, int harga) { // Menambahkan produk ke dalam linked list di bagian atas
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk; // Menambahkan nama produk ke dalam linked list
        newNode->harga = harga; // Menambahkan harga produk ke dalam linked list
        newNode->prev = nullptr; // Pointer prev menunjuk ke nullptr
        newNode->next = head; // Pointer next menunjuk ke head
        if (head != nullptr) {
            head->prev = newNode; // Pointer prev head menunjuk ke newNode jika head tidak nullptr
        }
        else {
            tail = newNode; // Tail menunjuk ke newNode jika head nullptr
        }
        head = newNode; // Head menunjuk ke newNode setelah newNode di tambahkan ke linked list
    }

    void hapus_produk_2123() { // Menghapus produk teratas dari linked list
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool ubah_produk_2123(string Nama_Produk_Lama, string Nama_Produk_Baru, int Harga_Baru) { // Mengubah data produk berdasarkan nama produk
        Node* current = head;
        while (current != nullptr) { // Looping selama current tidak nullptr
            if (current->Nama_Produk == Nama_Produk_Lama) { // Jika nama produk lama ditemukan di linked list maka lakukan perubahan data produk
                current->Nama_Produk = Nama_Produk_Baru; // Mengubah nama produk lama menjadi nama produk baru
                current->harga = Harga_Baru; // Mengubah harga produk lama menjadi harga produk baru
                return true;
            }
            current = current->next;
        }
        return false; // Mengembalikan false jika data produk tidak ditemukan
    }

    void sisipkan_posisi_tertentu_2123(string Nama_Produk, int harga, int posisi) { // Menambahkan data produk pada posisi tertentu
        if (posisi < 1) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk;
        newNode->harga = harga;
        if (posisi == 1) { // Jika posisi adalah 1 maka tambahkan data produk di depan linked list
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            else {
                tail = newNode;
            }
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) { // Looping sampai posisi sebelum posisi yang diinginkan (Posisi - 1)
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode; // Pointer prev node setelah current menunjuk ke newNode jika node setelah current tidak nullptr
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void hapus_posisi_tertentu_2123(int posisi) { // Menghapus data produk pada posisi tertentu
        if (posisi < 1 || head == nullptr) { // Jika posisi kurang dari 1 atau head nullptr maka tampilkan pesan
            cout << "Posisi tidak ada atau list kosong" << endl;
            return;
        }
        Node* current = head;
        if (posisi == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete current;
            return;
        }
        for (int i = 1; current != nullptr && i < posisi; ++i) { // Looping sampai posisi yang diinginkan
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    void hapus_semua_2123() { // Menghapus semua data produk
        Node* current = head; // Pointer current menunjuk ke head
        while (current != nullptr) {
            Node* temp = current; // Pointer temp menunjuk ke current
            current = current->next; // Pointer current menunjuk ke node selanjutnya
            delete temp; // Menghapus node temp (node head sebelumnya)
        }
        head = nullptr;
        tail = nullptr;
    }

    void display_2123() { // Menampilkan data produk
        Node* current = head;
        cout << "\nBerikut daftar Produk dan harga yang tersedia saat ini:" << endl;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl; // Menampilkan header tabel nama produk dan harga
        while (current != nullptr) {
            cout << left << setw(20) << current->Nama_Produk << current->harga << endl;  // Menampilkan produk dan harga dan meluruskan ke tabel
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list; // Deklarasi objek list dari class DoublyLinkedList
    
    list.tambah_produk_2123("Hanasui", 30000);
    list.tambah_produk_2123("Wardah", 50000);
    list.tambah_produk_2123("Skintific", 100000);
    list.tambah_produk_2123("Somethinc", 150000);
    list.tambah_produk_2123("Originote", 60000);

    cout << "\n||||||-------Selamat datang di Toko Skincare Purwokerto by Dadya Vio Hendraksa_2123-------||||||" << endl;
    list.display_2123();

    while (true) { // Looping menu utama
        cout << "\nMenu Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan; // Deklarasi variabel pilihan
        cout << "Pilih Menu: ";
        cin >> pilihan; // Input pilihan menu
        switch (pilihan) { // Switch case untuk memilih menu
        case 1: {
            string Nama_Produk;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> Nama_Produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.tambah_produk_2123(Nama_Produk, harga); // Memanggil fungsi tambah_produk
            cout << "Produk berhasil ditambahkan teratas" << endl;
            break;
        }
        case 2: {
            list.hapus_produk_2123(); // Memanggil fungsi hapus_produk
            cout << "Produk teratas berhasil dihapus" << endl;
            break;
        }
        case 3: { 
            string Nama_Produk_Lama, Nama_Produk_Baru;
            int Harga_Baru;
            cout << "Input nama produk lama: ";
            cin >> Nama_Produk_Lama;
            cout << "Input nama produk baru: ";
            cin >> Nama_Produk_Baru;
            cout << "Input harga baru: ";
            cin >> Harga_Baru;
            bool updated = list.ubah_produk_2123(Nama_Produk_Lama, Nama_Produk_Baru, Harga_Baru); // Memanggil fungsi ubah_produk
            if (!updated) {
                cout << "Data produk tidak ditemukan" << endl;
            }
            else {
                cout << "Data produk berhasil diupdate" << endl;
            }
            break;
        }
        case 4: {
            string Nama_Produk;
            int harga, position;
            cout << "Input nama produk: ";
            cin >> Nama_Produk;
            cout << "Input harga: ";
            cin >> harga;
            cout << "Input posisi: ";
            cin >> position;
            list.sisipkan_posisi_tertentu_2123(Nama_Produk, harga, position); // Memanggil fungsi sisipkan_posisi_tertentu
            cout << "Produk berhasil ditambahkan pada posisi " << position << endl;
            break;
        }
        case 5: {
            int position;
            cout << "Input posisi yang ingin dihapus: ";
            cin >> position;
            list.hapus_posisi_tertentu_2123(position); // Memanggil fungsi hapus_posisi_tertentu

            break;
        }
        case 6: {
            list.hapus_semua_2123(); // Memanggil fungsi hapus_semua
            break;
        }
        case 7: {
            list.display_2123(); // Memanggil fungsi display
            break;
        }
        case 8: {
            return 0; // Exit program
        }
        default: {
            cout << "Input Invalid" << endl; 
            break;
        }
        }
    }
    return 0;
}