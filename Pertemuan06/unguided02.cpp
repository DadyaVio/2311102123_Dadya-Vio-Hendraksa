#include <iostream> // Library untuk input output
#include <string> // Library untuk string
#include <stack> // Library untuk stack
#include <algorithm> // Library untuk count

using namespace std;

// Fungsi untuk membersihkan kata dari karakter non-alfabet dan mengubahnya menjadi huruf kecil
string bersihkan_Dan_Kecilkan_Hurufnya_2123(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) { // Hanya menambahkan karakter alfabet ke string bersih
            cleanStr += tolower(c); // Mengubah karakter menjadi huruf kecil jika karakter tersebut adalah alfabet 
        }
    }
    return cleanStr;
}

// Fungsi untuk melakukan pembalikan kalimat menggunakan stack
string balik_Kalimat_2123(string kalimat) {
    stack<char> tumpukanKarakter; // Membuat stack untuk menampung karakter yang akan dibalik
    string kalimat_Terbalik_2123;

    // Membersihkan dan mengubah menjadi huruf kecil
    kalimat = bersihkan_Dan_Kecilkan_Hurufnya_2123(kalimat);

    // Menempatkan setiap karakter ke dalam tumpukan
    for (char c : kalimat) {
        if (c != ' ') {
            tumpukanKarakter.push(c); // Menambahkan karakter ke dalam tumpukan jika karakter tersebut bukan spasi 
        } else {
            // Mengosongkan tumpukan dan menambahkan kata yang telah dibalik ke kalimatTerbalik
            while (!tumpukanKarakter.empty()) {
                kalimat_Terbalik_2123 += tumpukanKarakter.top(); // Menambahkan karakter yang di-pop dari tumpukan ke kalimatTerbalik 
                tumpukanKarakter.pop(); // Menghapus karakter dari tumpukan
            }
            kalimat_Terbalik_2123 += ' '; // Menambahkan spasi setelah setiap kata yang telah dibalik
        }
    }

    // Menambahkan kata terakhir yang telah dibalik
    while (!tumpukanKarakter.empty()) { // Mengosongkan tumpukan dan menambahkan kata yang telah dibalik ke kalimatTerbalik 
        kalimat_Terbalik_2123 += tumpukanKarakter.top(); // Menambahkan karakter yang di-pop dari tumpukan ke kalimatTerbalik 
        tumpukanKarakter.pop(); // Menghapus karakter dari tumpukan
    }

    return kalimat_Terbalik_2123; // Mengembalikan kalimat yang telah dibalik
}

int main() {
    string kalimat_2123;
    char lanjutkan_2123;

    do {
        cout << "\nMasukkan kata atau kalimat (minimal 3 kata): ";
        getline(cin, kalimat_2123); // Mengambil inputan dari user berupa kata atau kalimat

        // Mengecek apakah kalimat memiliki minimal 3 kata
        int jumlah_Spasi_2123 = count(kalimat_2123.begin(), kalimat_2123.end(), ' '); // Menghitung jumlah spasi pada kalimat 
        int jumlah_Kata_2123 = jumlah_Spasi_2123 + 1; // Jumlah kata adalah jumlah spasi ditambah 1 

        if (jumlah_Kata_2123 < 3) {
            cout << "Masukkan minimal 3 kata!" << endl;
        } else {
            string kalimatTerbalik = balik_Kalimat_2123(kalimat_2123); // Memanggil fungsi balikKalimat dengan parameter kalimat 
            cout << "Kalimat Terbalik: " << kalimatTerbalik << endl; 
        }

        cout << "Apakah ingin memasukkan kata atau kalimat lagi? (y/n): ";
        cin >> lanjutkan_2123;
        cin.ignore(); // Membersihkan buffer dari newline sebelumnya
    } while (lanjutkan_2123 == 'y' || lanjutkan_2123 == 'Y'); // Perulangan jika user ingin memasukkan kata atau kalimat lagi

    return 0;
}