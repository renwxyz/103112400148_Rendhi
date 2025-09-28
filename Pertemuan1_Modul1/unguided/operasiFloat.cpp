#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama (float): ";
    cin >> a;

    cout << "Masukkan bilangan kedua (float): ";
    cin >> b;

    cout << "\nHasil Perhitungan:" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian: " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian: " << a / b << endl;
    } else {
        cout << "Pembagian: Tidak dapat dibagi (Pembagi nol)" << endl;
    }

    return 0;
}