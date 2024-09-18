#include <iostream>
#include <string> 

using namespace std;

// Struct untuk karyawan yang berisi nama, jabatan, dan gaji
struct Karyawan {
    string nama;
    string jabatan;
    int gaji = -1;  // Inisialisasi gaji dengan -1
};

// Prosedur tampilkan daftar nama
void Tampilkan_Daftar_Nama(string Jabatan, Karyawan Karyawan[], int Jumlah_Nama, int indeks[], int &indeks_count) {
    cout << endl;
    cout << "|==========================|" << endl;
    cout << " Daftar nama " << Jabatan << endl;
    cout << "|==========================|" << endl;
    int count = 1;
    for (int i = 0; i < Jumlah_Nama; i++) { // Looping untuk menampilkan nama karyawan berdasarkan jabatan yang dipilih
        if (Karyawan[i].jabatan == Jabatan) { // Jika jabatan karyawan sama dengan jabatan yang dipilih
            cout << "      " << count << ". " << Karyawan[i].nama << endl;
            indeks[indeks_count++] = i; // Simpan indeks karyawan
            count++; 
        }
    }
    cout << "|==========================|" << endl;
}

// Fungsi hitung gaji hari masuk karyawan
int Hitung_Gaji(string Jabatan, int Hari_Masuk) {
    int Gaji = 0;

    if (Jabatan == "CEO") {
        Gaji = Hari_Masuk * 1000000;
    } else if (Jabatan == "Direktur") {
        Gaji = Hari_Masuk * 750000;
    } else if (Jabatan == "Manajer") {
        Gaji = Hari_Masuk * 500000;
    } else if (Jabatan == "Pekerja/Buruh") {
        Gaji = Hari_Masuk * 250000;
    } else {
        cout << "Jabatan tidak tersedia." << endl;
    }

    return Gaji;
}

// Fungsi hitung gaji performa karyawan
int Hitung_Gaji_Perfomance(string Jabatan, int Hari_Masuk, int Performa) {
    int Gaji = Hitung_Gaji(Jabatan, Hari_Masuk);

    if (Performa >= 90) {
        Gaji += Gaji * 0.2;  // 20% bonus performa 
    } else if (Performa >= 70) {
        Gaji += Gaji * 0.1;  // 10% bonus performa
    }

    return Gaji;
}

// Fungsi hitung gaji overtime karyawan
int Hitung_Gaji_Overtime(string Jabatan, int Hari_Masuk, int Jam_Overtime) {
    int Gaji = Hitung_Gaji(Jabatan, Hari_Masuk);

    int Gaji_Per_Jam_Overtime = 0;
    if (Jabatan == "CEO") {
        Gaji_Per_Jam_Overtime = 100000;
    } else if (Jabatan == "Direktur") {
        Gaji_Per_Jam_Overtime = 75000;
    } else if (Jabatan == "Manajer") {
        Gaji_Per_Jam_Overtime = 50000;
    } else if (Jabatan == "Pekerja/Buruh") {
        Gaji_Per_Jam_Overtime = 25000;
    } else {
        cout << "Jabatan tidak tersedia." << endl;
    }

    Gaji += Jam_Overtime * Gaji_Per_Jam_Overtime; // Hitung gaji overtime dengan mengalikan gaji per jam overtime dengan jam overtime

    return Gaji; 
}

// Fungsi untuk mencari karyawan berdasarkan nama dan menampilkan jabatan dan gaji karyawan
int Cari_Karyawan_Berdasarkan_Nama(string nama, Karyawan karyawan[], int jumlah_karyawan) {
    for (int i = 0; i < jumlah_karyawan; i++) { // Looping untuk mencari karyawan berdasarkan nama yang diinput
        if (karyawan[i].nama == nama) {
            cout << "Karyawan " << nama << " ditemukan dengan jabatan " << karyawan[i].jabatan << endl; // Menampilkan jabatan karyawan
            cout << "Gaji: Rp " << (karyawan[i].gaji == -1 ? 0 : karyawan[i].gaji) << endl; // Jika gaji karyawan belum dihitung, maka gaji karyawan adalah 0
            return karyawan[i].gaji;
        }
    }
    cout << "Karyawan dengan nama " << nama << " tidak ditemukan." << endl;
    return -1; // Jika karyawan tidak ditemukan, maka return -1 
}

// Fungsi untuk menghapus karyawan berdasarkan nama dan mengurangi jumlah karyawan
bool Hapus_Karyawan(string nama, Karyawan karyawan[], int &jumlah_karyawan) {
    for (int i = 0; i < jumlah_karyawan; i++) { // Looping untuk mencari karyawan berdasarkan nama yang diinput
        if (karyawan[i].nama == nama) { // Jika karyawan ditemukan berdasarkan nama yang diinput 
            for (int j = i; j < jumlah_karyawan - 1; j++) { // Looping untuk menggeser karyawan yang akan dihapus ke belakang
                karyawan[j] = karyawan[j + 1];
            }
            jumlah_karyawan--;
            cout << "Karyawan " << nama << " berhasil dihapus." << endl;
            return true;
        }
    }
    cout << "Karyawan dengan nama " << nama << " tidak ditemukan." << endl;
    return false;
}

int main() {
    const int jumlah_jabatan = 4; // Jumlah jabatan yang tersedia 
    string Jabatan[jumlah_jabatan] = {"CEO", "Direktur", "Manajer", "Pekerja/Buruh"}; // Array untuk menyimpan jabatan yang tersedia 
    Karyawan karyawan[100]; // Array untuk menyimpan data karyawan dengan maksimal 100 karyawan
    int jumlah_karyawan = 0; // Jumlah karyawan yang sudah diinput

    for (int i = 0; i < jumlah_jabatan; i++) { // Looping untuk input nama karyawan berdasarkan jabatan yang tersedia
        int jumlah_nama;
        cout << " Masukkan jumlah nama dari " << Jabatan[i] << ": "; 
        cin >> jumlah_nama;

        for (int j = 0; j < jumlah_nama; j++) { // Looping untuk input nama karyawan berdasarkan jumlah nama yang diinput 
            cout << " Nama " << j + 1 << ": ";
            cin >> karyawan[jumlah_karyawan].nama;
            karyawan[jumlah_karyawan].jabatan = Jabatan[i];
            karyawan[jumlah_karyawan].gaji = -1;  // Inisialisasi gaji dengan -1
            jumlah_karyawan++;
        }
    }

    char Lanjutkan; // Variabel untuk menentukan apakah user ingin kembali ke menu utama
    do { // Looping untuk menampilkan menu utama program
        cout << endl;
        cout << "|==========================|" << endl;
        cout << "|==Menu Program Karyawan===|" << endl;
        cout << "|==========================|" << endl;
        cout << " 1. Mencari Gaji" << endl;
        cout << " 2. Cari Nama" << endl;
        cout << " 3. Hapus Nama" << endl;
        cout << "|==========================|" << endl;
        int Pilihan_Menu;
        do {
            cout << " Pilih menu (1-3): ";
            cin >> Pilihan_Menu;

            if (Pilihan_Menu < 1 || Pilihan_Menu > 3) {
                cout << " Input anda tidak tersedia. Tolong input antara 1-3." << endl;
            }
        } while (Pilihan_Menu < 1 || Pilihan_Menu > 3);

        if (Pilihan_Menu == 1) { // Jika user memilih menu 1 (Mencari Gaji) 
            cout << endl;
            cout << "|==========================|" << endl;
            cout << "|==Menu Jabatan Pekerjaan==|" << endl;
            cout << "|==========================|" << endl;
            for (int i = 0; i < jumlah_jabatan; i++) { // Looping untuk menampilkan jabatan yang tersedia 
                cout << "      " << i + 1 << ". " << Jabatan[i] << endl;
            }
            cout << "|==========================|" << endl;
            int Pilihan_Jabatan;
            do {
                cout << " Pilih jabatan (1-4): ";
                cin >> Pilihan_Jabatan;

                if (Pilihan_Jabatan < 1 || Pilihan_Jabatan > 4) {
                    cout << " Input anda tidak tersedia. Tolong input antara 1-4." << endl;
                }
            } while (Pilihan_Jabatan < 1 || Pilihan_Jabatan > 4);

            int indeks[100]; // Array untuk menyimpan indeks karyawan yang sesuai dengan jabatan yang dipilih
            int indeks_count = 0; // Jumlah indeks yang valid
            Tampilkan_Daftar_Nama(Jabatan[Pilihan_Jabatan - 1], karyawan, jumlah_karyawan, indeks, indeks_count); // Menampilkan daftar nama karyawan berdasarkan jabatan yang dipilih

            int Nomor_Nama;
            do { // Looping untuk memilih nama karyawan yang sesuai
                cout << " Pilih nama anda yang sesuai (1-" << indeks_count << "): ";
                cin >> Nomor_Nama;

                if (Nomor_Nama < 1 || Nomor_Nama > indeks_count) { 
                    cout << " Input anda tidak tersedia. Tolong input antara 1-" << indeks_count << "." << endl;
                }
            } while (Nomor_Nama < 1 || Nomor_Nama > indeks_count);

            Karyawan & karyawan_terpilih = karyawan[indeks[Nomor_Nama - 1]]; // Mengambil data karyawan berdasarkan indeks yang dipilih
            cout << " Nama anda adalah " << karyawan_terpilih.nama << endl;

            int Pilihan_Hitung_Gaji; 
            do { // Looping untuk memilih menu perhitungan gaji 
                cout << endl;
                cout << "|==========================|" << endl;
                cout << "|==Menu Perhitungan Gaji===|" << endl;
                cout << "|==========================|" << endl;
                cout << " 1. Hitung gaji hari masuk" << endl;
                cout << " 2. Hitung gaji perfomance" << endl;
                cout << " 3. Hitung gaji overtime" << endl;
                cout << "|==========================|" << endl;
                cout << " Pilih menu (1-3): ";
                cin >> Pilihan_Hitung_Gaji;

                if (Pilihan_Hitung_Gaji < 1 || Pilihan_Hitung_Gaji > 3) {
                    cout << " Input anda tidak tersedia. Tolong input antara 1-3." << endl;
                }
            } while (Pilihan_Hitung_Gaji < 1 || Pilihan_Hitung_Gaji > 3);

            int Hari_Masuk, Performa, Jam_Overtime, Gaji_Karyawan; // Variabel untuk menyimpan input hari masuk, performa, jam overtime, dan gaji karyawan
            switch (Pilihan_Hitung_Gaji) { // Switch case untuk memilih perhitungan gaji yang dipilih
                case 1: // Jika user memilih menu 1 (Hitung gaji hari masuk) 
                    cout << " Masukkan jumlah hari masuk kerja anda: ";
                    cin >> Hari_Masuk;
                    Gaji_Karyawan = Hitung_Gaji(karyawan_terpilih.jabatan, Hari_Masuk);
                    cout << " Gaji anda adalah Rp " << Gaji_Karyawan << endl;
                    break;
                case 2: // Jika user memilih menu 2 (Hitung gaji performa)
                    cout << " Masukkan jumlah hari masuk kerja anda: ";
                    cin >> Hari_Masuk;
                    cout << " Masukkan performa kerja anda (1-100): ";
                    cin >> Performa;
                    Gaji_Karyawan = Hitung_Gaji_Perfomance(karyawan_terpilih.jabatan, Hari_Masuk, Performa);
                    cout << " Gaji anda adalah Rp " << Gaji_Karyawan << endl;
                    break;
                case 3: // Jika user memilih menu 3 (Hitung gaji overtime)
                    cout << " Masukkan jumlah hari masuk kerja anda: ";
                    cin >> Hari_Masuk;
                    cout << " Masukkan jumlah jam overtime anda: ";
                    cin >> Jam_Overtime;
                    Gaji_Karyawan = Hitung_Gaji_Overtime(karyawan_terpilih.jabatan, Hari_Masuk, Jam_Overtime);
                    cout << " Gaji anda adalah Rp " << Gaji_Karyawan << endl;
                    break;
            }

            karyawan_terpilih.gaji = Gaji_Karyawan; // Menyimpan gaji karyawan yang sudah dihitung
        } else if (Pilihan_Menu == 2) { // Jika user memilih menu 2 (Cari Nama)
            string Nama_Karyawan;
            cout << " Masukkan nama karyawan yang dicari: ";
            cin >> Nama_Karyawan;
            Cari_Karyawan_Berdasarkan_Nama(Nama_Karyawan, karyawan, jumlah_karyawan);
        } else if (Pilihan_Menu == 3) { // Jika user memilih menu 3 (Hapus Nama)
            string Nama_Karyawan;
            cout << " Masukkan nama karyawan yang ingin dihapus: ";
            cin >> Nama_Karyawan;
            Hapus_Karyawan(Nama_Karyawan, karyawan, jumlah_karyawan);
        }

        cout << " Apakah anda ingin kembali ke menu utama? (y/n): ";
        cin >> Lanjutkan;
    } while (Lanjutkan == 'y' || Lanjutkan == 'Y'); // Jika user ingin kembali ke menu utama, maka loop akan terus berjalan

    return 0;
}