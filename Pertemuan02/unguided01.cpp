/*
Dadya Vio Hendraksa - 2311102123
*/

#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel untuk menyimpan nilai data array yang diinputkan pengguna
  int data_array_2123[50], size_2123 = 0;

  // Melakukan Input nilai data array dari pengguna
  cout << "\n(Catatan: pisahkan angka dengan klik enter dan untuk mengakhiri input (.) by Dadya Vio Hendraksa)" << endl;
  cout << "Inputkan Nilai elemen data array : ";
  while (cin >> data_array_2123[size_2123]) {
    size_2123++;
  }

  // Deklarasi variabel max menampung nilai elemen array
  bool genap[50] = {false}, ganjil[50] = {false};

  // Melakukan perulangan untuk setiap elemen dalam array yang telah diinputkan
  for (int i = 0; i < size_2123; i++) 
  { if (data_array_2123[i] % 2 == 0) // Memeriksa bilangan genap pada nilai array yang diinputkan
    {   genap[i] = true;} 
    else { ganjil[i] = true;} // Jika tidak sesuai bilangan genap maka akan masuk ke bilangan ganjil
  }

  // Menggunakan perulangan for dan percabangan untuk menampilkan nilai(Output) yang telah diinput tadi
  cout << "Data Array: "; // Menampilkan data array yang dinputkan pengguna
  for (int i = 0; i < size_2123; i++) 
  { cout << data_array_2123[i] << " ";}
  cout << endl;

  cout << "Nomor Genap: "; // Menampilkan data array genap
  for (int i = 0; i < size_2123; i++) 
  { if (genap[i]) 
    {   cout << data_array_2123[i] << ", ";}
  }
  cout << endl;

  cout << "Nomor Ganjil: "; // Menampilkan data array ganjil
  for (int i = 0; i < size_2123; i++) 
  { if (ganjil[i]) 
    {   cout << data_array_2123[i] << ", ";}
  }
  cout << endl;

  return 0;
}