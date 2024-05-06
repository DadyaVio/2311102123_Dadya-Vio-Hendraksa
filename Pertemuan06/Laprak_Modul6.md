# <h1 align="center">Laporan Praktikum Modul 6 - STACK</h1>
<p align="center">Dadya Vio Hendraksa - 2311102123</p>

## Dasar Teori

1. Pengertian Hash Table<br/>
Hash Table adalah struktur data yang efisien digunakan untuk mengatur dan mengelola data dengan kecepatan tinggi. Prinsip dasarnya adalah kunci-nilai, di mana setiap data memiliki kunci yang unik untuk mengaksesnya. Fungsi hash digunakan untuk mengubah kunci menjadi indeks dalam array, memungkinkan akses data secara langsung dengan perhitungan indeks. Ini memungkinkan operasi seperti pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan, kecuali jika terjadi konflik pada fungsi hash (collision). Hash Table sangat berguna untuk penyimpanan data yang efisien, pencarian data cepat berdasarkan kunci, dan implementasi struktur data lain seperti set dan map.<br/>
![Gambar Dasar Teori Part 1](Dasar-Teori_Part-1_Hash-Table.png)</br>

2. Fungsi, Kelebihan, Kekurangan Hash Table<br/>
Hash Table adalah sebuah struktur data yang efisien digunakan untuk menyimpan dan mengelola data dengan cepat. Fungsi utamanya meliputi penyimpanan data dengan efisien, pencetakan seluruh elemen dalam hash table, dan penggunaan fungsi hash untuk menetapkan lokasi key dalam tabel. Ini sangat berguna dalam mengelola data dengan frekuensi operasi insert, delete, dan search yang tinggi, serta dalam mengimplementasikan struktur data lain seperti set dan map.<br/>
Kelebihannya termasuk kemampuan hashing untuk melakukan operasi dengan waktu rata-rata konstan, memungkinkan penyimpanan data besar dalam hash table, pencarian data cepat berdasarkan key, dan efisiensi penyimpanan data.<br/>
Terdapat juga kekurangan seperti kemungkinan collision saat beberapa kunci memetakan data ke integer yang sama, kesulitan dalam pencetakan seluruh elemen hash table, keterbatasan dalam mencari elemen minimum atau maksimum, serta keterbatasan dalam ekspansi hash table dan pemborosan memory yang mungkin terjadi.</br>

3. Operasi Hash Table</br>
Hash Table adalah struktur data yang menyediakan beberapa operasi utama untuk mengelola dan memanipulasi data di dalamnya. Berikut adalah operasi-operasi utama pada Hash Table beserta penjelasannya:</br>
• Insert: Digunakan untuk menambahkan data baru ke dalam Hash Table. Ketika data ditambahkan, fungsi hash digunakan untuk menghitung kunci (key) data tersebut, yang kemudian digunakan untuk menentukan lokasi penyimpanan dalam Hash Table. Jika terjadi collision, seperti saat dua data memiliki kunci yang sama, teknik penanganan seperti chaining atau probing digunakan untuk menempatkan data baru di tempat yang sesuai.</br>
• Get (Search): Berfungsi untuk mencari data berdasarkan kunci (key) yang diberikan. Fungsi hash digunakan kembali untuk menemukan lokasi yang mungkin dari data dalam Hash Table. Jika data ditemukan, nilainya dikembalikan; jika tidak, biasanya nilai null atau indikator lain yang menunjukkan bahwa data tidak ditemukan dikembalikan.</br>
• Remove: Digunakan untuk menghapus data dari Hash Table berdasarkan kunci (key) yang diberikan. Sama seperti operasi pencarian, fungsi hash digunakan untuk menemukan lokasi data yang mungkin. Jika data ditemukan, maka data tersebut dihapus dari Hash Table. Pengelolaan collision juga perlu dipertimbangkan saat menghapus data.</br>
• Traverse: Berfungsi untuk mencetak atau menampilkan seluruh elemen yang ada dalam Hash Table. Biasanya dilakukan dengan mengunjungi setiap slot dalam Hash Table dan mencetak data yang terdapat di dalamnya. Namun, perlu diingat bahwa pencetakan semua elemen dalam Hash Table dapat menjadi tugas yang sulit atau memakan waktu, terutama jika Hash Table memiliki ukuran yang besar.</br>
Dengan menggunakan operasi-operasi tersebut, Hash Table mampu menyimpan, mencari, memperbarui, dan menghapus data dengan efisien. Akses ke data juga dapat dilakukan dengan waktu yang konstan, selama fungsi hash beroperasi secara optimal dan collision ditangani dengan baik.

4. Collision Resolution </br>
Collision Resolution adalah suatu teknik yang sangat penting dalam implementasi Hash Table. Dalam struktur data Hash Table, collision terjadi ketika dua atau lebih kunci data di-hash ke lokasi yang sama dalam tabel hash. Untuk menangani collision, terdapat dua pendekatan utama yang digunakan: Open Hashing (atau Chaining) dan Closed Hashing (atau Open Addressing).</br>
Open Hashing, atau yang dikenal juga sebagai Chaining, melibatkan penggunaan struktur data tambahan seperti linked list untuk menangani kasus collision. Setiap slot dalam tabel hash menyimpan pointer ke linked list yang berisi semua data yang di-hash ke slot tersebut. Ketika terjadi collision, data baru disisipkan ke dalam linked list yang sesuai dengan slot hash-nya. Keuntungan dari Open Hashing adalah bahwa tidak ada pemborosan ruang karena data dengan kunci yang sama dapat disimpan bersama dalam satu slot hash. Namun, ada overhead tambahan yang timbul karena perlu mengelola struktur data tambahan untuk setiap slot hash.</br>
Sementara itu, Closed Hashing, juga dikenal sebagai Open Addressing, mencoba untuk menyimpan semua data di dalam tabel hash tanpa menggunakan struktur data tambahan. Ketika terjadi collision, Closed Hashing mencari slot yang kosong di dalam tabel hash untuk menempatkan data yang bertabrakan. Ada beberapa teknik yang digunakan untuk menentukan slot yang kosong, seperti Linear Probing, Quadratic Probing, dan Double Hashing. Keuntungan dari Closed Hashing adalah penggunaan ruang yang lebih efisien karena tidak memerlukan struktur data tambahan. Namun, Closed Hashing dapat mengalami clustering, di mana slot kosong cenderung berdekatan, yang dapat menyebabkan kinerja menurun saat tabel hash menjadi lebih terisi.</br>
![Gambar Dasar Teori Part 2](Dasar-Teori_Part-2_Hash-Table.jpeg)</br>

## Guided 

### 1. Program Latihan l Stack

```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() { return (top == maksimal); }
bool isEmpty() { return (top == 0); }

void pushArrayBuku(string data) {
  if (isFull()) {
    cout << "Data telah penuh" << endl;
  } else {
    arrayBuku[top] = data;
    top++;
  }
}
void popArrayBuku() {
  if (isEmpty()) {
    cout << "Tidak ada data yang dihapus" << endl;
  } else {
    arrayBuku[top - 1] = "";
    top--;
  }
}
void peekArrayBuku(int posisi) {
  if (isEmpty()) {
    cout << "Tidak ada data yang bisa dilihat" << endl;
  } else {
    int index = top;
    for (int i = 1; i <= posisi; i++) {
      index--;
    }
    cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
  }
}
int countStack() { return top; }
void changeArrayBuku(int posisi, string data) {
  if (posisi > top) {
    cout << "Posisi melebihi data yang ada" << endl;
  } else {
    int index = top;
    for (int i = 1; i <= posisi; i++) {
      index--;
    }
    arrayBuku[index] = data;
  }
}
void destroyArraybuku() {
  for (int i = top; i >= 0; i--) {
    arrayBuku[i] = "";
  }
  top = 0;
}
void cetakArrayBuku() {
  if (isEmpty()) {
    cout << "Tidak ada data yang dicetak" << endl;
  } else {
    for (int i = top - 1; i >= 0; i--) {
      cout << arrayBuku[i] << endl;
    }
  }
}
int main() {
  pushArrayBuku("Kalkulus");
  pushArrayBuku("Struktur Data");
  pushArrayBuku("Matematika Diskrit");
  pushArrayBuku("Dasar Multimedia");
  pushArrayBuku("Inggris");
  cetakArrayBuku();
  cout << "\n";
  cout << "Apakah data stack penuh? " << isFull() << endl;
  cout << "Apakah data stack kosong? " << isEmpty() << endl;
  peekArrayBuku(2);
  popArrayBuku();
  cout << "Banyaknya data = " << countStack() << endl;
  changeArrayBuku(2, "Bahasa Jerman");
  cetakArrayBuku();
  cout << "\n";
  destroyArraybuku();
  cout << "Jumlah data setelah dihapus: " << top << endl;
  cetakArrayBuku();
  return 0;
}
```
 

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.</br>

### Contoh:</br>

### Kalimat : ini</br>
### Kalimat tersebut adalah polindrom</br>

### Kalimat : telkom</br>
### Kalimat tersebut adalah bukan polindrom</br>

```C++
/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream> // Library untuk input output
#include <string> // Library untuk string
#include <stack> // Library untuk stack

using namespace std;

// Fungsi untuk membersihkan kata dari karakter non-alfabet dan mengubahnya menjadi huruf kecil
string bersihkan_dan_ubah_ke_huruf_kecil_2123(string str) { 
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
    char lanjutkan_2123;
    do {
        string input;
        cout << "\nMasukkan kata atau kalimat: ";
        getline(cin, input); // Mengambil inputan dari user berupa kata atau kalimat 

        // Membersihkan dan mengubah menjadi huruf kecil
        string membersihkan_input_2123 = bersihkan_dan_ubah_ke_huruf_kecil_2123(input);

        if (Palindrom_2123(membersihkan_input_2123)) { // Memanggil fungsi Palindrom_2123 dengan parameter membersihkan_input_2123
            cout << "Kata atau kalimat tersebut adalah : Palindrom" << endl;
        } else { // Jika fungsi Palindrom_2123 mengembalikan nilai false
            cout << "Kata atau kalimat tersebut adalah : Bukan Palindrom" << endl;
        }

        cout << "Ingin memasukkan kata atau kalimat lain? (y/n): ";
        cin >> lanjutkan_2123;
        cin.ignore(); // Membersihkan newline dari buffer
    } while (lanjutkan_2123 == 'y' || lanjutkan_2123 == 'Y');

    return 0;
}
```

#### Output:
![Screenshot Output Unguided 1 Part 1](Output_Unguided-01_Part-1_Dadya-Vio-H.png)</br>
![Screenshot Output Unguided 1 Part 2](Output_Unguided-01_Part-2_Dadya-Vio-H.png)</br>
![Screenshot Output Unguided 1 Part 3](Output_Unguided-01_Part-3_Dadya-Vio-H.png)</br>
Program tersebut merupakan implementasi dari hash map dengan chaining yang digunakan untuk menyimpan data mahasiswa, termasuk nama, NIM, dan nilai. Program ini memiliki beberapa metode, antara lain:<br/>
• insert_2123: Digunakan untuk menambahkan data mahasiswa ke dalam hash map.<br/>
• remove_2123: Digunakan untuk menghapus data mahasiswa dari hash map.<br/>
• searchByNIM_2123: Digunakan untuk mencari data mahasiswa berdasarkan NIM mahasiswa.<br/>
• searchByScoreRange_2123: Digunakan untuk mencari data mahasiswa berdasarkan rentang nilai mahasiswa.<br/>
• print_2123: Digunakan untuk menampilkan seluruh data mahasiswa yang ada di dalam hash map.<br/>
Program tersebut juga menyediakan beberapa pilihan menu yang dapat digunakan oleh pengguna, seperti menambahkan data mahasiswa, menghapus data mahasiswa, mencari data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan rentang nilai, dan menampilkan seluruh data mahasiswa yang ada di dalam hash map.

## Kesimpulan
Kesimpulannya tentang materi Hash table yaitu merupakan struktur data yang efisien digunakan untuk menyimpan dan mengakses data dengan cepat berdasarkan kunci (key) tertentu. Terdapat beberapa metode yang umumnya digunakan dalam hash table, salah satunya adalah metode chaining. Metode chaining memungkinkan beberapa data dengan kunci yang sama disimpan dalam satu slot hash table. Dalam implementasi hash table, terdapat beberapa fungsi dasar yang umumnya tersedia, antara lain:<br/>
• Insert: Digunakan untuk memasukkan data ke dalam hash table.<br/>
• Get: Digunakan untuk mencari data berdasarkan kunci (key).<br/>
• Remove: Digunakan untuk menghapus data berdasarkan kunci.<br/>
• Traverse: Digunakan untuk menampilkan semua data yang ada di dalam hash table.<br/>
Penggunaan hash table sangat berguna dalam berbagai konteks, seperti penyimpanan data karyawan, mahasiswa, atau data lainnya yang memerlukan pengindeksan berdasarkan kunci tertentu. Dengan metode chaining, pengguna dapat dengan efisien menyimpan dan mengakses data yang berpotensi memiliki kunci yang sama. Kesimpulannya, hash table dengan metode chaining merupakan alat yang powerful dalam mengelola dan mengakses data dengan cepat berdasarkan kunci tertentu. Implementasinya dapat diadaptasi untuk berbagai kebutuhan, sehingga sangat berguna dalam pengembangan berbagai jenis aplikasi dan sistem.

## Referensi
[1] Jasson Prestiliano., Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data. Salatiga: Universitas Kristen Satya Wacana, 2020.<br/>
[2] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish, 2021.<br/>
[3] Malik, D.S., C++ Programming. Boston: Course Technology, 2023.