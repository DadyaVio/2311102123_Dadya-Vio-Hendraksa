/* 
Pernyataan tentang perbedaan dari map dan array yang telah saya telaah dari jurnal dan beberapa ebook.
Dadya Vio Hendraksa 2311102123
*/

/*
Perbedaan Map dan Array:
1. Tipe data
   Array hanya bisa memiliki elemen dengan tipe data yang sama.
   Map dapat memiliki elemen yang tipe datanya berbeda dalam satu kelompok data.
2. Penggunaannya
   Array menggunakan pengelompokkan data dengan indeks yang sudah tetap yaitu dari indeks 0.
   Map lebih fleksibel karena pengelompokkannya menggunakan nilai kunci yang telah kita buat,
   jadi tidak ada ketetapan.
3. Pengubahan elemen
   Array untuk perubahan elemn sangat tidak dinamis, karena tidak dapat mengubah salah satu elemen saja.
   Map lebih fleksibel dan dinamis karena dapat mengubah salah satu elemn saja.
4. Ukuran
   Array ukurannya sudah ditentukan saat pembuatanya/deklarasinya dan tidak bisa diubah.
   Map ukurannya bisa diubah lebih kecil atau lebih besar tergantung dengan banyak elemen yang ada.
*/

#include <iostream>
#include <map> // Library untuk melakukan fungsi map

using namespace std;

int main() {
    
    // Deklarasi map dengan key int dan value string
    map<int, string> Nilai_2123;
  
    // Tamnbahkan elemen string yang di inginkan untuk map
    Nilai_2123[1] = "4   = A";
    Nilai_2123[2] = "3,5 = AB";
    Nilai_2123[3] = "3   = B";
    Nilai_2123[4] = "2,5 = BC";
    Nilai_2123[5] = "2   = C";
    Nilai_2123[6] = "1   = D";
    Nilai_2123[7] = "0   = E";

    cout << "\n-----||||Nilai Mutu dan Nilai Bobot ITTP by Dadya Vio H.||||-----" << endl;
    for (int i = 1; i <= Nilai_2123.size(); ++i) { // Melakukan pengulangan untuk untuk mengoutputkan elemen yang telah di masukkan pada map
        cout << "No Urut Nilai Mutu." << i << "     " << Nilai_2123[i] << endl; // Menampilkan elemen map yang sudah di ulang
    }

    return 0;
}