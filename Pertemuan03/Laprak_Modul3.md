# <h1 align="center">Laporan Praktikum Modul 3 - LINKED LIST</h1>
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
Program ini

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
Program ini

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
![Screenshot Output Unguided 1 Part 1](Output_Unguided-01_Part-1_Dadya-Vio-H.png)</br>
![Screenshot Output Unguided 1 Part 2](Output_Unguided-01_Part-2_Dadya-Vio-H.png)</br>
Program ini

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.</br> ![Screenshot Soal Unguided 2 Part 1](Soal_Unguided-02_Part-1_Dadya-Vio-H.png)<br/> ![Screenshot Soal Unguided 2 Part 2](Soal_Unguided-02_Part-2_Dadya-Vio-H.png)<br/> Case:</br> 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific</br> 2. Hapus produk wardah</br> 3. Update produk Hanasui menjadi Cleora dengan harga 55.000</br> 4. Tampilkan menu seperti dibawah ini:</br> 

### Toko Skincare Purwokerto</br> 1. Tambah Data</br> 2. Hapus Data 3 Update Data</br> 4. Tambah Data Urutan Tertentu</br> 5. Hapus Data Urutan Tertentu</br> 6. Hapus Seluruh Data</br> 7. Tampilkan Data</br> 8. Exit</br> Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :</br> ![Screenshot Soal Unguided 2 Part 2](Soal_Unguided-02_Part-2_Dadya-Vio-H.png)

```C++
/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream> // mengatur input output
#include <iomanip> // mengatur layout output
#include <string> // mengatur string

using namespace std; // menggunakan standar library

class Node { // Deklarasi Class Node untuk Double Linked List
public: // Deklarasi Public untuk Class Node agar bisa diakses di luar class Node
    string Nama_Produk; 
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList { // Deklarasi Class DoublyLinkedList untuk Double Linked List
public: // Deklarasi Public untuk Class DoublyLinkedList agar bisa diakses di luar class DoublyLinkedList
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
 
    void tambah_produk(string Nama_Produk, int harga) { // Menambahkan produk ke dalam linked list di bagian atas
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk; // Menambahkan nama produk ke dalam linked list
        newNode->harga = harga; // Menambahkan harga produk ke dalam linked list
        newNode->prev = nullptr; // Pointer prev menunjuk ke nullptr
        newNode->next = head; // Pointer next menunjuk ke head
        if (head != nullptr) {
            head->prev = newNode; // Pointer prev head menunjuk ke newNode jika head tidak nullptr
        }
        else {
            tail = newNode; // Tail menunjuk ke newNode jika head nullptr
        }
        head = newNode; // Head menunjuk ke newNode setelah newNode di tambahkan ke linked list
    }

    void hapus_produk() { // Menghapus produk teratas dari linked list
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool ubah_produk(string Nama_Produk_Lama, string Nama_Produk_Baru, int Harga_Baru) { // Mengubah data produk berdasarkan nama produk
        Node* current = head;
        while (current != nullptr) { // Looping selama current tidak nullptr
            if (current->Nama_Produk == Nama_Produk_Lama) { // Jika nama produk lama ditemukan di linked list maka lakukan perubahan data produk
                current->Nama_Produk = Nama_Produk_Baru; // Mengubah nama produk lama menjadi nama produk baru
                current->harga = Harga_Baru; // Mengubah harga produk lama menjadi harga produk baru
                return true;
            }
            current = current->next;
        }
        return false; // Mengembalikan false jika data produk tidak ditemukan
    }

    void sisipkan_posisi_tertentu(string Nama_Produk, int harga, int posisi) { // Menambahkan data produk pada posisi tertentu
        if (posisi < 1) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk;
        newNode->harga = harga;
        if (posisi == 1) { // Jika posisi adalah 1 maka tambahkan data produk di depan linked list
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            else {
                tail = newNode;
            }
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) { // Looping sampai posisi sebelum posisi yang diinginkan (Posisi - 1)
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode; // Pointer prev node setelah current menunjuk ke newNode jika node setelah current tidak nullptr
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void hapus_posisi_tertentu(int posisi) { // Menghapus data produk pada posisi tertentu
        if (posisi < 1 || head == nullptr) { // Jika posisi kurang dari 1 atau head nullptr maka tampilkan pesan
            cout << "Posisi tidak ada atau list kosong" << endl;
            return;
        }
        Node* current = head;
        if (posisi == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete current;
            return;
        }
        for (int i = 1; current != nullptr && i < posisi; ++i) { // Looping sampai posisi yang diinginkan
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    void hapus_semua() { // Menghapus semua data produk
        Node* current = head; // Pointer current menunjuk ke head
        while (current != nullptr) {
            Node* temp = current; // Pointer temp menunjuk ke current
            current = current->next; // Pointer current menunjuk ke node selanjutnya
            delete temp; // Menghapus node temp (node head sebelumnya)
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() { // Menampilkan data produk
        Node* current = head;
        cout << "\nBerikut daftar Produk dan harga yang tersedia saat ini:" << endl;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl; // Menampilkan header tabel nama produk dan harga
        while (current != nullptr) {
            cout << left << setw(20) << current->Nama_Produk << current->harga << endl;  // Menampilkan produk dan harga dan meluruskan ke tabel
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list; // Deklarasi objek list dari class DoublyLinkedList
    
    list.tambah_produk("Hanasui", 30000);
    list.tambah_produk("Wardah", 50000);
    list.tambah_produk("Skintific", 100000);
    list.tambah_produk("Somethinc", 150000);
    list.tambah_produk("Originote", 60000);

    cout << "\n||||||-------Selamat datang di Toko Skincare Purwokerto by Dadya Vio Hendraksa_2123-------||||||" << endl;
    list.display();

    while (true) { // Looping menu utama
        cout << "\nMenu Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan; // Deklarasi variabel pilihan
        cout << "Pilih Menu: ";
        cin >> pilihan; // Input pilihan menu
        switch (pilihan) { // Switch case untuk memilih menu
        case 1: {
            string Nama_Produk;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> Nama_Produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.tambah_produk(Nama_Produk, harga); // Memanggil fungsi tambah_produk
            cout << "Produk berhasil ditambahkan teratas" << endl;
            break;
        }
        case 2: {
            list.hapus_produk(); // Memanggil fungsi hapus_produk
            cout << "Produk teratas berhasil dihapus" << endl;
            break;
        }
        case 3: { 
            string Nama_Produk_Lama, Nama_Produk_Baru;
            int Harga_Baru;
            cout << "Input nama produk lama: ";
            cin >> Nama_Produk_Lama;
            cout << "Input nama produk baru: ";
            cin >> Nama_Produk_Baru;
            cout << "Input harga baru: ";
            cin >> Harga_Baru;
            bool updated = list.ubah_produk(Nama_Produk_Lama, Nama_Produk_Baru, Harga_Baru); // Memanggil fungsi ubah_produk
            if (!updated) {
                cout << "Data produk tidak ditemukan" << endl;
            }
            else {
                cout << "Data produk berhasil diupdate" << endl;
            }
            break;
        }
        case 4: {
            string Nama_Produk;
            int harga, position;
            cout << "Input nama produk: ";
            cin >> Nama_Produk;
            cout << "Input harga: ";
            cin >> harga;
            cout << "Input posisi: ";
            cin >> position;
            list.sisipkan_posisi_tertentu(Nama_Produk, harga, position); // Memanggil fungsi sisipkan_posisi_tertentu
            cout << "Produk berhasil ditambahkan pada posisi " << position << endl;
            break;
        }
        case 5: {
            int position;
            cout << "Input posisi yang ingin dihapus: ";
            cin >> position;
            list.hapus_posisi_tertentu(position); // Memanggil fungsi hapus_posisi_tertentu

            break;
        }
        case 6: {
            list.hapus_semua(); // Memanggil fungsi hapus_semua
            break;
        }
        case 7: {
            list.display(); // Memanggil fungsi display
            break;
        }
        case 8: {
            return 0; // Exit program
        }
        default: {
            cout << "Input Invalid" << endl; 
            break;
        }
        }
    }
    return 0;
}
```
#### Output:
![Screenshot Output Unguided 2 Part 1](Output_Unguided-02_Part-1_Dadya-Vio-H.png)</br>
![Screenshot Output Unguided 2 Part 2](Output_Unguided-02_Part-2_Dadya-Vio-H.png)</br>
![Screenshot Output Unguided 2 Part 3](Output_Unguided-02_Part-3_Dadya-Vio-H.png)</br>
Program ini 

## Kesimpulan
Kesimpulannya

## Referensi
[1] Shofyann Hanief,et al., Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Yogyakarta: Andi Publisher, 2020. <br/>
[2] Joseph Teguh Santoso., STRUKTUR DATA dan ALGORITMA (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.