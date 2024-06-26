#include <iostream> // Library standar yang digunakan untuk input dan output
#include <iomanip> // Library standar yang digunakan untuk manipulasi input dan output
#include <string> // Library standar yang digunakan untuk manipulasi string

using namespace std;

struct Node { // Membuat struct Node untuk menyimpan data mahasiswa yang berisi nama dan umur
    string Nama_2123;
    int Umur_2123;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void inisialisasi_2123() { // Inisialisasi awal linked list dengan head dan tail bernilai nullptr
    head = nullptr;
    tail = nullptr;
}

bool apakah_kosong_2123() { // Mengecek apakah linked list kosong atau tidak
    return head == nullptr;
}

void tambah_depan_2123(string Nama, int Umur) { // Menambahkan data mahasiswa di depan linked list
    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }
}

void tambah_belakang_2123(string Nama, int Umur) { // Menambahkan data mahasiswa di belakang linked list
    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;
    newNode->next = nullptr;

    if (apakah_kosong_2123()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void tambah_tengah_2123(string Nama, int Umur, int Posisi) { // Menambahkan data mahasiswa di tengah linked list berdasarkan posisi yang diinputkan oleh user
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Maka di tambah ke depan." << endl;
        tambah_depan_2123(Nama, Umur);
        return;
    }

    Node* newNode = new Node; // Membuat node baru untuk menyimpan data mahasiswa yang akan ditambahkan ke linked list
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;

    Node* current = head;
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi - 1) { // Mencari posisi node yang akan ditambahkan data mahasiswanya berdasarkan posisi yang diinputkan oleh user
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void hapus_depan_2123() { // Menghapus data mahasiswa di depan linked list
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void hapus_belakang_2123() { // Menghapus data mahasiswa di belakang linked list 
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail) { // Mencari node yang berada sebelum node yang akan dihapus di belakang linked list 
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
}

void hapus_tengah_2123(int Posisi) { // Menghapus data mahasiswa di tengah linked list berdasarkan posisi yang diinputkan oleh user
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr; // Node sebelum node yang akan dihapus di tengah linked list 
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) { // Mencari posisi node yang akan dihapus data mahasiswanya berdasarkan posisi yang diinputkan oleh user
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) {
        cout << "Posisi tidak ada, Maka tida ada yang dihapus" << endl;
        return;
    }

    previous->next = current->next; // Menghapus node yang ditunjuk oleh current 
    delete current;

    if (previous->next == nullptr) {
        tail = previous;
    }
}

void ubah_depan_2123(string Nama, int Umur) { // Mengubah data mahasiswa di depan linked list
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    head->Nama_2123 = Nama;
    head->Umur_2123 = Umur;
}

void ubah_belakang_2123(string Nama, int Umur) { // Mengubah data mahasiswa di belakang linked list 
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    tail->Nama_2123 = Nama;
    tail->Umur_2123 = Umur;
}

void ubah_tengah_2123(string Nama, int Umur, int Posisi) { // Mengubah data mahasiswa di tengah linked list berdasarkan posisi yang diinputkan oleh user
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat diubah." << endl;
        return;
    }

    Node* current = head;
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) { // Mencari posisi node yang akan diubah datanya berdasarkan posisi yang diinputkan oleh user
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) {
        cout << "Posisi tidak ada, Maka tidak ada yang diubah" << endl;
        return;
    }

    current->Nama_2123 = Nama;
    current->Umur_2123 = Umur;
}

void display() { // Menampilkan data mahasiswa yang ada di linked list 
    if (apakah_kosong_2123()) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    cout << left << setw(10) << "|Nama|" << right << setw(5) << " |Umur|" << endl; // Menampilkan header tabel data mahasiswa 
    while (current != nullptr) {
        cout << left << setw(10) << current->Nama_2123 << right << setw(5) << current->Umur_2123 << endl; // Menampilkan data mahasiswa dan merapikan tampilan data mahasiswa
        current = current->next;
    }
}

int main() { // Fungsi utama yang akan dieksekusi pertama kali saat program dijalankan
    inisialisasi_2123(); // Memanggil fungsi inisialisasi_2123 untuk menginisialisasi linked list dengan head dan tail bernilai nullptr

    cout << "\n||||||-------Program data link list by Dadya Vio Hendraksa_2123-------||||||" << endl;
    
    int jumlah_data; // Deklarasi variabel jumlah_data untuk menyimpan jumlah data mahasiswa yang akan diinputkan oleh user
    cout << "Masukkan jumlah data mahasiswa: ";
    cin >> jumlah_data; // Menginputkan jumlah data mahasiswa yang akan diinputkan oleh user

    for (int i = 0; i < jumlah_data; ++i) { // Perulangan untuk menginputkan data mahasiswa sebanyak jumlah_data yang diinputkan oleh user
        string nama;
        int umur;
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Umur: ";
        cin >> umur;
        tambah_belakang_2123(nama, umur); // Memanggil fungsi tambah_belakang_2123 untuk menambahkan data mahasiswa ke linked list
    }
    
    cout << "\nData Mahasiswa Terbaru:" << endl;
    display(); // Memanggil fungsi display untuk menampilkan data mahasiswa yang ada di linked list

    int pilihan; // Deklarasi variabel pilihan untuk menyimpan pilihan menu yang diinputkan oleh user
    do { // Perulangan untuk menampilkan menu pilihan yang dapat dilakukan oleh user
        cout << "\nMenu Data Mahasiswa:\n1. Tambah Data di Depan\n2. Tambah Data di Belakang\n3. Tambah Data di Tengah\n";
        cout << "4. Hapus Data di Depan\n5. Hapus Data di Belakang\n6. Hapus Data di Tengah\n";
        cout << "7. Ubah Data di Depan\n8. Ubah Data di Belakang\n9. Ubah Data di Tengah\n";
        cout << "10. Menampilkan Data\n0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan; // Menginputkan pilihan menu yang diinginkan oleh user

        switch (pilihan) { // Percabangan switch case untuk mengeksekusi fungsi sesuai dengan pilihan menu yang diinputkan oleh user
            case 1: { // Pilihan menu 1 untuk menambahkan data mahasiswa di depan linked list
                string nama;
                int umur;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Umur: ";
                cin >> umur;
                tambah_depan_2123(nama, umur); // Memanggil fungsi tambah_depan_2123 untuk menambahkan data mahasiswa ke linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 2: { // Pilihan menu 2 untuk menambahkan data mahasiswa di belakang linked list
                string nama;
                int umur;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Umur: ";
                cin >> umur;
                tambah_belakang_2123(nama, umur); // Memanggil fungsi tambah_belakang_2123 untuk menambahkan data mahasiswa ke linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 3: { // Pilihan menu 3 untuk menambahkan data mahasiswa di tengah linked list
                string nama;
                int umur, posisi;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Umur: ";
                cin >> umur;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                tambah_tengah_2123(nama, umur, posisi); // Memanggil fungsi tambah_tengah_2123 untuk menambahkan data mahasiswa ke linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 4: // Pilihan menu 4 untuk menghapus data mahasiswa di depan linked list
                hapus_depan_2123(); // Memanggil fungsi hapus_depan_2123 untuk menghapus data mahasiswa di depan linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            case 5: // Pilihan menu 5 untuk menghapus data mahasiswa di belakang linked list
                hapus_belakang_2123(); // Memanggil fungsi hapus_belakang_2123 untuk menghapus data mahasiswa di belakang linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            case 6: { // Pilihan menu 6 untuk menghapus data mahasiswa di tengah linked list
                int posisi;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                hapus_tengah_2123(posisi); // Memanggil fungsi hapus_tengah_2123 untuk menghapus data mahasiswa di tengah linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 7: { // Pilihan menu 7 untuk mengubah data mahasiswa di depan linked list
                string nama;
                int umur;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan Umur Baru: ";
                cin >> umur;
                ubah_depan_2123(nama, umur); // Memanggil fungsi ubah_depan_2123 untuk mengubah data mahasiswa di depan linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 8: { // Pilihan menu 8 untuk mengubah data mahasiswa di belakang linked list
                string nama;
                int umur;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan Umur Baru: ";
                cin >> umur;
                ubah_belakang_2123(nama, umur); // Memanggil fungsi ubah_belakang_2123 untuk mengubah data mahasiswa di belakang linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 9: { // Pilihan menu 9 untuk mengubah data mahasiswa di tengah linked list
                string nama;
                int umur, posisi;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan Umur Baru: ";
                cin >> umur;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                ubah_tengah_2123(nama, umur, posisi); // Memanggil fungsi ubah_tengah_2123 untuk mengubah data mahasiswa di tengah linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display();
                break;
            }
            case 10: // Pilihan menu 10 untuk menampilkan data mahasiswa yang ada di linked list
                cout << "\nData Mahasiswa Terbaru:" << endl;
                display(); // Memanggil fungsi display untuk menampilkan data mahasiswa yang ada di linked list
                break;
            case 0: // Pilihan menu 0 untuk keluar dari program
                cout << "Terima kasih!" << endl;
                break;
            default: // Pilihan default jika pilihan menu yang diinputkan oleh user tidak valid
                cout << "Input pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0); // Perulangan akan terus berjalan selama pilihan menu yang diinputkan oleh user bukan 0

    return 0;
}