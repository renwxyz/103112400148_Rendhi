#include <iostream>
#include <string>
using namespace std;

string sebutAngka(int n) {
    if (n == 0) return "nol";
    if (n == 100) return "seratus";

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (n < 10) {
        return satuan[n];
    } else if (n < 20) {
        if (n == 10) return "sepuluh";
        if (n == 11) return "sebelas";
        return satuan[n % 10] + " belas";
    } else {
        string hasil = satuan[n / 10] + " puluh";
        if (n % 10 != 0) {
            hasil += " " + satuan[n % 10];
        }
        return hasil;
    }
}

int main() {
    int angka;

    cout << "Masukkan angka bulat positif (0 s.d 100): ";
    cin >> angka;
    
    cout << angka << " : " << sebutAngka(angka) << endl;

    return 0;
}