# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data

### 1. Definisi dan Konsep Dasar Linked List
Linked List adalah koleksi elemen data linear di mana urutan logis elemen tidak ditentukan oleh lokasi fisik dalam memori, melainkan oleh pointer atau tautan yang tertanam dalam setiap elemennya. Struktur data ini sangat penting karena memungkinkan alokasi memori secara dinamis (dynamic memory allocation), yang berarti list dapat tumbuh atau menyusut ukurannya saat program sedang berjalan, sangat berbeda dengan Array statis yang ukurannya sudah ditentukan sejak awal kompilasi. Fleksibilitas ini membuat Linked List sangat efisien untuk operasi penyisipan dan penghapusan data di mana saja dalam list.

### 2. Struktur Node dan Singy Linked List
Unit dasar dari Linked List disebut Node, yang merupakan objek yang terdiri dari dua bagian utama: bagian Data (Infotype), yang menyimpan nilai atau informasi yang sebenarnya, dan bagian Pointer (Address), yang menyimpan alamat memori dari node berikutnya dalam urutan. Dalam Singly Linked List, setiap node hanya memiliki satu pointer yang menunjuk ke node selanjutnya, memungkinkan penelusuran (traversal) hanya dalam satu arah (maju), dan pointer pada node terakhir akan bernilai NULL untuk menandai akhir dari list. Secara keseluruhan, list didefinisikan oleh pointer First (Head) yang menunjuk ke node pertama, dan jika list kosong, First bernilai NULL.

### 3. Implementasi Operasi Kunci
Praktikum ini berfokus pada implementasi Abstract Data Type (ADT) dengan berbagai operasi manipulasi data, yang memanfaatkan perubahan pada pointer Next. Operasi Penyisipan (insertFirst, insertLast, insertAfter) dan Penghapusan (delAfter) melibatkan penyesuaian pointer untuk menjaga integritas urutan list. Lebih lanjut, operasi Update memungkinkan modifikasi nilai data pada node tertentu (updateFirst, updateLast, updateAfter), sementara operasi Pencarian (SearchByData, SearchByAddress, SearchByRange) memerlukan penelusuran list dari node pertama hingga node yang dicari ditemukan. Terakhir, fungsi Aritmatika mengharuskan penelusuran seluruh list untuk melakukan komputasi agregat (penjumlahan, pengurangan, perkalian) terhadap semua elemen data di dalamnya.

## Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
Program di atas berfungsi sebagai kerangka Abstract Data Type (ADT) untuk mengelola data stok buah-buahan menggunakan Singly Linked List, di mana setiap node dapat menyimpan nama, jumlah, dan harga. Berkas header ini secara komprehensif mendeklarasikan semua fungsi dan prosedur yang saya butuhkan, mulai dari operasi dasar insert dan delete node pada posisi tertentu, hingga fungsi-fungsi lanjutan yang saya kembangkan untuk praktikum ini, yaitu Update data (updateFirst, updateLast, updateAfter) dan berbagai metode Pencarian data (FindNodeByData, FindNodeByAddress, FindNodeByRange).

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
Program di atas berguna sebagai implementasi fungsional penuh dari semua operasi Singly Linked List yang sebelumnya saya deklarasikan dalam header listBuah.h. Ini mencakup fungsi-fungsi penting seperti pemeriksaan kondisi list (isEmpty), manajemen memori (alokasi dan dealokasi), dan semua variasi operasi Insert dan Delete pada awal, akhir, dan posisi tertentu. Selain itu, file ini memuat body kode untuk fungsionalitas lanjutan seperti prosedur Update dan berbagai prosedur Pencarian yang memungkinkan saya memverifikasi dan memanipulasi data buah dalam list secara efektif sesuai kebutuhan praktikum.

### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas berguna sebagai program pengujian utama yang mengaplikasikan semua fungsi Singly Linked List buah-buahan; program ini menginisialisasi list dengan lima node, lalu secara berurutan menguji fungsionalitas Insert, Update data (First, Last, After), berbagai metode Pencarian (Data, Address, Range), dan diakhiri dengan operasi Delete (First, Last, After, dan deleteList total) untuk memverifikasi kebenaran dan kinerja seluruh implementasi ADT.

## Unguided

### 1. listAngka.h
```C++
#include <iostream>

using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

typedef linkedList List;

void CreateList(List &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address nodePrev);
int nbList(List L);
void delAfter(List &L, address &nodeHapus, address nodePrev);
void updateFirst(List &L);
void updateLast(List &L);
void updateAfter(List &L, address nodePrev);
void SearchByData(List L, int data);
void SearchByAddress(List L, address node);
void SearchByRange(List L, int nilaiMin);
void hitungAritmatika(List L);
```
Program di atas berfungsi sebagai kerangka Abstract Data Type (ADT) untuk suatu Singly Linked List yang menyimpan data angka, dengan mendefinisikan struktur dasar (struct node dan linkedList) serta menetapkan semua operasi yang dapat dilakukan pada list tersebut. Saya telah mendeklarasikan secara komprehensif seluruh prosedur dan fungsi yang dibutuhkan, mulai dari operasi dasar pengelolaan list seperti CreateList, alokasi, dan berbagai metode Insert/Delete (insertFirst, delAfter), hingga fungsionalitas lanjutan yang mencakup prosedur Update data (updateFirst, updateLast, updateAfter), berbagai metode Pencarian node (SearchByData, SearchByAddress, SearchByRange), serta fungsi komputasi untuk Aritmatika (hitungAritmatika), yang semuanya siap untuk diimplementasikan secara rinci dalam file .cpp.

### 2. listAngka.cpp

```C++
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
```
Program di atas berguna sebagai implementasi fungsional penuh dari semua operasi Singly Linked List angka, mencakup semua prosedur dasar list dan manajemen memori. Secara spesifik, file ini mengimplementasikan fungsi-fungsi lanjutan seperti Insert/Delete, prosedur Update interaktif untuk posisi First, Last, dan After, berbagai metode Pencarian, serta fungsi komputasi Aritmatika yang menelusuri seluruh list untuk menghitung total penjumlahan, pengurangan, dan perkalian.

### 3. main.cpp

```C++
#include "ListAngka.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    address nodeHapus = NULL;
    delAfter(L, nodeHapus, nodeC);
    if (nodeHapus != NULL) {
        dealokasi(nodeHapus);
    }
    
    cout << "\n";
    printList(L);
    cout << "\n";
    
    // SOAL 1: Update
    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, L.First);

    printList(L);
    cout << "\n";

    // SOAL 2: Search
    SearchByData(L, 20);
    SearchByData(L, 55);

    cout << "\n";
    SearchByAddress(L, nodeB);
    cout << "\n";
    SearchByAddress(L, nodeA);

    SearchByRange(L, 40);
    
    // SOAL 3: Aritmatika
    cout << "\n";
    hitungAritmatika(L);

    return 0;
}
```
Program di atas berguna sebagai program pengujian dan aplikasi komprehensif untuk Singly Linked List angka, yang secara bertahap membangun list awal dengan operasi Insert dan Delete dasar. Program ini kemudian melanjutkan untuk menguji fungsionalitas lanjutan praktikum, termasuk prosedur Update interaktif (First, Last, dan After), berbagai metode Pencarian node berdasarkan nilai data, alamat, dan rentang, serta diakhiri dengan pemanggilan fungsi Aritmatika untuk menghitung total penjumlahan, pengurangan, dan perkalian dari semua data node yang tersisa, memverifikasi seluruh implementasi ADT.

### Output Unguided :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output.png)

### Output Unguided Soal 1 :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output1.png)

Pengujian dimulai dengan memanggil updateFirst(L) untuk memodifikasi nilai data pada node pertama, diikuti oleh updateLast(L) untuk mengubah data pada node terakhir list. Untuk menguji operasi di tengah list, saya menggunakan updateAfter(L, nodeD) untuk mengubah node yang berada tepat setelah nodeD, dan kemudian melakukan pengujian serupa dengan updateAfter(L, L.First) untuk memodifikasi node kedua yang berada tepat setelah node pertama yang baru saja diperbarui. Keempat pemanggilan fungsi update ini dirancang untuk berinteraksi dengan pengguna guna meminta input nilai baru secara runtime, memastikan bahwa perubahan data berhasil diterapkan di berbagai posisi kritis dalam list. Setelah semua operasi update selesai dilakukan, list dicetak lagi menggunakan printList(L) untuk memverifikasi bahwa urutan dan nilai data dalam list telah berubah sesuai dengan hasil yang saya inginkan, yaitu urutan akhir 50 - 20 - 25 - 29 - 45 -.

### Output Unguided Soal 2 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output2.png)

Pengujian dimulai dengan SearchByData(L, 20) dan SearchByData(L, 55) untuk memverifikasi kemampuan program dalam menemukan data yang ada maupun data yang tidak ada dalam list. Selanjutnya, saya menguji kemampuan pencarian berdasarkan alamat memori dengan memanggil SearchByAddress menggunakan pointer ke nodeB (yang telah dihapus) dan nodeA (yang datanya sudah diperbarui), untuk memastikan list dapat menangani kasus node yang hilang dan yang masih ada. Terakhir, SearchByRange(L, 40) dijalankan untuk memverifikasi bahwa program dapat menelusuri seluruh list dan secara akurat mengidentifikasi semua node yang memiliki nilai data di atas batas minimum yang ditentukan.

### Output Unguided Soal 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output3.png)

Pada soal 3 ini diinstruksikan untuk menghitung tiga operasi matematis secara sekaligus: penjumlahan (dimulai dari nilai 0), perkalian (dimulai dari nilai 1), dan pengurangan, yang mana nilai awal pengurangannya diambil dari nilai node pertama, kemudian dikurangi secara berurutan dengan semua node berikutnya. Pemanggilan ini secara efektif menguji kemampuan program untuk menelusuri seluruh list satu kali dan memproses data di setiap node untuk menghasilkan tiga hasil total, yang menunjukkan validitas implementasi fungsi penelusuran (traversal) dan manipulasi data di dalam Singly Linked List yang saya buat.

## Kesimpulan
Melalui praktikum Modul 5 tentang Singly Linked List, saya berhasil mengimplementasikan Abstract Data Type (ADT) untuk struktur data linier ini, mencakup dasar-dasar seperti alokasi node, inisialisasi list, serta operasi manipulasi utama seperti insertFirst, insertLast, insertAfter, dan delAfter. Selain itu, saya mengembangkan fungsionalitas lanjutan yang krusial, yaitu operasi Update (updateFirst, updateLast, updateAfter), prosedur Pencarian (SearchByData, SearchByAddress, SearchByRange), dan prosedur perhitungan Aritmatika (penjumlahan, pengurangan, perkalian), yang menunjukkan pemahaman mendalam tentang penelusuran dan modifikasi data dalam list tunggal.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/