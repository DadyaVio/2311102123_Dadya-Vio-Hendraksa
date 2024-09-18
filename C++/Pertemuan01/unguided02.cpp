/*
Pernyataan tentang Struct dan Class yang telah saya simpulkan dengan pengamatan dan pemahaman dari jurnal dan ebook yang ada di google schoolar.
Dadya Vio Hendraksa 2311102123
*/

/*
Struct
Struct merupakan sebuah jenis khusus dari class, Pada dasarnya anggota class memiliki sifat private. Akan tetapi struct berbeda, 
struct disini memili sifat sebaliknya yaitu public sehingga dapat diakses dengan bebas. Di dalam struct juga memiliki fungsi yang
spesifik yaitu untuk pengelompokan data yang dibuat dengan tipe data yang berlainan pada program.
*/

/*
Class
Class disini sudah diketahui bahwa memiliki sifat private yang tidak sembarang user dapat mengakses dari keluar class. Class juga 
memiliki sifat untuk penggabungan data dan operasinya menjadi satu kesatuan. Di class kita tidak dapat membuat inisial variabel saat 
deklarasi. Sehingga membutuhkan pada fungsi public untuk private data yang ada sehingga harus mengatur nilai awal dan mengambil nilai 
atribut private.
*/

#include <iostream>
#include <string>

using namespace std;

struct Creator_2123 { // Struct Creator_2123 yang berisi tipe data string nama, negara, pekerjaan dan int umur.
    string Nama_2123;
    string Negara_2123;
    string Pekerjaan_2123;
    int Umur_2123;
};

class Karya_2123 { // Class Karya_2123 yang berisi tipe data string nama karya, genre, dan int tahun terbit yang akses private kemudian dibuat menjadi public.
private:
    string NamaKarya_2123;
    string Genre_2123;
    int TahunTerbit_2123;

public:
    // Metode ini untuk mengatur nilai awal atribut private yang ada.
    Karya_2123(string namaKarya, string genre, int tahunTerbit)
        : NamaKarya_2123(namaKarya), Genre_2123(genre), TahunTerbit_2123(tahunTerbit) {}

    // Fungsi ini untuk mengambil nilai atribut private yang sudah di deklarasikan.
    string GetNamaKarya() const { return NamaKarya_2123; }
    string GetGenre() const { return Genre_2123; }
    int GetTahunTerbit() const { return TahunTerbit_2123; }
};

int main() {
    cout << "=========== Struct dan Class Biography Akira Toriyama oleh Dadya Vio Hendraksa ===========" << endl;
    // Pendeklarasian Struct Creator_2123
    Creator_2123 creator{"Akira Toriyama", "Jepang", "Mangaka", 68};
    cout << "\n|||| Biography Akira Toriyama ||||" << endl;
    cout << "Nama: " << creator.Nama_2123 << endl;
    cout << "Negara: " << creator.Negara_2123 << endl;
    cout << "Pekerjaan: " << creator.Pekerjaan_2123 << endl;
    cout << "Umur: " << creator.Umur_2123 << endl;
    // Pendeklarasian Class Karya_2123
    Karya_2123 karya("Dragon Ball", "Fantasi", 1984);
    cout << "\n|||| Karya Akira Toriyama ||||" << endl;
    cout << "Nama Karya: " << karya.GetNamaKarya() << endl;
    cout << "Genre: " << karya.GetGenre() << endl;
    cout << "Tahun Terbit: " << karya.GetTahunTerbit() << endl;

    return 0;
}