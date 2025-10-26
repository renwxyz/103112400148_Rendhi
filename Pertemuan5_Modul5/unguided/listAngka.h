#include <iostream>

using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

typedef linkedList List;

void CreateList(List &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address nodePrev);
int nbList(List L);
void delAfter(List &L, address &nodeHapus, address nodePrev);
void updateFirst(List &L);
void updateLast(List &L);
void updateAfter(List &L, address nodePrev);
void SearchByData(List L, int data);
void SearchByAddress(List L, address node);
void SearchByRange(List L, int nilaiMin);
void hitungAritmatika(List L);