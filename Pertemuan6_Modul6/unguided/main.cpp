#include "Doublylist.h"

// Fungsi helper untuk Latihan 3
void deleteKendaraan(List &L, string nopol) {
    address P, Prec;
    P = findElm(L, nopol);

    if (P == Nil) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
    }
}

int main() {
    List L;
    CreateList(L);

    infotype data;
    address P;
    string nopolCari, nopolHapus;

    // Skenario Latihan 1: Input Data
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        if (findElm(L, data.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
            string dummy;
            getline(cin, dummy); 
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;

            P = alokasi(data);
            insertFirst(L, P); 
        }
    }

    // Output Latihan 1
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    // Skenario Latihan 2: Find Element
    cout << endl << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nopolCari;
    
    P = findElm(L, nopolCari);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    // Skenario Latihan 3: Delete Element
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nopolHapus;
    deleteKendaraan(L, nopolHapus);

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}