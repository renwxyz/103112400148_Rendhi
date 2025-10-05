#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "nilai dari a: " << a << endl;
    cout << "alamat memori variabel a: " << &a << endl;
    cout << "nilai yang disimpan di variabel pointer ptr: " << ptr << endl;
    cout << "nilai yang diarahkan oleh ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "Setelah ditukar, nilai a=" << a << " dan nilai b=" << b << endl;

    return 0;
}