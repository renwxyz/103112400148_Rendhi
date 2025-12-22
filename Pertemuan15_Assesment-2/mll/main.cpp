#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    Parent* G001 = alokasiNodeParent("G001", "Action");
    Parent* G002 = alokasiNodeParent("G002", "Comedy");
    Parent* G003 = alokasiNodeParent("G003", "Horror");
    Parent* G004 = alokasiNodeParent("G004", "Romance");

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    insertLastChild(G001->films, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    insertLastChild(G002->films, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(G002->films, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    insertLastChild(G003->films, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    insertLastChild(G004->films, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(G004->films, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

     
    printStrukturMLL(LP);
    cout << endl;

    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;

    deleteAfterParent(LP, G001);
    cout << endl;

    printStrukturMLL(LP);

    return 0;
}
