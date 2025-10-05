#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "nilai dari a: " << a << endl;
    cout << "alamat memori variabel a: " << &a << endl;
    cout << "Nilai dari ref (alias a): " << ref << endl;
    cout << "Alamat dari ref (&ref): " << &ref << endl;

    //mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "nilai a: " << a << endl;
    cout << "nilai ref: " << ref << endl;
    
    tukar(a,b);

    cout << "Setelah ditukar, nilai a=" << a << " dan nilai b=" << b << endl;

    return 0;
}