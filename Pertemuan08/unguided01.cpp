#include <iostream> // Library untuk fungsi input-output C++
#include <cstring> // Library untuk fungsi string C
#include <vector> // Library untuk tipe data dinamis
#include <algorithm> // Library untuk fungsi sort()

using namespace std;

struct CharIndexPair_2123 { // Struktur data untuk menyimpan pasangan karakter dan indeks dalam array 
    char character;
    int index;
};

vector<int> binary_search_all_2123(CharIndexPair_2123 dataArray[], int size, char target) { // Fungsi untuk mencari semua indeks karakter target dalam array pasangan karakter dan indeks dengan algoritma pencarian biner sederhana.
    vector<int> result; // Array dinamis untuk menyimpan indeks hasil pencarian karakter target dalam array pasangan karakter dan indeks.
    for (int i = 0; i < size; i++) {
        if (dataArray[i].character == target) {
            result.push_back(dataArray[i].index); // Menambahkan indeks karakter target ke dalam array hasil pencarian.
        }
    }
    return result;
}

int main() {
    char sentence_2123[100]; // Array karakter untuk menyimpan kalimat yang diinputkan pengguna.
    char cari_2123; 
    char ulangi_2123;

    do {
        cout << "\n\tBINARY SEARCH HURUF" << endl;
        cout << "\nInput kalimat: ";
        cin.getline(sentence_2123, 100); // Menggunakan getline() agar kalimat yang diinputkan dapat mengandung spasi.

        int size_2123 = strlen(sentence_2123); // Menghitung panjang kalimat yang diinputkan.
        CharIndexPair_2123 dataArray[100]; // Array statis untuk menyimpan pasangan karakter dan indeks

        // Membuat array pasangan karakter dan indeks aslinya
        for (int i = 0; i < size_2123; i++) {
            dataArray[i] = {sentence_2123[i], i};
        }

        cout << "\nData awal: " << sentence_2123 << endl;

        cout << "\nInput huruf yang di cari: ";
        cin >> cari_2123;

        // Pencarian biner sederhana
        vector<int> indices = binary_search_all_2123(dataArray, size_2123, cari_2123); 

        if (!indices.empty()) { // Jika indeks ditemukan dalam array pasangan karakter dan indeks.
            // Sort hasil jika lebih dari satu indeks ditemukan
            if (indices.size() > 1) {
                sort(indices.begin(), indices.end());
            }

            cout << "\nHuruf '" << cari_2123 << "' ditemukan pada indeks ke-";
            for (int i = 0; i < indices.size(); i++) { // Menampilkan semua indeks karakter target dalam kalimat.
                if (i > 0) cout << ", ";
                cout << indices[i];
            }
            cout << " dalam kalimat.\n";
        } else {
            cout << "\nHuruf '" << cari_2123 << "' tidak ditemukan dalam kalimat.\n";
        }

        cout << "\nApakah Anda ingin mengulangi program binary search huruf ini? (y/n): ";
        cin >> ulangi_2123;
        cin.ignore(); // Membersihkan buffer agar getline() tidak terganggu

    } while (ulangi_2123 == 'y' || ulangi_2123 == 'Y'); // Ulangi program jika pengguna mengetikkan 'y' atau 'Y'

    cout << "\nTerima kasih telah menggunakan program binary search huruf ini.\n";

    return 0;
}