#include "mll.h"

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

Parent* alokasiNodeParent(string id, string nama) {
    Parent* P = new Parent;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->films);
    return P;
}

Child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    Child* C = new Child;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(Parent* P) {
    delete P;
}

void dealokasiNodeChild(Child* C) {
    delete C;
}

void insertFirstParent(ListParent &LP, Parent* P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(ListChild &LC, Child* C) {
    if (LC.first == NULL) {
        LC.first = LC.last = C;
    } else {
        LC.last->next = C;
        C->prev = LC.last;
        LC.last = C;
    }
}

void hapusListChild(ListChild &LC) {
    Child* C = LC.first;
    while (C != NULL) {
        Child* temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    LC.first = LC.last = NULL;
}

void deleteAfterParent(ListParent &LP, Parent* prec) {
    if (prec == NULL || prec->next == NULL) return;

    Parent* del = prec->next;
    hapusListChild(del->films);

    prec->next = del->next;
    if (del->next != NULL)
        del->next->prev = prec;
    else
        LP.last = prec;

    dealokasiNodeParent(del);
}

void searchFilmByRatingRange(ListParent LP, float minR, float maxR) {
    Parent* P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        Child* C = P->films.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->ratingFilm >= minR && C->ratingFilm <= maxR) {

                cout << "Data Film ditemukan pada list child dari node parent ";
                cout << P->namaGenre;
                cout << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posChild << endl;
                cout << "ID Film : " << C->idFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;

                cout << "-----------------------------" << endl;

                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;

                cout << "========================================" << endl;
            }
            C = C->next;
            posChild++;
        }

        P = P->next;
        posParent++;
    }
}


void printStrukturMLL(ListParent LP) {
    Parent* P = LP.first;
    int noParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Genre : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        Child* C = P->films.first;
        int noChild = 1;

        while (C != NULL) {
            cout << " - Child " << noChild << " :" << endl;
            cout << "     ID Film : " << C->idFilm << endl;
            cout << "     Judul Film : " << C->judulFilm << endl;
            cout << "     Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "     Tahun Tayang : " << C->tahunTayang << endl;
            cout << "     Rating Film : " << C->ratingFilm << endl;

            C = C->next;
            noChild++;
        }

        cout << "-----------------------------" << endl;

        P = P->next;
        noParent++;
    }
}

