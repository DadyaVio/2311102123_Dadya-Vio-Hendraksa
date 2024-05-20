#include <iostream> // Library untuk fungsi input-output C++
#include <map> // Library untuk tipe data map

using namespace std;

int hitung_vokal_2123(const char kalimat_2123[]) { // Fungsi untuk menghitung jumlah huruf vokal dalam kalimat yang diinputkan pengguna
    int jumlah_vokal = 0;
    for (int i = 0; kalimat_2123[i] != '\0'; i++) { // Looping untuk setiap karakter dalam kalimat hingga karakter null terminator (akhir string)
        char huruf = tolower(kalimat_2123[i]); // Ubah huruf menjadi lowercase untuk mempermudah perbandingan
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            jumlah_vokal++; // Jika huruf adalah huruf vokal, tambahkan jumlah vokal
        }
    }
    return jumlah_vokal; // Kembalikan jumlah vokal
}

int main() {
    char kalimat_2123[100]; // Array karakter untuk menyimpan kalimat yang diinputkan pengguna
    char ulangi_2123;

    do {
        cout << "\nInput kalimat: ";
        cin.getline(kalimat_2123, 100); // Menggunakan getline() agar kalimat yang diinputkan dapat mengandung spasi dan karakter khusus lainnya

        int jumlah_vokal = hitung_vokal_2123(kalimat_2123); // Hitung jumlah huruf vokal dalam kalimat yang diinputkan pengguna

        cout << "\nJumlah huruf vokal dalam kalimat adalah: " << jumlah_vokal << endl;

        map<char, int> vokal_map; // Map untuk menyimpan jumlah kemunculan setiap huruf vokal dalam kalimat yang diinputkan pengguna
        for (int i = 0; kalimat_2123[i] != '\0'; i++) { // Looping untuk setiap karakter dalam kalimat hingga karakter null terminator (akhir string)
            char huruf = tolower(kalimat_2123[i]); // Ubah huruf menjadi lowercase untuk mempermudah perbandingan dan penyimpanan dalam map
            if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
                vokal_map[huruf]++;
            }
        }

        for (auto const &pair : vokal_map) { // Looping untuk setiap pasangan key-value dalam map vokal_map (auto digunakan untuk menentukan tipe data secara otomatis)
            cout << pair.first << " = " << pair.second << endl; // Tampilkan huruf vokal dan jumlah kemunculannya dalam kalimat
        }

        cout << "\nUlangi? (y/n): ";
        cin >> ulangi_2123;
        cin.ignore(); // Membersihkan input buffer
    } while (ulangi_2123 == 'y' || ulangi_2123 == 'Y'); // Ulangi program jika pengguna mengetikkan 'y' atau 'Y'

    return 0;
}