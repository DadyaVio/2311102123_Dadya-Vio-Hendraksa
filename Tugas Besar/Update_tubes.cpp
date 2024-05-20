#include <iostream>
#include <string>

using namespace std;

// Prosedur tampilkan daftar nama
void Tampilkan_Daftar_Nama(string Jabatan, string Nama[], int Jumlah_Nama) {
    cout << endl;
    cout << "|==========================|"<<endl;
    cout << " Daftar nama " << Jabatan << endl;
    cout << "|==========================|"<<endl;
    for (int i = 0; i < Jumlah_Nama; i++) {
        cout << "      " << i + 1 << ". " << Nama[i] << endl;
    }
    cout << "|==========================|"<<endl;
}

// Fungsi hitung gaji hari masuk
int Hitung_Gaji(string Jabatan, int Hari_Masuk) {
    int Gaji = 0;

    // Percabangan switch
    switch (Jabatan[0]) {
        case 'C':
            Gaji = Hari_Masuk * 1000000;
            break;
        case 'D':
            Gaji = Hari_Masuk * 750000;
            break;
        case 'M':
            Gaji = Hari_Masuk * 500000;
            break;
        case 'P':
            Gaji = Hari_Masuk * 250000;
            break;
        default:
            cout << "Jabatan tidak tersedia." << endl;
            break;
    }

    return Gaji;
}

// Fungsi hitung gaji perfomance
int Hitung_Gaji_Perfomance(string Jabatan, int Hari_Masuk, int Performa) {
    int Gaji = Hitung_Gaji(Jabatan, Hari_Masuk);

    // Bonus Performa
    if (Performa >= 90) {
        Gaji += Gaji * 0.2;  // 20% bonus performa
    } else if (Performa >= 70) {
        Gaji += Gaji * 0.1;  // 10% bonus performa
    }

    return Gaji;
}

//Fungsi hitung gaji overtime
int Hitung_Gaji_Overtime(string Jabatan, int Hari_Masuk, int Jam_Overtime) {
    int Gaji = Hitung_Gaji(Jabatan, Hari_Masuk);

    // Gaji overtime dan percabangan switch
    int Gaji_Per_Jam_Overtime = 0;
    switch (Jabatan[0]) {
        case 'C':
            Gaji_Per_Jam_Overtime = 100000;  //"Direksi"
            break;
        case 'D':
            Gaji_Per_Jam_Overtime = 75000;  //"Direktur"
            break;
        case 'M':
            Gaji_Per_Jam_Overtime = 50000;  //"Manajer"
            break;
        case 'P':
            Gaji_Per_Jam_Overtime = 25000;  //"Pekerja/Buruh"
            break;
        default:
            cout << "Jabatan tidak tersedia." << endl;
            break;
    }

    // Perhitungan gaji overtime
    Gaji += Jam_Overtime * Gaji_Per_Jam_Overtime;

    return Gaji;
}

// Fungsi untuk mencari karyawan berdasarkan nama
int Cari_Karyawan_Berdasarkan_Nama(string nama, string jabatan[], string* nama_karyawan[], int jumlah_nama[], int jumlah_jabatan) {
    for (int i = 0; i < jumlah_jabatan; i++) {
        for (int j = 0; j < jumlah_nama[i]; j++) {
            if (nama == nama_karyawan[i][j]) {
                cout << "Karyawan " << nama << " ditemukan dengan jabatan " << jabatan[i] << endl;
                return Hitung_Gaji(jabatan[i], 1); // Menggunakan fungsi Hitung_Gaji dengan Hari_Masuk=1 untuk menampilkan gaji standar
            }
        }
    }
    cout << "Karyawan dengan nama " << nama << " tidak ditemukan." << endl;
    return -1; // Mengembalikan -1 jika karyawan tidak ditemukan
}

int main() {
    //Array
    const int jumlah_jabatan = 4;
    int jumlah_nama[jumlah_jabatan];
    string Jabatan[jumlah_jabatan] = {"CEO", "Direktur", "Manajer", "Pekerja/Buruh"};
    string** Nama = new string*[jumlah_jabatan];

    // Input jumlah nama dan nama karyawan
    for (int i = 0; i < jumlah_jabatan; i++) {
        cout << " Masukkan jumlah nama dari " << Jabatan[i] << ": ";
        cin >> jumlah_nama[i];

        Nama[i] = new string[jumlah_nama[i]];

        cout << " Masukkan nama dari " << Jabatan[i] << ": " << endl;
        for (int j = 0; j < jumlah_nama[i]; j++) {
            cout << " Nama " << j + 1 << ": ";
            cin >> Nama[i][j];
        }
    }

    char Lanjutkan;
    do {
        cout << endl;
        cout << "|==========================|"<<endl;
        cout << "|==Menu Jabatan Pekerjaan==|" << endl;
        cout << "|==========================|"<<endl;
        for (int i = 0; i < jumlah_jabatan; i++) {
            cout <<"      "<< i + 1 << ". " << Jabatan[i] << endl;
        }
            cout << "|==========================|"<<endl;
        int Pilihan;
        do {
            cout << " Pilih menu (1-4) : ";
            cin >> Pilihan;

            if (Pilihan < 1 || Pilihan > 4) {
                cout << " Input anda tidak tersedia. Tolong input antara 1-4." << endl;
            }
        } while (Pilihan < 1 || Pilihan > 4);

        Tampilkan_Daftar_Nama(Jabatan[Pilihan - 1], Nama[Pilihan - 1], jumlah_nama[Pilihan - 1]);

        int Nomor_Nama;
        do {
            cout << " Pilih nama anda yang sesuai (1-" << jumlah_nama[Pilihan - 1] << ") : ";
            cin >> Nomor_Nama;

            if (Nomor_Nama < 1 || Nomor_Nama > jumlah_nama[Pilihan - 1]) {
                cout << " Input anda tidak tersedia. Tolong input antara 1-" << jumlah_nama[Pilihan - 1] << "." << endl;
            }
        } while (Nomor_Nama < 1 || Nomor_Nama > jumlah_nama[Pilihan - 1]);

        string Nama_Pengguna = Nama[Pilihan - 1][Nomor_Nama - 1];

        int Hari_Masuk;
        do {
            cout << endl;
            cout << " Berapa hari anda masuk dalam sebulan (1-31): ";
            cin >> Hari_Masuk;

            if (Hari_Masuk < 1 || Hari_Masuk > 31) {
                cout << " Input anda tidak tersedia. Harap masukkan angka antara 1 dan 31." << endl;
            }
        } while (Hari_Masuk < 1 || Hari_Masuk > 31);

        cout << endl;
        cout << "|==========================|"<<endl;
        cout << "|====Menu Gaji Karyawan====|" << endl;
        cout << "|==========================|"<<endl;
        cout << "      1. Gaji Standar       "<< endl;
        cout << "      2. Gaji Performa      " << endl;
        cout << "      3. Gaji Overtime      " << endl;
        cout << "|==========================|"<<endl;
        int Menu_Gaji;
        do {
            cout << " Pilih menu gaji (1-3) : ";
            cin >> Menu_Gaji;

            if (Menu_Gaji < 1 || Menu_Gaji > 3) {
                cout << " Input anda tidak tersedia. Tolong input antara 1-3." << endl;
            }
        } while (Menu_Gaji < 1 || Menu_Gaji > 3);

        int Performa = 0;
        int Jam_Overtime = 0;
        int Tunjangan = 0;
        int Potongan = 0;

        if (Menu_Gaji == 2) {
            cout << endl;
            cout << "|=================================================|"<<endl;
            cout << "|   Persentase >= 90 Mendapatkan 20% dari gaji    |" << endl;
            cout << "| 70 <= Persentase < 90 Mendapatkan 10% dari gaji |" << endl;
            cout << "|=================================================|"<<endl;
            do {
                cout << " Masukkan persentase performa (0-100): ";
                cin >> Performa;

                if (Performa < 0 || Performa > 100) {
                    cout << " Input anda tidak tersedia. Tolong masukkan antara 0 dan 100." << endl;
                }
            } while (Performa < 0 || Performa > 100);
        } else if (Menu_Gaji == 3) {
            cout << endl;
            do {
                cout << " Masukkan jumlah jam lembur: ";
                cin >> Jam_Overtime;

                if (Jam_Overtime < 0) {
                    cout << " Input anda tidak Tersedia. Tolong masukkan angka lebih dari 0." << endl;
                }
            } while (Jam_Overtime < 0);
        }

        // Memanggil fungsi/prosedur yang dipilih user dan dieksekusi
        int Gaji;
        if (Menu_Gaji == 1) {
            Gaji = Hitung_Gaji(Jabatan[Pilihan - 1], Hari_Masuk);
        } else if (Menu_Gaji == 2) {
            Gaji = Hitung_Gaji_Perfomance(Jabatan[Pilihan - 1], Hari_Masuk, Performa);
        } else if (Menu_Gaji == 3) {
            Gaji = Hitung_Gaji_Overtime(Jabatan[Pilihan - 1], Hari_Masuk, Jam_Overtime);
        }

        cout << " Masukkan jumlah tunjangan: ";
        cin >> Tunjangan;

        cout << " Masukkan jumlah potongan: ";
        cin >> Potongan;

        // Menampilkan hasil perhitungan gaji
        cout << endl;
        cout << "|==========================|"<<endl;
        cout << "|==Hasil Perhitungan Gaji==|" << endl;
        cout << "|==========================|"<<endl;
        cout << " Jabatan      : " << Jabatan[Pilihan - 1] << endl;
        cout << " Nama         : " << Nama_Pengguna << endl;
        cout << " Hari Masuk   : " << Hari_Masuk << " hari" << endl;

        // Menampilkan jenis gaji yang dipilih user
        switch (Menu_Gaji) {
            case 1:
                cout << " Gaji Standar : Rp " << Gaji << endl;
                break;
            case 2:
                cout << " Gaji Performa: Rp " << Gaji << endl;
                break;
            case 3:
                cout << " Gaji Overtime: Rp " << Gaji << endl;
                break;
        }

        // Menampilkan tunjangan dan potongan
        cout << " Tunjangan    : Rp " << Tunjangan << endl;
        cout << " Potongan     : Rp " << Potongan << endl;

        // Menampilkan Gaji Bersih
        int Gaji_Bersih = Gaji + Tunjangan - Potongan;
        cout << " Gaji Bersih  : Rp " << Gaji_Bersih << endl;
        cout << "|==========================|"<<endl;
        cout << endl;
        cout << " Apakah Anda ingin melanjutkan program hitung gaji karyawan ini (y/n)? ";
        cin >> Lanjutkan;

        if (Lanjutkan != 'y' && Lanjutkan != 'Y' && Lanjutkan != 'n' && Lanjutkan != 'N') {
            cout << " Input tidak tersedia. Tolong masukkan huruf 'y' atau 'n'." << endl;
        }

    } while (Lanjutkan == 'y' || Lanjutkan == 'Y');

    string cari_nama;
    cout << "Masukkan nama karyawan yang ingin Anda cari: ";
    cin >> cari_nama;
    Cari_Karyawan_Berdasarkan_Nama(cari_nama, Jabatan, Nama, jumlah_nama, jumlah_jabatan); // Memanggil fungsi pencarian

    cout << "Terima kasih telah menggunakan program hitung gaji karyawan. Sampai jumpa lagi!" << endl;

    // Dealokasi memori yaitu untuk menghapus nama yang tersimpan pada array dinamis
    for (int i = 0; i < jumlah_jabatan; i++) {
        delete[] Nama[i];
    }
    delete[] Nama;

    return 0;
}
