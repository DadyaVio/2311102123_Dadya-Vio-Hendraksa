# <h1 align="center">Laporan Praktikum Modul 2 - ARRAY</h1>
<p align="center">Dadya Vio Hendraksa - 2311102123</p>

## Dasar Teori

Array merupakan struktur data yang paling dasar. Satu blok memori dialokasikan untuk seluruh array untuk menampung elemen-elemen array.  Elemen  array  dapat  diakses  dalam  waktu  yang  konstan  dengan  menggunakan  indeks elemen tertentu sebagai subskrip. Untuk  mengakses  elemen  array,  alamat  elemen  dihitung  sebagai  offset  dari  alamat dasar   array   dan   satu   perkalian   diperlukan   untuk   menghitung   apa   yang   seharusnya ditambahkan  ke  alamat  dasar  untuk  mendapatkan  alamat  memori  elemen. 

Keuntungan dari Array<br/>
   - Sederhana dan mudah digunakan
   - Akses lebih cepat ke elemen (akses konstan)<br/>

Kekurangan Array<br/>
   - Mengalokasikan  semua  memori  yang  dibutuhkan  di  depan  dan  membuang-buang ruang memori untuk indeks dalam array yang kosong.
   - Ukuran    tetap:    Ukuran    larik    bersifat    statis    (tentukan    ukuran    larik    sebelum menggunakannya).
   - Alokasi  satu  blok:  Untuk  mengalokasikan  array  itu  sendiri  di  awal,  terkadang  tidak mungkin  untuk  mendapatkan  memori  untuk  array  yang  lengkap(jika  ukuran  array besar).
   - Penyisipan berbasis posisi kompleks: Untuk menyisipkan elemen pada posisi tertentu, kita  mungkin  perlu  menggeser  elemen  yang  ada.  Ini  akan  membuat  posisi  bagi  kita untuk memasukkan elemen baru pada posisi yang diinginkan. Jika posisi di mana kita ingin menambahkan elemen di awal, maka operasi pemindahan lebih mahal.

1. Array 1 Dimensi<br/>
Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu. Array satu dimensi merupakan kumpulan data yang disusun dalam satu baris atau kolom, terdiri dari elemen-elemen dengan tipe yang sama. Setiap elemen dalam array satu dimensi dapat diakses menggunakan indeksnya. Array satu dimensi sering digunakan untuk menampung sejumlah elemen dengan tipe data yang sama, seperti angka, nilai, atau teks. Penggunaan array memungkinkan penyimpanan dan akses data secara terstruktur dalam satu variabel, yang lebih efisien daripada menggunakan sejumlah variabel terpisah.

2. Array 2 Dimensi<br/>
Array dua dimensi adalah struktur data yang terdiri dari baris dan kolom, di mana setiap elemen dapat diakses menggunakan indeks yang terdapat di dalamnya. Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris, sementara indeks kolom menunjukkan posisi elemen dalam kolom. Jadi, array dua dimensi digunakan untuk menyimpan data yang terorganisir dalam bentuk tabel dengan baris dan kolom, atau untuk data yang memiliki struktur yang lebih kompleks, seperti matriks.

3. Array 3 Dimensi/Multidimensi<br/>
Array tiga dimensi adalah tipe array yang terdiri dari satu baris, satu kolom, dan beberapa lapisan. Array tiga dimensi sering digunakan untuk menyimpan data dalam bentuk tabel yang meliputi baris, kolom, dan halaman, atau untuk menyimpan data yang memiliki struktur yang kompleks seperti matriks, sehingga memiliki ukuran memori yang lebih besar. Ini memungkinkan penyimpanan dan akses data yang terstruktur dalam satu variabel, meningkatkan efisiensi dalam pengelolaan data. Array tiga dimensi sering digunakan untuk menyimpan data dalam bentuk tabel yang meliputi baris, kolom, dan halaman, atau untuk menyimpan data yang memiliki struktur yang kompleks seperti matriks. Untuk mengakses elemen dalam array tiga dimensi, kita dapat menggunakan perulangan nested.

## Guided 

### 1. Program Latihan Single Linked List

```C++
#include <iostream>

using namespace std;
///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
  int data;
  Node * next;
};
Node * head;
Node * tail;
//Inisialisasi Node
void init() {
  head = NULL;
  tail = NULL;
}
// Pengecekan
bool isEmpty() {
  if (head == NULL)
    return true;
  else
    return false;
}
//Tambah Depan
void insertDepan(int nilai) {
  //Buat Node baru
  Node * baru = new Node;
  baru -> data = nilai;
  baru -> next = NULL;
  if (isEmpty() == true) {
    head = tail = baru;
    tail -> next = NULL;
  } else {
    baru -> next = head;
    head = baru;
  }
}
//Tambah Belakang
void insertBelakang(int nilai) {
  //Buat Node baru
  Node * baru = new Node;
  baru -> data = nilai;
  baru -> next = NULL;
  if (isEmpty() == true) {
    head = tail = baru;
    tail -> next = NULL;
  } else {
    tail -> next = baru;
    tail = baru;
  }
}
//Hitung Jumlah List
int hitungList() {
  Node * hitung;
  hitung = head;
  int jumlah = 0;
  while (hitung != NULL) {
    jumlah++;
    hitung = hitung -> next;
  }
  return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi diluar jangkauan" << endl;
  } else if (posisi == 1) {
    cout << "Posisi bukan posisi tengah" <<
      endl;
  } else {
    Node * baru, * bantu;
    baru = new Node();
    baru -> data = data;
    // tranversing
    bantu = head;
    int nomor = 1;
    while (nomor < posisi - 1) {
      bantu = bantu -> next;
      nomor++;
    }
    baru -> next = bantu -> next;
    bantu -> next = baru;
  }
}
//Hapus Depan
void hapusDepan() {
  Node * hapus;
  if (isEmpty() == false) {
    if (head -> next != NULL) {
      hapus = head;
      head = head -> next;
      delete hapus;
    } else {
      head = tail = NULL;
    }
  } else {
    cout << "List kosong!" << endl;
  }
}
//Hapus Belakang
void hapusBelakang() {
  Node * hapus;
  Node * bantu;
  if (isEmpty() == false) {
    if (head != tail) {
      hapus = tail;
      bantu = head;
      while (bantu -> next != tail) {
        bantu = bantu -> next;
      }
      tail = bantu;
      tail -> next = NULL;
      delete hapus;
    } else {
      head = tail = NULL;
    }
  } else {
    cout << "List kosong!" << endl;
  }
}
//Hapus Tengah
void hapusTengah(int posisi) {
  Node * hapus, * bantu, * bantu2;
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi di luar jangkauan" << endl;
  } else if (posisi == 1) {
    cout << "Posisi bukan posisi tengah" <<
      endl;
  } else {
    int nomor = 1;
    bantu = head;
    while (nomor <= posisi) {
      if (nomor == posisi - 1) {
        bantu2 = bantu;
      }
      if (nomor == posisi) {
        hapus = bantu;
      }
      bantu = bantu -> next;
      nomor++;
    }
    bantu2 -> next = bantu;
    delete hapus;
  }
}
//Ubah Depan
void ubahDepan(int data) {
  if (isEmpty() == false) {
    head -> data = data;
  } else {
    cout << "List masih kosong!" << endl;
  }
}
//Ubah Tengah
void ubahTengah(int data, int posisi) {
  Node * bantu;
  if (isEmpty() == false) {
    if (posisi < 1 || posisi > hitungList()) {
      cout << "Posisi di luar jangkauan" <<
        endl;
    } else if (posisi == 1) {
      cout << "Posisi bukan posisi tengah" <<
        endl;
    } else {
      bantu = head;
      int nomor = 1;
      while (nomor < posisi) {
        bantu = bantu -> next;
        nomor++;
      }
      bantu -> data = data;
    }
  } else {
    cout << "List masih kosong!" << endl;
  }
}
//Ubah Belakang
void ubahBelakang(int data) {
  if (isEmpty() == false) {
    tail -> data = data;
  } else {
    cout << "List masih kosong!" << endl;
  }
}
//Hapus List
void clearList() {
  Node * bantu, * hapus;
  bantu = head;
  while (bantu != NULL) {
    hapus = bantu;
    bantu = bantu -> next;
    delete hapus;
  }
  head = tail = NULL;
  cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil() {
  Node * bantu;
  bantu = head;
  if (isEmpty() == false) {
    while (bantu != NULL) {
      cout << bantu -> data << ends;
      bantu = bantu -> next;
    }
    cout << endl;
  } else {
    cout << "List masih kosong!" << endl;
  }
}
int main() {
  init();
  insertDepan(3);
  tampil();
  insertBelakang(5);
  tampil();
  insertDepan(2);
  tampil();
  insertDepan(1);
  tampil();
  hapusDepan();
  tampil();
  hapusBelakang();
  tampil();
  insertTengah(7, 2);
  tampil();
  hapusTengah(2);
  tampil();
  ubahDepan(1);
  tampil();
  ubahBelakang(8);
  tampil();
  ubahTengah(11, 2);
  tampil();
  return 0;
}
```
Program diatas ini merupakan input array 3 dimensi. Dimana user akan  menginputkan nilai elemen setiap bari dan kolom yang ada. Dimana disini dideklarasikan array arr[2][3][3]; maka kita akan input sesuai kondisi yang ada pada program tersebut. Setelahnya input array ini akan ditampilkan menjadi data array untuk melihat apakah benar semua nilai inputnya. Terakhir yaitu menampilkan susunan array yang ada pada data arry yang tadi kita inputkan. Disini program menggunakan nested for 3 kali.

### 2. Program Latihan Double Linked List

```C++
#include <iostream>

using namespace std;
class Node {
  public: int data;
  Node * prev;
  Node * next;
};
class DoublyLinkedList {
  public: Node * head;
  Node * tail;
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  void push(int data) {
    Node * newNode = new Node;
    newNode -> data = data;
    newNode -> prev = nullptr;
    newNode -> next = head;
    if (head != nullptr) {
      head -> prev = newNode;
    } else {
      tail = newNode;
    }
    head = newNode;
  }
  void pop() {
    if (head == nullptr) {
      return;
    }
    Node * temp = head;
    head = head -> next;
    if (head != nullptr) {
      head -> prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
  }
  bool update(int oldData, int newData) {
    Node * current = head;
    while (current != nullptr) {
      if (current -> data == oldData) {
        current -> data = newData;
        return true;
      }
      current = current -> next;
    }
    return false;
  }
  void deleteAll() {
    Node * current = head;
    while (current != nullptr) {
      Node * temp = current;
      current = current -> next;
      delete temp;
    }
    head = nullptr;
    tail = nullptr;
  }
  void display() {
    Node * current = head;
    while (current != nullptr) {
      cout << current -> data << " ";
      current = current -> next;
    }
    cout << endl;
  }
};
int main() {
  DoublyLinkedList list;
  while (true) {
    cout << "1. Add data" << endl;
    cout << "2. Delete data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Clear data" << endl;
    cout << "5. Display data" << endl;
    cout << "6. Exit" << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: {
      int data;
      cout << "Enter data to add: ";
      cin >> data;
      list.push(data);
      break;
    }
    case 2: {
      list.pop();
      break;
    }
    case 3: {
      int oldData, newData;
      cout << "Enter old data: ";
      cin >> oldData;
      cout << "Enter new data: ";
      cin >> newData;
      bool updated = list.update(oldData,
        newData);
      if (!updated) {
        cout << "Data not found" << endl;
      }
      break;
    }
    case 4: {
      list.deleteAll();
      break;
    }
    case 5: {
      list.display();
      break;
    }
    case 6: {
      return 0;
    }
    default: {
      cout << "Invalid choice" << endl;
      break;
    }
    }
  }
  return 0;
}
```
Program diatas ini berguna untuk mencari nilai maksimal dari elemen array yang telah diinputkan user. Jadi program ini hanya menggunakan array 1 dimensi maka tidak akan menggunakan nested for. Pertama user akan diminta untuk menentukan penjang untuk elemen array nya. Contoh kita input 3 maka selanjutnya kita akan mengisi nilai elemen array 1 dimensi tersebut dari indeks 0 sampai indeks 2 yang kemudian akan dicari nilai max dari elemen menggunakan percabangan if di dalam for. Terakhir tinggal memanggil nilai maks yang telah ditemukan.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: </br> a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.</br> ![Screenshot Soal Unguided 1](Soal_Unguided-01_Dadya-Vio-H.png)<br/> b. Hapus data Akechi<br/> c. Tambahkan data berikut diantara John dan Jane : Futaba, 18<br/> d. Tambahkan data berikut diawal : Igor, 20<br/> e. Ubah data Michael menjadi : Reyn, 18<br/> f. Tampilkan seluruh data

```C++
/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream> // mengatur input output
#include <iomanip> // mengatur layout output
#include <string> // mengatur string

using namespace std; // menggunakan standar library

// Deklarasi Struct Node
struct Node {
    string Nama_2123;
    int Umur_2123;
    Node* next; // Pointer next
};

Node* head = nullptr; // Deklarasi head
Node* tail = nullptr; // Deklarasi tail

// Inisialisasi Linked List
void inisialisasi_2123() {
    head = nullptr;
    tail = nullptr;
}

// Mengecek apakah linked list kosong
bool apakah_kosong_2123() {
    return head == nullptr;
}

// Menambah data di depan linked list
void tambah_depan_2123(string Nama, int Umur) {
    Node* newNode = new Node; // Membuat node baru
    newNode->Nama_2123 = Nama; // Menambahkan data Nama
    newNode->Umur_2123 = Umur; // Menambahkan data Umur
    newNode->next = head; // Pointer next menunjuk ke head
    head = newNode; // Head menunjuk ke newNode

    if (tail == nullptr) {
        tail = newNode;
    }
}

// Menambah data di belakang linked list
void tambah_belakang_2123(string Nama, int Umur) {
    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;
    newNode->next = nullptr; // Pointer next menunjuk ke nullptr

    if (apakah_kosong_2123()) {
        head = tail = newNode; // Jika kosong, head dan tail menunjuk ke newNode
    } else {
        tail->next = newNode; // Pointer next tail menunjuk ke newNode
        tail = newNode; // Tail menunjuk ke newNode
    }
}

// Menambah data di tengah linked list berdasarkan posisi data
void tambah_tengah_2123(string Nama, int Umur, int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) { // Jika posisi kurang dari sama dengan 1 atau linked list kosong maka tambah di depan linked list
        cout << "Posisi tidak valid atau list kosong, Maka di tambah ke depan." << endl;
        tambah_depan_2123(Nama, Umur);
        return;
    }

    Node* newNode = new Node;
    newNode->Nama_2123 = Nama;
    newNode->Umur_2123 = Umur;

    Node* current = head; // Pointer current menunjuk ke head linked list sekarang
    int currentPosition = 1; // Inisialisasi posisi saat ini adalah 1 (head) linked list sekarang

    while (current->next != nullptr && currentPosition < Posisi - 1) { // Looping sampai posisi sebelum posisi yang diinginkan (Posisi - 1)
        current = current->next; // Pointer current menunjuk ke node selanjutnya
        currentPosition++; // Posisi saat ini bertambah
    }

    newNode->next = current->next; // Pointer next newNode menunjuk ke node setelah current
    current->next = newNode; // Pointer next current menunjuk ke newNode
}

// Menghapus data di depan linked list
void hapus_depan_2123() {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* temp = head; // Pointer temp menunjuk ke head 
    head = head->next; // Pointer head menunjuk ke node selanjutnya
    delete temp; // Menghapus node temp (node head sebelumnya)

    if (head == nullptr) {
        tail = nullptr;
    }
}

// Menghapus data di belakang linked list
void hapus_belakang_2123() {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    if (head == tail) {
        delete head; // Menghapus node head
        head = tail = nullptr; // Jika head dan tail sama, maka head dan tail menunjuk ke nullptr
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next; // Pointer current menunjuk ke node selanjutnya
    }
    delete tail;
    tail = current; // Pointer tail menunjuk ke node sebelumnya (node yang baru terakhir)
    tail->next = nullptr; // Pointer next tail menunjuk ke nullptr
}

// Menghapus data di tengah linked list berdasarkan posisi data
void hapus_tengah_2123(int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat dihapus." << endl;
        return;
    }

    Node* current = head; // Pointer current diinisialisasi head
    Node* previous = nullptr; // Pointer previous diinisialisasi nullptr
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) {
        cout << "Posisi tidak ada, Maka tida ada yang dihapus" << endl;
        return;
    }

    previous->next = current->next; // Pointer next previous menunjuk ke node setelah current (node yang dihapus)
    delete current; // Menghapus node current (node yang dihapus)

    if (previous->next == nullptr) {
        tail = previous; // Jika node yang dihapus adalah node terakhir, maka tail menunjuk ke node sebelumnya (node yang baru terakhir)
    }
}

// Mengubah data di depan linked list
void ubah_depan_2123(string Nama, int Umur) {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    head->Nama_2123 = Nama;
    head->Umur_2123 = Umur;
}

// Mengubah data di belakang linked list
void ubah_belakang_2123(string Nama, int Umur) {
    if (apakah_kosong_2123()) {
        cout << "List kosong, Maka tidak ada yang dapat diubah." << endl;
        return;
    }

    tail->Nama_2123 = Nama;
    tail->Umur_2123 = Umur;
}

// Mengbah data di tengah linked list berdasarkan posisi data
void ubah_tengah_2123(string Nama, int Umur, int Posisi) {
    if (Posisi <= 1 || apakah_kosong_2123()) {
        cout << "Posisi tidak valid atau list kosong, Jadi tidak ada yang dapat diubah." << endl;
        return;
    }

    Node* current = head;
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < Posisi) { // Looping sampai posisi yang diinginkan
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < Posisi) { // Jika posisi tidak ada maka tidak ada yang diubah
        cout << "Posisi tidak ada, Maka tidak ada yang diubah" << endl;
        return;
    }

    current->Nama_2123 = Nama;
    current->Umur_2123 = Umur;
}

// Tampilkan isi data linked list
void display() {
    if (apakah_kosong_2123()) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    cout << left << setw(10) << "|Nama|" << right << setw(5) << " |Umur|" << endl; // Memberikan penjelasan label pada data
    while (current != nullptr) {
        cout << left << setw(10) << current->Nama_2123 << right << setw(5) << current->Umur_2123 << endl; // Meluruskan data sesuai label
        current = current->next;
    }
}

int main() {
    inisialisasi_2123(); // Inisialisasi linked list

    // Menambahkan data ke linked list sesuai permintaan user
    cout << "\n||||||-------Program data link list by Dadya Vio Hendraksa_2123-------||||||" << endl;
    tambah_depan_2123("John", 19); 
    tambah_belakang_2123("Jane", 20);
    tambah_belakang_2123("Michael", 18);
    tambah_belakang_2123("Yusuke", 19);
    tambah_belakang_2123("Akechi", 20);
    tambah_belakang_2123("Hoshino", 18);
    tambah_belakang_2123("Karin", 18);

    // Menampilkan isi linked list sebelum operasi
    cout << "-----List data sebelum operasi dilakukan (A)-----" << endl;
    display(); // Menampilkan data
    cout << endl;

    // Operasi menghapus data Akechi
    cout << "-----Menghapus data 'Akechi' (B)-----" << endl;
    hapus_tengah_2123(5); // Menghapus data Akechi pada posisi 5
    display();
    cout << endl;

    // Operasi menambahkan data Futaba di antara John dan Jane
    cout << "-----Menambahkan data 'Futaba' diantara 'John' dan 'Jane' (C)-----" << endl;
    tambah_tengah_2123("Futaba", 18, 2); // Memasukkan data Futaba di posisi 2
    display();
    cout << endl;

    // Operasi menambahkan data Igor di awal
    cout << "-----Menambahkan data 'Igor' didepan (D)-----" << endl;
    tambah_depan_2123("Igor", 20);
    display();
    cout << endl;

    // Operasi mengubah data Michael menjadi Reyn
    cout << "-----Menghubah data 'Michael' menjadi 'Reyn' dan Tampilan seluruh data (E dan F)-----" << endl;
    ubah_tengah_2123("Reyn", 18, 5); // Michael pada posisi 5
    display();
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot Output Unguided 1](Output_Unguided-01_Dadya-Vio-H.png)
Program ini hanya menggunakan array 1 dimensi dengan batas max elemen 50, jadi pertama user akan langsung diminta untuk mengisi nilai elemenya, jika sudah dapat menginput tanda (.) untuk melanjutkan program. Di program terlihat bahwa batas max angka genap dan ganjil yaitu 50. Kemudian kita menggunakan looping for yang didalamnya ada percabangan if-else untuk memeriksa dan memilah elemen array yang kita masukkan menjadi angka genap dan angka ganjil. Maka selanjutnya kita buat looping for yang memperhatikan syaratnya juga untuk menampilkan data array yang telah kita masukkan semuanya. Selanjutnya yaitu menampilkan elemen array yang ber-angka genap dimana disini saya menggunakan looping for untuk menampilkan nilai dan percabangan if untuk memanggil nilai genapnya. Lanjut  untuk menampilkan elemen array yang angka ganjil juga sama menggunakan looping for untuk menampilkan nilai dan percabangan if untuk memanggil nilai ganjil dari if-else pemisahan diawal tadi.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.</br> ![Screenshot Soal Unguided 2 Part 1](Soal_Unguided-02_Part-1_Dadya-Vio-H.png)<br/> ![Screenshot Soal Unguided 2 Part 2](Soal_Unguided-02_Part-2_Dadya-Vio-H.png)<br/> Case:</br> 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific</br> 2. Hapus produk wardah</br> 3. Update produk Hanasui menjadi Cleora dengan harga 55.000</br> 4. Tampilkan menu seperti dibawah ini</br> Toko Skincare Purwokerto</br> 1. Tambah Data</br> 2. Hapus Data 3 Update Data</br> 4. Tambah Data Urutan Tertentu</br> 5. Hapus Data Urutan Tertentu</br> 6. Hapus Seluruh Data</br> 7. Tampilkan Data</br> 8. Exit</br> Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :</br> ![Screenshot Soal Unguided 2 Part 2](Soal_Unguided-02_Part-2_Dadya-Vio-H.png)

```C++
/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream>

using namespace std;

int main() {
    int A_2123, B_2123, C_2123; // Deklarasi variabel 3 dimensi isi array

    // Input user ukuran array tiga dimensi per dimensi
    cout << "\nPemprograman Array 3 Dimensi dengan julan dan ukuran elemen dari user by Dadya Vio Hendraksa" << endl;
    cout << "Inputkan jumlah elemen array dimensi A: ";
    cin >> A_2123; // input ukuran elemen array nilai A
    cout << "Inputkan jumlah elemen array dimensi B: ";
    cin >> B_2123; // input ukuran elemen array nilai B
    cout << "Inputkan jumlah elemen array dimensi C: ";
    cin >> C_2123; // input ukuran elemen array nilai C

    // Deklarasi dan inisialisasi 3 dimensi isi array
    int arr[A_2123][B_2123][C_2123];

    // Input elemen array yang telah ditetapkan
    for (int a = 0; a < A_2123; a++)  // Perulangan untuk input elemen array A
    {   for (int b = 0; b < B_2123; b++) // Perulangan untuk input elemen array B
        {   for (int c = 0; c < C_2123; c++) // Perulangan untuk input elemen array C
            {   cout << "Input Array 3 Dimensi[" << a << "][" << b << "][" << c << "] = ";
                cin >> arr[a][b][c];}
        }
        cout << endl;
    }

    // Menampilkan inputan elemen array yang telah di isi user
    cout << "Tampilan array 3 Dimensi:" << endl;
    for (int a = 0; a < A_2123; a++) // Perulangan untuk menampilkan input elemen array A
    {    for (int b = 0; b < B_2123; b++) // Perulangan untuk menampilkan input elemen array B
        {   for (int c = 0; c < C_2123; c++) // Perulangan untuk menampilkan input elemen array C
            {   cout << arr[a][b][c] << " ";}
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot Output Unguided 2](Output_Unguided-02_Dadya-Vio-H.png)
Program ini menggunakan 3 dimensi yang dimana kita harus input untuk jumlah elemen yang akan kita isi nantinya. disini saya menggunakan A, B, C untuk inisial dimensinya. pertama user akan diminta untuk mengisi jumlah elemen dari A, B, C. yang kemudian kita sebagai user akan mengisi nilai elemen dengan menggunakan angka disinilah kita menggunakan nested for yang sebanyak 3x karena array nya 3 dimensi yaitu nested A, B, C untuk menginput elemen tiap dimensinya, baris dan kolommnya. Selanjutnya yaitu menampilkan array 3 dimensi yang telah kita buat tadi seperti sebelumnya kita menggunakan nested for yang sebanyak 3x karena array nya 3 dimensi yaitu nested A, B, C untuk menampilkannya elemen tiap baris dan kolomnya. Secara sekilas seperti guided 1 akan tetapi disini kita menentukan jumlah elemen array nya.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream> // Library

using namespace std;

// Fungsi untuk mencari nilai minimum dari array yang telah diinputkan oleh pengguna
int Minimal_2123(int arr[], int size)
{   int nilai_min = arr[0];
        for (int i = 1; i < size; ++i) 
        {   if (arr[i] < nilai_min) 
            {   nilai_min = arr[i];}
        }
    return nilai_min; // mengembalikan nilai dari variabel Minimal_2123
}

// Fungsi untuk mencari nilai maksimum dari array yang telah diinputkan oleh pengguna
int Maksimal_2123(int arr[], int size) 
{   int nilai_max = arr[0];
        for (int i = 1; i < size; ++i) 
        {   if (arr[i] > nilai_max) 
            {   nilai_max = arr[i];}
        }
    return nilai_max; // mengembalikan nilai dari variabel Maksimal_2123
}

// Fungsi untuk mencari nilai rata-rata dari array yang telah diinputkan oleh pengguna
double Rata_2123(int arr[], int size) 
{   double jumlah = 0;
        for (int i = 0; i < size; ++i)
        {   jumlah += arr[i];}
    return jumlah / size; // mengembalikan nilai dari variabel Rata_2123
}

int main() { // Fungsi utama
    const int ukuran_maksimal_2123 = 50; // Batasan jumlah elemen array
    int arr_2123[ukuran_maksimal_2123]; // Array untuk menyimpan elemen-elemen
    int pilih_2123, size_2123; // deklarasi variabel

    do { // Untuk melakukan Looping jika sudah output muncul
        cout << "\nMenu Pencari Nilai Array by Dadya Vio Hendraksa" << endl; // Bagian menu
        cout << "1. Nilai Minimum" << endl;
        cout << "2. Nilai Maksimum" << endl;
        cout << "3. Nilai Rata-rata" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih_2123; // Input menu

        switch (pilih_2123) {
            case 1:
            case 2:
            case 3:
                // Input jumlah elemen array dari pengguna
                cout << "Masukkan jumlah elemen array (maksimum " << ukuran_maksimal_2123 << "): ";
                cin >> size_2123;

                // Cek ukuran array apakah tidak melebihi batas jumlah elemen array
                if (size_2123 <= 0 || size_2123 > ukuran_maksimal_2123) {
                    cout << "Ukuran array tidak valid! Harap masukkan ukuran antara 1 dan " << ukuran_maksimal_2123 << endl;
                    break;
                }

                // Menginputkan nilai elemen-elemen array
                cout << "Masukkan elemen-elemen array:" << endl;
                for (int i = 0; i < size_2123; ++i) {
                    cout << "Indeks [" << i << "]: ";
                    cin >> arr_2123[i];
                }

                // Memproses pilihan pengguna
                switch (pilih_2123) {
                    case 1: // Mencari nilai minimum dan menampilkannya dengan memanggil fungsi Minimal_2123
                        cout << "Nilai Minimum: " << Minimal_2123(arr_2123, size_2123) << endl;
                        break;
                    case 2: // Mencari nilai minimum dan menampilkannya dengan memanggil fungsi Maksimal_2123
                        cout << "Nilai Maksimum: " << Maksimal_2123(arr_2123, size_2123) << endl;
                        break;
                    case 3: // Mencari nilai minimum dan menampilkannya dengan memanggil fungsi Rata_2123
                        cout << "Nilai Rata-rata: " << Rata_2123(arr_2123, size_2123) << endl;
                        break;
                }
                break;
            case 4: // Jika memilih 4 maka akan keluar dari program ini
                cout << "Anda telah keluar dari program ini. Terima kasih." << endl;
                break;
            default: // Bagian ini dijalankan jika input jumlah ukuran array lebih dari batas maksimal
                cout << "Input junlah elemen array salah, Tolong inputkan angka yang sesuai." << endl;
                break;
        }

    } while (pilih_2123 != 4); // Input selain 4 maka akan melakukan perulangan

    return 0;
}
```
#### Output:
![Screenshot Output Unguided 3](Output_Unguided-03_Dadya-Vio-H.png)
Program ini berguna untuk mencari min, max, dan median dari array yang diinput user. Saya disini menggunakan 3 fungsi yaitu Minimal_2123, Maksimal_2123, Rata_2123 untuk memudahkan dalam pemprosesan dan penghitungan mencari min, max, dan median dari array dengan menggunakan looping for dan pecabangan if-else. Selanjutnya pada Fungsi utama main pertama kita deklarasikan array, jumlah max elemen array dan variabel pilih_2123, size_2123. Kemudian disini saya menggunakan do while untuk melakukan perulangan menunya, didalam nya terdapat menu untuk memilih mencari nilai apa yang kita inginkan. <br/>

Kemudian ada switch pertama dari case 1 samapai case 4. untuk case 1 sampai case 3 disini saya jadikan 1 karena ada beberapa kesamaan untuk input jumlah elemen array, cek ukuran jumlah elemen array dengan perulangan if, dan input nilai elemen array dengam menggunakan looping for. Selanjutnya terdapat switch kedua didalam case 1-3 switch pertama yang berguna untuk memanggil nilai dari 3 fungsi yang kita buat tadi diluat fungsi utama main yang harusnya teroutput sesuai dengan pilihan menu yang dipilih user. Unuk penjelasan case 4 dan default switch pertama yaitu case 4 untuk keluar dari program ini sedangkan default untuk looping jika user input jumlah elemen arraynya salah.
## Kesimpulan
Array sangat membantu dalam efisiensi program karena dapat mempermudah dalam menyimpan dan mengakses data yang terkumpul dalam satu variabel, dari pada menggunakan banyak variabel. Dengan adanya pengurutan data indeks yang tetap dari 0 ini memberikan kemudahan dalam membaca alamat elemen tersebut. Akan tetapi perlu diketahui bahwa menggunakan array yang lebih dari 2 dimensi tidaklah efisien. Semua tergantung program yang akan dibuat dan pembangunan sturuktur data dan algoritma yang digunakan sebelum melakukan pemprograman.

## Referensi
[1] Shofyann Hanief,et al., Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Yogyakarta: Andi Publisher, 2020. <br/>
[2] Joseph Teguh Santoso., STRUKTUR DATA dan ALGORITMA (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.