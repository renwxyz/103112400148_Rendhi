# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori
### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula.

#### B. Pointer & Reference
Pointer adalah variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain. Dengan pointer, kita bisa mengakses dan mengubah nilai variabel melalui alamat yang disimpannya, biasanya ditulis menggunakan simbol * untuk dereference dan & untuk mengambil alamat. Sementara itu, reference adalah sebuah alias dari variabel lain, artinya reference tidak menyimpan alamat melainkan langsung menjadi nama lain dari variabel tersebut. Reference bersifat tetap sejak pertama kali dideklarasikan, sehingga tidak bisa diubah untuk merujuk ke variabel lain. Perbedaan utama antara pointer dan reference terletak pada fleksibilitas dan cara penggunaannya: pointer dapat dipindahkan untuk menunjuk variabel yang berbeda, sedangkan reference selalu terikat pada satu variabel yang sama, dan penggunaannya lebih sederhana karena tidak memerlukan dereference.

#### C. Fungsi & Prosedur
Fungsi dan prosedur adalah dua konsep penting dalam pemrograman yang digunakan untuk membagi program menjadi bagian-bagian kecil agar lebih terstruktur. Fungsi adalah blok kode yang menerima input (parameter), melakukan proses, dan biasanya mengembalikan sebuah nilai dengan menggunakan kata kunci return. Fungsi cocok digunakan saat kita ingin menghitung atau menghasilkan sesuatu dari data yang diberikan. Sedangkan prosedur (dalam C++ umumnya berupa fungsi dengan tipe void) adalah blok kode yang dapat menerima parameter, melakukan serangkaian instruksi, tetapi tidak mengembalikan nilai. Prosedur lebih tepat digunakan untuk tugas yang hanya menjalankan aksi, seperti menampilkan output atau memodifikasi variabel. Dengan menggunakan fungsi dan prosedur, program menjadi lebih modular, mudah dibaca, serta memudahkan proses debugging maupun pengembangan lebih lanjut.

#### D. Single Linked List
Single Linked List merupakan salah satu struktur data dinamis yang tersusun atas sekumpulan elemen (node) yang saling terhubung melalui pointer. Setiap node pada single linked list umumnya terdiri dari dua bagian utama, yaitu info yang menyimpan data, dan next yang menyimpan alamat node berikutnya. Berbeda dengan array yang memiliki ukuran tetap, single linked list bersifat fleksibel karena elemen dapat ditambahkan atau dihapus secara dinamis tanpa perlu mengatur ulang seluruh struktur data. Operasi dasar yang dapat dilakukan pada single linked list meliputi insert (penyisipan elemen), delete (penghapusan elemen), traversal (penelusuran isi list), serta alokasi dan dealokasi memori. Struktur ini sangat berguna dalam situasi di mana jumlah data tidak diketahui sejak awal atau sering berubah. Menurut Mohanty dan Tripathy (2021), penggunaan single linked list membantu efisiensi pengelolaan memori dan memperkenalkan konsep penting dalam manipulasi pointer yang menjadi dasar bagi struktur data yang lebih kompleks seperti double linked list dan circular linked list.

## Guided 

### 1. Guided1

## list.h
```C++
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
```
Program di atas berfungsi untuk mendefinisikan struktur dan fungsi dasar dalam pembuatan linked list yang menyimpan data mahasiswa menggunakan bahasa C++. Program ini mendeklarasikan struktur Mahasiswa untuk menyimpan atribut seperti nama, NIM, dan umur, serta struktur Node yang merepresentasikan elemen dalam linked list. Selain itu, terdapat struktur linkedlist yang menyimpan alamat elemen pertama (first) dari daftar. Kode ini juga mendefinisikan beberapa fungsi penting seperti createList, isEmpty, alokasi, dealokasi, dan printList yang nantinya digunakan untuk menginisialisasi, memeriksa kondisi list, menambah atau menghapus node, serta menampilkan data mahasiswa secara keseluruhan.


## list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new Node; 
    nodeBaru->info.nama = nama;
    nodeBaru->info.nim = nim; 
    nodeBaru->info.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->info.nama << ", NIM : " << nodeBantu->info.nim 
            << ", Usia : " << nodeBantu->info.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Program di atas digunakan untuk mengimplementasikan fungsi-fungsi dasar dari linked list yang telah dideklarasikan pada file header sebelumnya. Fungsi isEmpty digunakan untuk memeriksa apakah linked list kosong dengan mengecek apakah elemen pertama bernilai Nil. Fungsi createList berfungsi untuk menginisialisasi list agar siap digunakan dengan mengatur pointer first menjadi Nil. Fungsi alokasi digunakan untuk membuat node baru yang menyimpan data mahasiswa berupa nama, NIM, dan umur, serta mengatur pointer next agar menunjuk ke Nil. Terakhir, fungsi printList digunakan untuk menampilkan seluruh data mahasiswa yang ada dalam linked list secara berurutan, atau menampilkan pesan jika list masih kosong.

## main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas digunakan untuk menguji fungsi-fungsi dasar dari linked list yang telah dibuat sebelumnya. Program ini dimulai dengan membuat sebuah list kosong menggunakan createList, kemudian membuat beberapa node baru berisi data mahasiswa dengan memanggil fungsi alokasi. Setiap node menyimpan informasi berupa nama, NIM, dan umur. Setelah node-node tersebut berhasil dialokasikan, program menampilkan isi list menggunakan fungsi printList. Namun, karena pada kode ini belum ada proses penyambungan node ke dalam list, hasil output yang ditampilkan masih menunjukkan bahwa list kosong.

### 2. Guided2

## list.h
```C++
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

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist &List);
void delList(linkedlist &List);

#endif
```
Program di atas digunakan untuk mendefinisikan struktur data dan deklarasi fungsi-fungsi yang diperlukan dalam pengelolaan linked list yang menyimpan data mahasiswa menggunakan bahasa C++. Program ini memuat struktur Mahasiswa untuk menampung atribut nama, NIM, dan umur, serta struktur Node yang menjadi elemen dari linked list dengan pointer next sebagai penghubung antar node. Selain itu, terdapat struktur linkedlist yang menyimpan alamat node pertama. Pada bagian deklarasi fungsi, terdapat operasi dasar seperti createList, alokasi, dealokasi, dan printList, serta operasi manipulasi data seperti insertFirst, insertAfter, insertLast untuk menambahkan data, dan delFirst, delLast, delAfter, delList untuk menghapus data. Fungsi nbList digunakan untuk menghitung jumlah elemen yang ada dalam list.

## list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new Node; 
    nodeBaru->info.nama = nama;
    nodeBaru->info.nim = nim; 
    nodeBaru->info.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

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

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->info.nama << ", NIM : " << nodeBantu->info.nim << ", Usia : " << nodeBantu->info.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
Program di atas digunakan untuk mengimplementasikan seluruh fungsi operasi dasar pada struktur data linked list yang menyimpan data mahasiswa. Program ini mencakup fungsi createList untuk menginisialisasi list kosong, isEmpty untuk memeriksa apakah list berisi elemen atau tidak, serta alokasi dan dealokasi untuk membuat dan menghapus node dari memori. Fungsi insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan elemen di awal, setelah node tertentu, dan di akhir list. Sedangkan delFirst, delAfter, dan delLast berfungsi untuk menghapus node dari posisi-posisi tersebut. Fungsi nbList digunakan untuk menghitung jumlah elemen yang ada di dalam list, sedangkan deleteList digunakan untuk menghapus seluruh isi list sekaligus. Program ini secara keseluruhan memperlihatkan bagaimana operasi dasar pada linked list diimplementasikan secara manual menggunakan pointer dalam bahasa C++.

## main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas digunakan untuk menguji keseluruhan fungsi operasi pada struktur data linked list yang menyimpan data mahasiswa. Program diawali dengan pembuatan list kosong menggunakan createList, kemudian lima node berisi data mahasiswa dialokasikan dengan fungsi alokasi. Node-node tersebut dimasukkan ke dalam list menggunakan kombinasi fungsi insertFirst, insertAfter, dan insertLast agar membentuk urutan data tertentu. Setelah proses insert, program menampilkan isi list dan jumlah node yang ada. Selanjutnya dilakukan penghapusan data menggunakan delFirst, delLast, dan delAfter untuk menghapus elemen di awal, akhir, dan setelah node tertentu. Setelah setiap proses, isi list dan jumlah node ditampilkan kembali. Terakhir, fungsi delList digunakan untuk menghapus seluruh isi list, dan hasil akhir menunjukkan bahwa list telah kosong.

## Unguided 

### 1. Unguided1

## SinglyList.h
```C++
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

#endif
```
Program di atas digunakan untuk mendefinisikan struktur dasar dan deklarasi fungsi dalam pembuatan linked list sederhana menggunakan bahasa C++. Program ini menggunakan tipe data infotype sebagai data yang akan disimpan di setiap node, dengan struktur ElmList yang berisi elemen info dan pointer next untuk menunjuk ke node berikutnya. Struktur List digunakan untuk menyimpan alamat node pertama dari linked list. Selain itu, terdapat deklarasi beberapa fungsi penting seperti CreateList untuk menginisialisasi list kosong, alokasi untuk membuat node baru, dealokasi untuk menghapus node dari memori, insertFirst untuk menambahkan node di awal list, dan printInfo untuk menampilkan seluruh elemen yang ada dalam list.

## Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L){
    L.First = nullptr;
}

address alokasi(infotype x){
    address nodeBaru = (address) malloc(sizeof(ElmList));
    nodeBaru->info = x;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

void dealokasi(address &P){
    P->next = nullptr;
    delete P;
}

void printInfo(List L){
    if (L.First == nullptr){
        cout << "List Kosong" << endl;
    } else {
        address current = L.First;
        while (current!= nullptr){
        cout << current->info << " ";
        current = current->next;
        }
    }
}

void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}
```
Program di atas digunakan untuk mengimplementasikan fungsi-fungsi dasar dari struktur data singly linked list menggunakan bahasa C++. Program ini dimulai dengan fungsi CreateList yang berfungsi untuk menginisialisasi list agar kosong dengan mengatur pointer First menjadi nullptr. Fungsi alokasi digunakan untuk membuat node baru yang menyimpan nilai bertipe infotype dan mengatur pointer next menjadi nullptr. Fungsi dealokasi digunakan untuk menghapus node dari memori setelah tidak digunakan lagi. Fungsi printInfo berfungsi menampilkan seluruh elemen yang terdapat dalam list, atau menampilkan pesan “List Kosong” jika tidak ada data. Terakhir, fungsi insertFirst digunakan untuk menambahkan node baru di bagian awal list dengan cara menghubungkan node tersebut ke elemen pertama yang sudah ada sebelumnya.

## main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address P1,P2,P3,P4,P5 = nullptr;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L);
    return 0;
}
```
Program di atas digunakan untuk menguji implementasi fungsi-fungsi dasar pada struktur data singly linked list. Program dimulai dengan membuat list kosong menggunakan CreateList, kemudian lima node baru dialokasikan dengan nilai 2, 0, 8, 12, dan 9. Setiap node dimasukkan ke awal list menggunakan fungsi insertFirst, sehingga urutan data dalam list menjadi terbalik dari urutan pemasukan (node terakhir yang dimasukkan akan menjadi node pertama). Setelah semua data dimasukkan, fungsi printInfo dipanggil untuk menampilkan seluruh elemen list secara berurutan mulai dari elemen pertama hingga terakhir.


### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan4_Modul4/unguided/output/unguided1-output.png)

Setelah seluruh file dicompile dan file executable nya dijalankan maka output akan keluar seperti di atas.

### 2. Unguided2

## SinglyList.h
```C++
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
```
Program di atas merupakan pengembangan atau lanjutan dari file sebelumnya, yaitu unguided1, yang membahas implementasi dasar struktur data singly linked list. Pada file unguided2 ini, selain fungsi-fungsi dasar seperti CreateList, alokasi, dealokasi, printInfo, dan insertFirst, ditambahkan pula beberapa fungsi baru yang memperluas kemampuan manipulasi data dalam linked list. Fungsi-fungsi tambahan tersebut meliputi deleteFirst untuk menghapus elemen pertama, deleteAfter untuk menghapus elemen setelah node tertentu, deleteLast untuk menghapus elemen terakhir, nbList untuk menghitung jumlah elemen dalam list, serta deleteList untuk menghapus seluruh isi list. Dengan demikian, program ini tidak hanya dapat menambahkan dan menampilkan data, tetapi juga mengelola dan menghapus data secara dinamis dalam struktur linked list.

## Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L){
    L.First = nullptr;
}

address alokasi(infotype x){
    address nodeBaru = (address) malloc(sizeof(ElmList));
    nodeBaru->info = x;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

void dealokasi(address &P){
    P->next = nullptr;
    free(P);
}

void printInfo(List L){
    if (L.First == nullptr){
        cout << "List Kosong" << endl;
    } else {
        address current = L.First;
        while (current!= nullptr){
        cout << current->info << " ";
        current = current->next;
        }
    }
}

void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L){
    if (L.First != nullptr){
        address firstNode = L.First;
        L.First = firstNode->next;
        dealokasi(firstNode);
        cout << "Node pertama berhasil dihapus" << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

void deleteAfter(List &L, address nodePrev) {
    if (nodePrev == nullptr || nodePrev->next == nullptr) {
        cout << "Tidak ada node setelahnya" << endl;
        return;
    }

    address targetNode = nodePrev->next;     
    nodePrev->next = targetNode->next;        
    dealokasi(targetNode);                    
}

void deleteLast(List &L){
    address current, nodePrev;
    current = L.First;
    if(current != nullptr){
        if(current->next == nullptr){
            L.First = nullptr;
            dealokasi(current);
        } else { 
            while(current->next != nullptr){
                nodePrev = current; 
                current = current->next;
            }
            nodePrev->next = nullptr; 
            dealokasi(current);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

int nbList(List L){
    address current;
    int count = 0;

    current = L.First;
    while (current != nullptr){
        count++;
        current = current->next;
    }

    return count;
}

void deleteList(List &L){
    address current, targetNode;

    current = L.First;
    while (current != nullptr){
        targetNode = current;
        current = targetNode->next;
        dealokasi(targetNode);
    }

    L.First = nullptr;
    cout << "List berhasil dihapus" << endl;
}
```
Program di atas merupakan hasil pengembangan dari file sebelumnya, yaitu unguided1, dan disusun sebagai bagian dari tugas unguided2. Pada kode ini, fungsi-fungsi dasar dari singly linked list diperluas dengan menambahkan berbagai operasi penghapusan dan penghitungan elemen dalam list. Selain fungsi CreateList, alokasi, dealokasi, printInfo, dan insertFirst yang sudah ada sebelumnya, program ini menambahkan fungsi deleteFirst untuk menghapus node pertama, deleteAfter untuk menghapus node setelah node tertentu, deleteLast untuk menghapus node terakhir, nbList untuk menghitung jumlah node dalam list, serta deleteList untuk menghapus seluruh isi list sekaligus. Dengan adanya pengembangan ini, program mampu melakukan operasi manipulasi data yang lebih lengkap pada struktur data linked list secara dinamis.


## main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address P1,P2,P3,P4,P5 = nullptr;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node pertama ---" << endl;
    deleteFirst(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node terakhir ---" << endl;
    deleteLast(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus Node->info = 8 (deleteAfter) ---" << endl;
    deleteAfter(L, P4);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    cout << "--- Menghapus List ---" << endl;
    deleteList(L);
    printInfo(L);
    cout << endl;
    cout << "Jumlah Node : " << nbList(L) << endl;
    cout << endl;

    return 0;
}
```
Program di atas merupakan bagian dari pengujian hasil pengembangan pada tugas unguided2 yang melanjutkan implementasi singly linked list dari unguided1. Program ini berfungsi untuk menguji berbagai operasi manipulasi data dalam list, mulai dari penambahan, penghapusan, hingga penghitungan jumlah elemen. Pertama, list diinisialisasi menggunakan CreateList, kemudian lima node dialokasikan dan dimasukkan ke awal list dengan insertFirst. Setelah itu, isi list serta jumlah node ditampilkan menggunakan printInfo dan nbList. Program kemudian melakukan serangkaian operasi penghapusan, yaitu deleteFirst untuk menghapus node pertama, deleteLast untuk menghapus node terakhir, dan deleteAfter untuk menghapus node setelah node tertentu. Terakhir, deleteList digunakan untuk menghapus seluruh isi list. Setiap tahap menampilkan kondisi list dan jumlah node terkini agar hasil operasi dapat diamati dengan jelas.

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan4_Modul4/unguided/output/unguided2-output.png)

## Kesimpulan
Implementasi singly linked list memungkinkan pengelolaan data secara dinamis melalui operasi penambahan, penghapusan, dan penelusuran elemen dalam list. Melalui percobaan yang dilakukan, dapat dipahami bagaimana setiap fungsi seperti insert, delete, dan alokasi memengaruhi struktur dan isi list. Selain itu, praktikum ini juga memperkuat pemahaman tentang penggunaan pointer dalam menghubungkan antar node serta pentingnya pengaturan memori dengan alokasi dan dealokasi agar tidak terjadi kebocoran memori. Dengan demikian, praktikum ini memberikan dasar yang kuat untuk memahami konsep struktur data dinamis dalam pemrograman.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/