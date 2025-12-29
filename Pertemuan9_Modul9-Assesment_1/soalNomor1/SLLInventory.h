#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <iostream>
using namespace std;

struct Product{
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef struct Node *address;

struct Node{
    Product info;
    address next;
};

struct List {
    address head;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(string nama, string sku, int jumlah, float harga, float diskonPersen);
void deallocate(address targetNode);
void insertFirst(List &L, address newNode);
void insertLast(List &L, address newNode);
void insertAfter(List &L, address targetNode, address newNode);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address targetNode);
void updateAtPosition(List &L, int posisi);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

void maxHargaAkhir(List L);


#endif