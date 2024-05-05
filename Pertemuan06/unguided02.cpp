#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// Fungsi untuk membersihkan kata dari karakter non-alfabet dan mengubahnya menjadi huruf kecil
string bersihkanDanKecilkan(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}

// Fungsi untuk melakukan pembalikan kalimat menggunakan stack
string balikKalimat(string kalimat) {
    stack<char> tumpukanKarakter;
    string kalimatTerbalik;

    // Membersihkan dan mengubah menjadi huruf kecil
    kalimat = bersihkanDanKecilkan(kalimat);

    // Menempatkan setiap karakter ke dalam tumpukan
    for (char c : kalimat) {
        if (c != ' ') {
            tumpukanKarakter.push(c);
        } else {
            // Mengosongkan tumpukan dan menambahkan kata yang telah dibalik ke kalimatTerbalik
            while (!tumpukanKarakter.empty()) {
                kalimatTerbalik += tumpukanKarakter.top();
                tumpukanKarakter.pop();
            }
            kalimatTerbalik += ' '; // Menambahkan spasi setelah setiap kata yang telah dibalik
        }
    }

    // Menambahkan kata terakhir yang telah dibalik
    while (!tumpukanKarakter.empty()) {
        kalimatTerbalik += tumpukanKarakter.top();
        tumpukanKarakter.pop();
    }

    return kalimatTerbalik;
}

int main() {
    string kalimat;
    cout << "Masukkan kata atau kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Mengecek apakah kalimat memiliki minimal 3 kata
    int jumlahSpasi = count(kalimat.begin(), kalimat.end(), ' ');
    int jumlahKata = jumlahSpasi + 1;

    if (jumlahKata < 3) {
        cout << "Masukkan minimal 3 kata!" << endl;
        return 1;
    }

    string kalimatTerbalik = balikKalimat(kalimat);
    cout << "Kalimat Terbalik: " << kalimatTerbalik << endl;

    return 0;
}
