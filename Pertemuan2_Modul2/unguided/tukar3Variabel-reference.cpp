#include <iostream>

using namespace std;

void tukar(int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari b: " << b << endl;
    cout << "Nilai dari c: " << c << endl;
    cout << "Alamat memori variabel a: " << &a << endl;
    cout << "Nilai dari ref (alias a): " << ref << endl;
    cout << "Alamat dari ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << endl;
    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari ref: " << ref << endl;
    
    tukar(a, b, c);
    
    cout << "Setelah ditukar, nilai a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}