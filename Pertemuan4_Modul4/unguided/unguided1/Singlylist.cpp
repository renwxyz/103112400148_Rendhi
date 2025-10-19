#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L){
    L.First = nullptr;
}

address alokasi(infotype x){
    address nodeBaru = (address) malloc(sizeof(ElmList));
    nodeBaru->info = x;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

void dealokasi(address &P){
    P->next = nullptr;
    delete P;
}

void printInfo(List L){
    if (L.First == nullptr){
        cout << "List Kosong" << endl;
    } else {
        address current = L.First;
        while (current!= nullptr){
        cout << current->info << " ";
        current = current->next;
        }
    }
}

void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}