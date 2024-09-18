#include <iostream> // Library untuk fungsi input-output C++

using namespace std;

int main() {
    int data_2123[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array data
    int cari_2123 = 4; // Angka yang dicari
    int jumlah_angka_4 = 0; // Jumlah angka 4 dalam data
    const int ukuran_2123 = sizeof(data_2123) / sizeof(data_2123[0]); // Ukuran array

    // Menampilkan data array
    cout << "\nData array: ";
    for (int i = 0; i < ukuran_2123; i++) {
        cout << data_2123[i] << " "; // Menampilkan nilai setiap elemen array
    }
    cout << endl;

    // Algoritma Sequential Search
    for (int i = 0; i < ukuran_2123; i++) { // Looping untuk setiap elemen dalam array data (10 elemen)
        if (data_2123[i] == cari_2123) { // Jika elemen saat ini sama dengan angka yang dicari (4)
            jumlah_angka_4++; // Tambahkan jumlah angka 4
        }
    }

    cout << "\nBanyaknya angka 4 dalam data diatas adalah: " << jumlah_angka_4 << endl; // Tampilkan jumlah angka 4 dalam data

    return 0;
}