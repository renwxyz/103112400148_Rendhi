#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef Mahasiswa dataMahasiswa;
typedef struct Node *address;
 
struct Node{
    dataMahasiswa info;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &Node);
void printList(linkedlist List);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist &List);
void delList(linkedlist &List);

#endif