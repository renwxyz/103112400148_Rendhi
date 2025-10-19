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
    free(P);
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

void deleteFirst(List &L){
    if (L.First != nullptr){
        address firstNode = L.First;
        L.First = firstNode->next;
        dealokasi(firstNode);
        cout << "Node pertama berhasil dihapus" << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

void deleteAfter(List &L, address nodePrev) {
    if (nodePrev == nullptr || nodePrev->next == nullptr) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }

    address targetNode = nodePrev->next;     
    nodePrev->next = targetNode->next;        
    dealokasi(targetNode);                    
}

void deleteLast(List &L){
    address current, nodePrev;
    current = L.First;
    if(current != nullptr){
        if(current->next == nullptr){
            L.First = nullptr;
            dealokasi(current);
        } else { 
            while(current->next != nullptr){
                nodePrev = current; 
                current = current->next;
            }
            nodePrev->next = nullptr; 
            dealokasi(current);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

int nbList(List L){
    address current;
    int count = 0;

    current = L.First;
    while (current != nullptr){
        count++;
        current = current->next;
    }

    return count;
}

void deleteList(List &L){
    address current, targetNode;

    current = L.First;
    while (current != nullptr){
        targetNode = current;
        current = targetNode->next;
        dealokasi(targetNode);
    }

    L.First = nullptr;
    cout << "List berhasil dihapus" << endl;
}