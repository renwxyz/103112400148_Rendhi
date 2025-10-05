#include <iostream>

using namespace std;

void tukar(int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari b: " << b << endl;
    cout << "Nilai dari c: " << c << endl;
    cout << "Alamat memori variabel a: " << &a << endl;
    cout << "Nilai yang disimpan di variabel pointer ptr: " << ptr << endl;
    cout << "Nilai yang diarahkan oleh ptr: " << *ptr << endl;
    
    tukar(&a, &b, &c);
    
    cout << "Setelah ditukar, nilai a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}