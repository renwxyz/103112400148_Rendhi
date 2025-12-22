#ifndef MLL_H
#define MLL_H

#include <iostream>

using namespace std;

struct Child {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    Child *next;
    Child *prev;
};

struct ListChild {
    Child *first;
    Child *last;
};

struct Parent {
    string idGenre;
    string namaGenre;
    Parent *next;
    Parent *prev;
    ListChild films;
};

struct ListParent {
    Parent *first;
    Parent *last;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);

Parent* alokasiNodeParent(string id, string nama);
Child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(Parent* P);
void dealokasiNodeChild(Child* C);

void insertFirstParent(ListParent &LP, Parent* P);
void insertLastChild(ListChild &LC, Child* C);

void hapusListChild(ListChild &LC);
void deleteAfterParent(ListParent &LP, Parent* prec);

void searchFilmByRatingRange(ListParent LP, float minR, float maxR);
void printStrukturMLL(ListParent LP);

#endif
