//Dadya Vio Hendraksa 2311102123
#include <iostream>

using namespace std;

int main() {
    double suhu, Kelvin_2311102123_Dadya_VIO_H, Celcius_2311102123_Dadya_VIO_H;
    char skala;

    cout << "Masukkan nilai suhu: ";
    cin >> suhu;

    cout << "Masukkan skala suhu yang diinginkan (C/K): ";
    cin >> skala;

    if (skala == 'C' || skala == 'c') {
        Kelvin_2311102123_Dadya_VIO_H = suhu + 273.15;
        Celcius_2311102123_Dadya_VIO_H = suhu;
    } else if (skala == 'K' || skala == 'k') {
        Kelvin_2311102123_Dadya_VIO_H = suhu;
        Celcius_2311102123_Dadya_VIO_H = suhu - 273.15;
    } else {
        cout << "Skala suhu yang diinputkan salah." << endl;
        return 0;
    }

    cout << "Nilai suhu skala Kelvin: " << Kelvin_2311102123_Dadya_VIO_H << " Nilai suhu skala Celcius: " << Celcius_2311102123_Dadya_VIO_H << endl;

    return 0;
} 
