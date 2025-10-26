#include "ListAngka.h"

void CreateList(List &L) {
    L.First = NULL;
}

address alokasi(dataAngka x) {
    address P = new node;
    P->Angka = x;
    P->Next = NULL;
    return P;
}

void dealokasi(address &node) {
    delete node;
    node = NULL;
}

void printList(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    while (P != NULL) {
        cout << P->Angka << " - ";
        P = P->Next;
    }
    cout << endl;
}

void insertFirst(List &L, address nodeBaru) {
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru) {
    if (L.First == NULL) {
        L.First = nodeBaru;
        return;
    }
    address P = L.First;
    while (P->Next != NULL) {
        P = P->Next;
    }
    P->Next = nodeBaru;
}

void insertAfter(List &L, address nodeBaru, address nodePrev) {
    if (nodePrev != NULL) {
        nodeBaru->Next = nodePrev->Next;
        nodePrev->Next = nodeBaru;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->Next;
    }
    return count;
}

void delAfter(List &L, address &nodeHapus, address nodePrev) {
    if (nodePrev == NULL || nodePrev->Next == NULL) {
        nodeHapus = NULL;
        return;
    }

    address P = nodePrev->Next;
    nodeHapus = P;
    nodePrev->Next = P->Next;
    nodeHapus->Next = NULL;
}

void updateFirst(List &L) {
    if (L.First == NULL) {
        cout << "List kosong, tidak bisa update." << endl;
        return;
    }
    dataAngka newData;
    cout << "Masukkan update data node pertama: ";
    cout << "\nmasukkan angka: ";
    cin >> newData;
    L.First->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateLast(List &L) {
    if (L.First == NULL) {
        cout << "List kosong, tidak bisa update." << endl;
        return;
    }
    address P = L.First;
    while (P->Next != NULL) {
        P = P->Next;
    }
    dataAngka newData;
    cout << "\nmasukkan update data node terakhir : ";
    cout << "\nMasukkan angka: ";
    cin >> newData;
    P->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateAfter(List &L, address nodePrev) {
    if (nodePrev == NULL || nodePrev->Next == NULL) {
        cout << "Node sebelumnya tidak ditemukan atau tidak ada node setelahnya." << endl;
        return;
    }

    dataAngka newData;
    cout << "\nmasukkan update data node setelah node " << nodePrev->Angka << ":";
    cout << "\nMasukkan angka: ";
    cin >> newData;
    nodePrev->Next->Angka = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void SearchByData(List L, int data) {
    address P = L.First;
    int posisi = 0;
    bool ditemukan = false;
    while (P != NULL) {
        posisi++;
        if (P->Angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            ditemukan = true;
            break;
        }
        P = P->Next;
    }
    if (!ditemukan) {
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    }
}

void SearchByAddress(List L, address node) {
    address P = L.First;
    int posisi = 0;
    bool ditemukan = false;
    while (P != NULL) {
        posisi++;
        if (P == node) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << node << endl;
            ditemukan = true;
            break;
        }
        P = P->Next;
    }
    if (!ditemukan) {
        cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
    }
}

void SearchByRange(List L, int nilaiMin) {
    address P = L.First;
    bool ditemukan = false;
    int posisi = 0;
    cout << "\n--- Data diatas nilai " << nilaiMin << " ---" << endl;
    cout << "----------------------------------------------" << endl;
    while (P != NULL) {
        posisi++;
        if (P->Angka > nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << P->Angka << endl;
            cout << "----------------------------------------------" << endl;
            ditemukan = true;
        }
        P = P->Next;
    }
}

void hitungAritmatika(List L) {
    long long jumlah = 0;
    long long kurang = 0;
    long long kali = 1;

    address P = L.First;
    if (P != NULL) {
        kurang = P->Angka;
        P = P->Next;
    }

    address Q = L.First;
    while (Q != NULL) {
        jumlah += Q->Angka;
        kali *= Q->Angka;
        Q = Q->Next;
    }

    address R = L.First;
    if (R != NULL) {
        R = R->Next;
        while (R != NULL) {
            kurang -= R->Angka;
            R = R->Next;
        }
    }

    cout << "Total penjumlahan: " << jumlah << endl;
    cout << "Total pengurangan: " << kurang << endl;
    cout << "Total perkalian: " << kali << endl;
}