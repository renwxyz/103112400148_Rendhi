#include <iostream>
#include <limits>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int nomorSoal;
    
    cin >> nomorSoal;

    if (nomorSoal == 3) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (nomorSoal){
        case 1:
            cout << "Hello world!" << endl;
            createStack(S);
            push(S,3);
            push(S,4);
            push(S,8);
            pop(S);
            push(S,2);
            push(S,3);
            pop(S);
            push(S,9);
            printInfo(S);
            cout<<"balik stack"<<endl;
            balikStack(S);
            printInfo(S);
            break;
        case 2:
            cout << "Hello world!" << endl;
            createStack(S);
            pushAscending(S,3);
            pushAscending(S,4);
            pushAscending(S,8);
            pushAscending(S,2);
            pushAscending(S,3);
            pushAscending(S,9);
            printInfo(S);
            cout<<"balik stack"<<endl;
            balikStack(S);
            printInfo(S);
            break;
        case 3:
            cout << "Hello world!" << endl;
            createStack(S);
            getInputStream(S);
            printInfo(S);
            
            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        default:
            cout << "Nomor soal tidak valid\n";
            break;
    }

    return 0;
}