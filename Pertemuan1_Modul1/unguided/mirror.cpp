#include <iostream>

using namespace std;

void Mirror(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
        for (int k = i; k >= 1; --k) {
            cout << k << " ";
        }
        cout << "*";
        for (int l = 1; l <= i; ++l) {
            cout << " " << l;
        }
        cout << endl;
    }
    
    if (n >= 1) {
        for (int i = 0; i < n; ++i) {
            cout << "  ";
        }
        cout << "* " << endl;
    }
}

int main() {
    int input;
    cout << "input: ";
    cin >> input;
    
    cout << endl << "output: "<< endl << endl;
    
    Mirror(input);

    return 0;
}