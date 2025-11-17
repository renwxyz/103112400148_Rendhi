#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main(){
    List L1;
    address node1, node2, node3;
    
    node1 = allocate("Pulpen", "A001", 20, 2500, 0);
    node2 = allocate("Buku Tulis", "A002", 15, 5000, 10);
    node3 = allocate("Penghapus", "A003", 30, 1500, 0);

    createList(L1);
    insertLast(L1, node1);
    insertLast(L1, node2);
    insertLast(L1, node3);

    viewList(L1);

    deleteFirst(L1);

    viewList(L1);

    updateAtPosition(L1, 2);
    
    viewList(L1);

    searchByFinalPriceRange(L1, 2000, 7000);

    maxHargaAkhir(L1);

    return 0;
}