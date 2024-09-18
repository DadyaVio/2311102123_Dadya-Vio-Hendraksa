#include <iostream> // Library yang digunakan untuk fungsi input-output
#include <string> // Library yang digunakan untuk tipe data string
#include <vector> // Library yang digunakan untuk tipe data vector
#include <iomanip>  // Library yang digunakan untuk fungsi setw()

using namespace std;

const int TABLE_SIZE = 100; // Konstant untuk ukuran tabel hash map (100)

class HashNode { // Class HashNode untuk setiap node pada tabel hash map (berisi nama, NIM, dan nilai)
public: // Atribut-atribut yang dimiliki oleh class HashNode (nama, NIM, dan nilai)
    string name; 
    string nim; 
    int nilai; 

    HashNode(string name, string nim, int nilai) { // Constructor untuk class HashNode dengan parameter nama, NIM, dan nilai
        this->name = name; 
        this->nim = nim; 
        this->nilai = nilai; 
    }
};

class HashMap { // Class HashMap untuk tabel hash map (berisi array of vector dari HashNode)
private: // Atribut-atribut yang dimiliki oleh class HashMap (array of vector dari HashNode) 
    vector<HashNode*> table[TABLE_SIZE]; // Array of vector dari HashNode dengan ukuran TABLE_SIZE (100)

public: // Method-method yang dimiliki oleh class HashMap (insert, remove, searchByNIM, searchByScoreRange, print)
    int hashFunc_2123(string key) { // Method hashFunc_2123 untuk menghitung nilai hash dari key (nama)
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE; // Mengembalikan nilai hash dari key (nama) dengan modulo TABLE_SIZE (100)
    }

    void insert_2123(string name, string nim, int nilai) { // Method insert_2123 untuk menambahkan data Mahasiswa ke dalam tabel hash map
        int hash_val = hashFunc_2123(name); // Menghitung nilai hash dari nama Mahasiswa yang akan ditambahkan ke dalam tabel hash map
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->nim = nim;
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, nim, nilai)); // Menambahkan data Mahasiswa ke dalam tabel hash map pada indeks hash_val
        cout << "Data Mahasiswa dengan nama " << name << " berhasil ditambahkan." << endl;
    }

    void remove_2123(string name) { // Method remove_2123 untuk menghapus data Mahasiswa dari tabel hash map berdasarkan nama Mahasiswa
        int hash_val = hashFunc_2123(name); // Menghitung nilai hash dari nama Mahasiswa yang akan dihapus dari tabel hash map
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); ++it) { // Iterasi untuk mencari data Mahasiswa berdasarkan nama
            if ((*it)->name == name) {
                delete *it;
                table[hash_val].erase(it); // Menghapus data Mahasiswa dari tabel hash map jika ditemukan berdasarkan nama Mahasiswa
                cout << "Data Mahasiswa dengan nama " << name << " berhasil dihapus." << endl;
                return;
            }
        }
    }

    void searchByNIM_2123(string nim) { // Method searchByNIM_2123 untuk mencari data Mahasiswa berdasarkan NIM Mahasiswa
        bool found = false; // Inisialisasi variabel found dengan nilai false
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto node : table[i]) { // Iterasi untuk mencari data Mahasiswa berdasarkan NIM Mahasiswa
                if (node->nim == nim) {
                    cout << "\n==================== HASIL MENCARI DATA NIM MAHASISWA ====================" << endl;
                    cout << left << "| " << setw(25) << "Nama"
                         << "| " << setw(20) << "NIM"
                         << "| " << setw(15) << "Nilai"
                         << " |" << endl;
                    cout << "--------------------------------------------------------------------------" << endl;
                    cout << "| " << left << setw(25) << node->name
                         << "| " << left << setw(20) << node->nim
                         << "| " << left << setw(15) << node->nilai << " |" << endl;
                    cout << "--------------------------------------------------------------------------" << endl;
                    found = true;
                    return;
                }
            }
        }
        if (!found) { // Jika data Mahasiswa tidak ditemukan berdasarkan NIM Mahasiswa
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        }
    }

    void searchByScoreRange_2123(int minScore, int maxScore) { // Method searchByScoreRange_2123 untuk mencari data Mahasiswa berdasarkan rentang nilai Mahasiswa
        bool found = false;
        cout << "\n=============== HASIL MENCARI DATA RENTANG NILAI MAHASISWA ===============" << endl;
        cout << left << "| " << setw(25) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(15) << "Nilai"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto node : table[i]) { // Iterasi untuk mencari data Mahasiswa berdasarkan rentang nilai Mahasiswa
                if (node->nilai >= minScore && node->nilai <= maxScore) { // Jika nilai Mahasiswa berada dalam rentang nilai yang dicari
                    cout << "| " << left << setw(25) << node->name
                         << "| " << left << setw(20) << node->nim
                         << "| " << left << setw(15) << node->nilai << " |" << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada data Mahasiswa dengan nilai antara " << minScore << " dan " << maxScore << "." << endl;
        }
        cout << "--------------------------------------------------------------------------" << endl;
    }

    void print_2123() { // Method print_2123 untuk menampilkan seluruh data Mahasiswa yang ada di dalam tabel hash map
        cout << "\n============================= DATA MAHASISWA =============================" << endl;
        cout << left << "| " << setw(25) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(15) << "Nilai"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto pair : table[i]) { // Iterasi untuk menampilkan seluruh data Mahasiswa yang ada di dalam tabel hash map
                cout << "| " << left << setw(25) << pair->name
                     << "| " << left << setw(20) << pair->nim
                     << "| " << left << setw(15) << pair->nilai << " |" << endl;
            }
        }
        cout << "--------------------------------------------------------------------------" << endl;
    }
};

int main() { // Fungsi utama pada program ini untuk menjalankan program utama
    HashMap pt_2123;
    int choice_2123;
    string name_2123;
    string nim_2123;
    int nilai_2123;
    int minScore, maxScore;

    do { // Looping untuk menampilkan menu pilihan yang tersedia
        cout << "\n =================== DAFTAR NILAI MAHASISWA by Dadya Vio H ===================" << endl;
        cout << "1. Tambah data Mahasiswa" << endl;
        cout << "2. Menghapus data Mahasiswa" << endl;
        cout << "3. Mencari data Nim Mahasiswa" << endl;
        cout << "4. Mencari data Rentang Nilai Mahasiswa" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice_2123; // Input pilihan menu yang diinginkan

        switch (choice_2123) { // Switch case untuk memilih menu pilihan yang diinginkan
            case 1: // Jika pilihan menu adalah 1 (Tambah data Mahasiswa)
                cout << "\n =================== TAMBAHKAN DATA MAHASISWA ===================" << endl;
                cout << "Masukkan nama: ";
                cin >> name_2123;
                cout << "Masukkan NIM: ";
                cin >> nim_2123;
                cout << "Masukkan nilai: ";
                cin >> nilai_2123;
                pt_2123.insert_2123(name_2123, nim_2123, nilai_2123); // Memanggil method insert_2123 untuk menambahkan data Mahasiswa
                break;
            case 2: // Jika pilihan menu adalah 2 (Menghapus data Mahasiswa)
                cout << "\n =================== MENGHAPUS DATA MAHASISWA ===================" << endl;
                cout << "Masukkan nama: ";
                cin >> name_2123;
                pt_2123.remove_2123(name_2123); // Memanggil method remove_2123 untuk menghapus data Mahasiswa
                break;
            case 3: // Jika pilihan menu adalah 3 (Mencari data Nim Mahasiswa)
                cout << "\n =================== MENCARI DATA NIM MAHASISWA ===================" << endl;
                cout << "Masukkan NIM: ";
                cin >> nim_2123;
                pt_2123.searchByNIM_2123(nim_2123); // Memanggil method searchByNIM_2123 untuk mencari data Mahasiswa berdasarkan NIM Mahasiswa
                break;
            case 4: // Jika pilihan menu adalah 4 (Mencari data Rentang Nilai Mahasiswa)
                cout << "\n =================== MENCARI DATA RENTANG NILAI MAHASISWA ===================" << endl;
                cout << "Masukkan nilai minimum: ";
                cin >> minScore;
                cout << "Masukkan nilai maksimum: ";
                cin >> maxScore;
                pt_2123.searchByScoreRange_2123(minScore, maxScore); // Memanggil method searchByScoreRange_2123 untuk mencari data Mahasiswa berdasarkan rentang nilai Mahasiswa
                break;
            case 5: // Jika pilihan menu adalah 5 (Tampilkan)
                pt_2123.print_2123(); // Memanggil method print_2123 untuk menampilkan seluruh data Mahasiswa yang ada di dalam tabel hash map
                break;
            case 6: // Jika pilihan menu adalah 6 (Keluar)
                cout << "Program telah selesai digunakan. Terima kasih." << endl; // Menampilkan pesan bahwa program telah selesai digunakan
                break;
            default: // Jika pilihan menu tidak tersedia
                cout << "Input menu tidak tersedia." << endl;
        }
    } while (choice_2123 != 6); // Looping akan terus berjalan selama pilihan menu yang diinputkan bukan 6 (Keluar)

    return 0;
}