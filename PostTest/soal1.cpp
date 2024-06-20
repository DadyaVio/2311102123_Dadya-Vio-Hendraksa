//Dadya Vio Hendraksa 2311102123

#include <windows.h>
#include <iostream>

using namespace std;

const int maksimal_tumpukan = 10;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;

struct tumpukan
{
    int posisi;
    string data[maksimal_tumpukan];
};
tumpukan buku;

// menginisialisasi posisi awal adalah -1 atau masih belum ada data di stack
void inisialisasi()
{
    buku.posisi = -1;
}

// fungsi pengecekan apakah stack masih kosong
bool kosong()
{
    return buku.posisi == -1;
}

// fungsi pengecekan apakah stack sudah penuh
bool penuh()
{
    return buku.posisi == maksimal_tumpukan - 1;
}

// fungsi untuk memasukan data stack baru
void push_tumpukan(string data_masukkan)
{
    if (kosong())
    {
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan;
        cout << "Berhasil memasukkan : " << data_masukkan << endl;
    }
    else if (!penuh())
    {
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan;
        cout << "Berhasil memasukkan : " << data_masukkan << endl;
    }
    else
    {
        cout << "Tumpukan sudah penuh" << endl;
    }
}

// fungsi untuk menghapus data stack
void pop_tumpukan()
{
    // perkondisian untuk mengecek apakah data kosong
    if (kosong())
    {
        cout << "Tumpukan kosong" << endl;
    }
    else
    {
        buku.posisi--;
        cout << "Data berhasil dihapus" << endl;
    }
}

void tampil_data()
{
    if (kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        for (int c = buku.posisi; c >= 0; c--)
        {
            cout << buku.data[c] << endl;
        }
    }
}

void clear_screen()
{
    cout << string(50, '\n'); // Simulate clear screen
}

int main()
{
    inisialisasi();
    do
    {
        cout << "\t" << "Stack Apps" << endl;
        cout << "1. Masukkan data kedalam Stack" << endl;
        cout << "2. Hapus data dari Stack" << endl;
        cout << "3. Tampilkan data Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Silahkan pilih (1-4) : ";
        cin >> pilihan;
        cin.ignore(); // Clear the input buffer
        switch (pilihan)
        {
        case 1:
            cout << "Silahkan masukkan data : ";
            getline(cin, data_masuk); // Use getline to read the entire line
            push_tumpukan(data_masuk);
            cout << "Keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << " Jumpa kembali " << endl;
                keluar = true;
            }
            else
            {
                clear_screen();
            }
            break;
        case 2:
            pop_tumpukan();
            cout << "Keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << " Terima kasih" << endl;
                keluar = true;
            }
            else
            {
                clear_screen();
            }
            break;
        case 3:
            tampil_data();
            cout << "Keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << " Terima kasih" << endl;
                keluar = true;
            }
            else
            {
                clear_screen();
            }
            break;
        case 4:
            cout << "Yakin ingin keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << " Terima kasih" << endl;
                keluar = true;
            }
            clear_screen();
            break;
        default:
            cout << "Pilihan tidak tersedia..." << endl;
            cout << "Keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << " Terima kasih" << endl;
                keluar = true;
            }
            else
            {
                clear_screen();
            }
        }
    } while (!keluar);
    return 0;
}
