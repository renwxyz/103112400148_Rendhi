#include "Singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address P1,P2,P3,P4,P5 = nullptr;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node pertama ---" << endl;
    deleteFirst(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node terakhir ---" << endl;
    deleteLast(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node->info = 8 (deleteAfter) ---" << endl;
    deleteAfter(L, P4);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus List ---" << endl;
    deleteList(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    return 0;
}