#include <iostream>

using namespace std;

int main() {
  int a = 7;
  int data[a] = {12,5,5,3,8,10,11};
  int cari = 7;
  int i;
  bool ada = false;

  for (i = 0; i < a; i++) {
    if (data[a] == cari) {
      ada = true;
      break;
    }
  }
  cout << "cari data array" << endl;
  cout << "data: {12,5,5,2,8,10,11}" << endl;
  if (ada) {
    cout << "Angka" << cari << "ditemukan pada indeks: " << i << endl;
  } else {
    cout << cari << " tidak dapat ditemukan." << endl;
  }
  return 0;
}