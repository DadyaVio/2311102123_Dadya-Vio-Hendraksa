/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream>
#include <cmath> // Library untuk fungsi dalam operasi matematika

using namespace std;

int pilihan_2123, desimal_2123; // Data primitif int untuk pilihan menu pilihan_2123 dan angka decimal_2123
long biner_2123; // Data primitif long untuk angka biner_2123

void DadyaKonversiBilangan_2123() { // Fungsi void untuk tampilan menu pilihan user
    cout << "\nPilih operasi konversi bilangan:\n";
    cout << "1. Desimal ke Biner\n";
    cout << "2. Biner ke Desimal\n";
    cout << "Masukkan pilihan (1 atau 2) (0 = keluar): ";
    cin >> pilihan_2123;
}

long DesimalKeBiner(int desimal_2123) { // Fungsi untuk mengonversi bilangan desimal ke biner
    long biner_2123 = 0;
    int sisa, i = 1, langkah = 1;

    while (desimal_2123 != 0) {
        sisa = desimal_2123 % 2;
        desimal_2123 /= 2;
        biner_2123 += sisa * i;
        i *= 10;
    }

    return biner_2123; // Mengembalikan nilai hasil konversi biner
}

int BinerKeDesimal(long biner_2123) { // Fungsi untuk mengonversi bilangan biner ke desimal
    int desimal_2123 = 0, i = 0, sisa;

    while (biner_2123 != 0) {
        sisa = biner_2123 % 10;
        biner_2123 /= 10;
        desimal_2123 += sisa * pow(2, i);
        ++i;
    }

    return desimal_2123; // Mengembalikan nilai hasil konversi desimal
}

int main() {
    do { // Perulangan untuk menu pilihan user 
        DadyaKonversiBilangan_2123();
        switch (pilihan_2123) { // Switch case pilihan user
            case 1: // User memiih 1 maka fungsi konversi desimal ke biner akan dijalankan
                cout << "\nMasukkan bilangan desimal: ";
                cin >> desimal_2123; // Input desimal dari user
                cout << "Hasil konversi ke biner: " << DesimalKeBiner(desimal_2123) << endl; // Pemanggilan hasil fungsi konversi desimal ke biner
            break;
            case 2: // User memiih 1 maka fungsi konversi biner ke desimal akan dijalankan
                cout << "\nMasukkan bilangan biner: ";
                cin >> biner_2123; // Input biner dari user
                cout << "Hasil konversi ke desimal: " << BinerKeDesimal(biner_2123) << endl; // Pemanggilan hasil fungsi konversi biner ke desimal
            break;
            default:
                cout << "Anda telah keluar dari program.\n";
                break;
        }
    } while (pilihan_2123 != 0); // Jika memilih 0 switch case default akan dijalankan dan program berakhir

    return 0;
}