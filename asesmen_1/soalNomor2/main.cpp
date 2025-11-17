#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

int main(){
    List L1;
    createList(L1);

    address node1, node2, node3, node4;

    node1 = allocate("Senja di Kota", "Nona Band", 210, 150, 4.2);
    node2 = allocate("Langkahmu", "Delta", 185, 320, 4.8);
    node3 = allocate("Hujan Minggu", "Arka", 240, 90, 3.9);
    node4 = allocate("Senandung", "Mira", 175, 120, 4.0);

    insertLast(L1, node1);
    insertLast(L1, node2);
    insertLast(L1, node3);

    viewList(L1);

    deleteLast(L1);

    updateAtPosition(L1, 2);

    viewList(L1);
    
    insertBefore(L1, node2, node4);

    updateBefore(L1, node2);

    deleteBefore(L1, node2);

    viewList(L1);
}