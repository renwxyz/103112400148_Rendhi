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

#endif