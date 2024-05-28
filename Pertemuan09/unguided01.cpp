#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int jumlah_Simpul_2123;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlah_Simpul_2123;

    vector<string> simpul_2123(jumlah_Simpul_2123);
    vector<vector<int>> busur_2123(jumlah_Simpul_2123, vector<int>(jumlah_Simpul_2123));

    // Input nama simpul
    cout << "Silakan masukkan nama simpul:\n";
    for (int i = 0; i < jumlah_Simpul_2123; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul_2123[i];
    }

    // Input bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlah_Simpul_2123; ++i) {
        for (int j = 0; j < jumlah_Simpul_2123; ++j) {
            cout << simpul_2123[i] << " --> " << simpul_2123[j] << " = ";
            cin >> busur_2123[i][j];
        }
    }

    // Tampilkan graf
    int n = simpul_2123.size();

    // Cetak header
    cout << "\n        ";
    for (int i = 0; i < n; ++i) {
        cout << left << setw(12) << simpul_2123[i];
    }
    cout << endl;

    // Cetak baris
    for (int i = 0; i < n; ++i) {
        cout << left << setw(10) << simpul_2123[i];
        for (int j = 0; j < n; ++j) {
            cout << left << setw(12) << busur_2123[i][j];
        }
        cout << endl;
    }

    return 0;
}