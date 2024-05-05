#include <iostream> // Library untuk input output
#include <string> // Library untuk string
#include <stack> // Library untuk stack

using namespace std;

// Fungsi untuk membersihkan kata dari karakter non-alfabet dan mengubahnya menjadi huruf kecil
string ubah_ke_huruf_kecil_2123(string str) { 
    string cleanStr; 
    for (char &c : str) {
        if (isalpha(c)) { // Hanya menambahkan karakter alfabet ke string bersih 
            cleanStr += tolower(c); // Mengubah karakter menjadi huruf kecil
        }
    }
    return cleanStr; // Mengembalikan string yang sudah dibersihkan
}

bool Palindrom_2123(string str) { // Fungsi untuk mengecek apakah kata/kalimat tersebut palindrom atau bukan
    stack<char> charStack;
    int length = str.length(); // Panjang kata/kalimat yang akan dicek palindrom atau bukan

    // Menempatkan setengah pertama kata/kalimat ke dalam stack
    for (int i = 0; i < length / 2; i++) {
        charStack.push(str[i]);
    }

    // Membandingkan setengah kedua kata/kalimat dengan karakter yang di-pop dari stack
    int start = length / 2;
    if (length % 2 != 0) {
        start++; // Lewati karakter tengah jika panjang ganjil
    }
    for (int i = start; i < length; i++) { // Membandingkan setengah kedua kata/kalimat dengan karakter yang di-pop dari stack 
        if (charStack.empty() || str[i] != charStack.top()) { // Jika stack kosong atau karakter tidak sama dengan karakter yang di-pop dari stack
            return false;
        }
        charStack.pop(); // Menghapus karakter dari stack jika karakter sama dengan karakter yang di-pop dari stack 
    }

    return true;
}

int main() {
    char lanjut;
    do {
        string input;
        cout << "\nMasukkan kata atau kalimat: ";
        getline(cin, input); // Mengambil inputan dari user berupa kata atau kalimat 

        // Membersihkan dan mengubah menjadi huruf kecil
        string membersihkan_input_2123 = ubah_ke_huruf_kecil_2123(input);

        if (Palindrom_2123(membersihkan_input_2123)) { // Memanggil fungsi Palindrom_2123 dengan parameter membersihkan_input_2123
            cout << "Kata atau kalimat tersebut adalah : Palindrom" << endl;
        } else { // Jika fungsi Palindrom_2123 mengembalikan nilai false
            cout << "Kata atau kalimat tersebut adalah : Bukan Palindrom" << endl;
        }

        cout << "Ingin memasukkan kata atau kalimat lain? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // Membersihkan newline dari buffer
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}