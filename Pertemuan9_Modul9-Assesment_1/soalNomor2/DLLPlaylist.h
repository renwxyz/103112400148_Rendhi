#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <iostream>
using namespace std; 

struct Song{
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

typedef struct Node *address;

struct Node{
    Song info;
    address prev;
    address next;
};

struct List{
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(string title, string artist, int durationSec, int playCount, float rating);
void deallocate(address targetNode);
void insertFirst(List &L, address newNode);
void insertLast(List &L, address newNode);
void insertAfter(List &L, address targetNode, address newNode);
void insertBefore(List &L, address targetNode, address newNode);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address targetNode);
void deleteBefore(List &L, address targetNode);
void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address targetNode);
void viewList(List L);


#endif