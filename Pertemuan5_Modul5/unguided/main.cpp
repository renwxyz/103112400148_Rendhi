#include "ListAngka.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    address nodeHapus = NULL;
    delAfter(L, nodeHapus, nodeC);
    if (nodeHapus != NULL) {
        dealokasi(nodeHapus);
    }
    
    cout << "\n";
    printList(L);
    cout << "\n";
    
    // SOAL 1: Update
    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, L.First);

    printList(L);
    cout << "\n";

    // SOAL 2: Search
    SearchByData(L, 20);
    SearchByData(L, 55);

    cout << "\n";
    SearchByAddress(L, nodeB);
    cout << "\n";
    SearchByAddress(L, nodeA);

    SearchByRange(L, 40);
    
    // SOAL 3: Aritmatika
    cout << "\n";
    hitungAritmatika(L);

    return 0;
}