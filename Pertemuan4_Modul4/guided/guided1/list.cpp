#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new Node; 
    nodeBaru->info.nama = nama;
    nodeBaru->info.nim = nim; 
    nodeBaru->info.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->info.nama << ", NIM : " << nodeBantu->info.nim 
            << ", Usia : " << nodeBantu->info.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}