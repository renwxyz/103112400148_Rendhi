#ifndef LIST_H
#define LIST_H

typedef int infotype;
typedef struct ElmList* address;

struct ElmList{
    infotype info;
    address next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteAfter(List &L, address nodePrev);
void deleteLast(List &L);
int nbList(List L);
void deleteList(List &L);

#endif