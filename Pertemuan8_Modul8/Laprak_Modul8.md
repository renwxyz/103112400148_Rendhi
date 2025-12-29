# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data 

### 1. Pengertian Queue dan Prinsip FIFO
Queue atau Antrian adalah struktur data linear yang bekerja secara ketat berdasarkan prinsip FIFO (First In First Out), yang secara harfiah berarti elemen yang pertama kali dimasukkan ke dalam antrian adalah elemen yang pertama kali akan dikeluarkan. Prinsip ini mendefinisikan Queue sebagai koleksi data yang mana proses penambahan (Enqueue) dan penghapusan (Dequeue) selalu dilakukan melalui ujung yang berbeda. Sifat ini menjadikan Queue sangat cocok untuk memodelkan proses yang memerlukan urutan layanan yang adil, seperti antrian cetak dokumen pada printer atau antrian tugas pada sistem operasi.

### 2. Implementasi dengan Array dan Struct (Statis)
Queue dapat diimplementasikan secara statis menggunakan Array (larik), yaitu tipe data terstruktur yang digunakan sebagai wadah penyimpanan utama dengan batasan ukuran tertentu yang telah dideklarasikan sebelumnya. Untuk data yang lebih kompleks (memiliki banyak atribut), digunakan tipe data bentukan Struct atau Record untuk mendefinisikan struktur setiap elemen sebelum disimpan dalam array tersebut, sehingga program dapat menangani elemen data yang terdiri dari berbagai tipe sekaligus.

### 3. Implementasi dengan Linked List (Dinamis)
Alternatif implementasi Queue adalah secara dinamis menggunakan Linked List, di mana elemen-elemennya (disebut node) saling terhubung menggunakan pointer alih-alih indeks Array. Keunggulan implementasi dinamis adalah efisiensi penggunaan memori, karena Queue dapat tumbuh dan menyusut ukurannya sesuai dengan kebutuhan program pada saat dijalankan (runtime). Setiap node dalam Linked List ini akan selalu memiliki dua penunjuk utama, yaitu Front (penghapusan) dan Rear (penambahan).

### 4. Operasi dan Konsep Modularitas
Pengelolaan Queue yang optimal dilakukan dengan menerapkan Pemrograman Modular, yaitu memecah setiap operasi dasar menjadi Prosedur atau Fungsi tersendiri agar kode program menjadi lebih terstruktur, mudah dibaca, dan meminimalisir kesalahan. Operasi penting seperti Enqueue (penambahan elemen di Rear), Dequeue (pengambilan elemen dari Front), IsEmpty (cek kekosongan), dan IsFull (cek kepenuhan, hanya pada Array) wajib diimplementasikan sebagai modul terpisah, yang kesemuanya harus mengikuti aturan algoritma FIFO.

## Guided 1

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL
using namespace std;
#include <string>

struct Node {
    std::string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue& Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue& Q, const string& nama);
void deQueue(queue& Q);
void viewQueue(queue Q);
void clearQueue(queue& Q);

#endif

```

### 2. queue.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "Nama " << nama << " berhasil ditambahkan ke dalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

```

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    cout << endl;
    return 0;
}
```

## Guided 2

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### 2. queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

## Unguided - alternatif 1

### 1. queue.hpp

```C++
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### 2. queue.cpp

```C++
#include "queue.hpp"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i+1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";
    if (!isEmptyQueue(Q)) {
        for (int i = Q.head; i <= Q.tail; i++) cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "queue.hpp"

int main() {
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T | Queue info" << endl;
    cout << "----------------------" << endl;
    
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    dequeue(Q);  printInfo(Q);

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan8_Modul8/unguided/output/alternatif1.png)

## Deskripsi
Program ini mengimplementasikan struktur data queue sederhana menggunakan bahasa C++ dengan pendekatan array statis berukuran tetap. Queue didefinisikan dengan konsep FIFO (First In First Out) yang memiliki dua penunjuk, yaitu head dan tail, untuk mengatur posisi data. Program ini menyediakan fungsi-fungsi dasar seperti inisialisasi queue, pengecekan kondisi kosong dan penuh, operasi enqueue untuk menambahkan data, dequeue untuk menghapus data, serta fungsi untuk menampilkan isi queue beserta posisi head dan tail. Melalui file main, saya melakukan pengujian dengan beberapa operasi enqueue dan dequeue untuk memastikan queue bekerja sesuai dengan konsep yang diharapkan.

## Unguided - alternatif 2

### 1. queue.hpp
```C++
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### 2. queue.cpp

```C++
#include "queue.hpp"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";
    if (!isEmptyQueue(Q)) {
        for (int i = Q.head; i <= Q.tail; i++) cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "queue.hpp"

int main() {
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    enqueue(Q,10); printInfo(Q);
    enqueue(Q,20); printInfo(Q);
    enqueue(Q,30); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,40); printInfo(Q);
    enqueue(Q,50); printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan8_Modul8/unguided/output/alternatif2.png)

## Deskripsi
Program ini mengimplementasikan struktur data queue berbasis array statis dengan ukuran tetap menggunakan bahasa C++. Queue bekerja dengan prinsip FIFO (First In First Out) dan dikelola menggunakan dua indeks, yaitu head dan tail, untuk menandai posisi awal dan akhir data. Di dalam program ini tersedia fungsi untuk melakukan inisialisasi queue, mengecek kondisi kosong dan penuh, menambahkan data (enqueue), menghapus data (dequeue), serta menampilkan isi queue beserta nilai head dan tail. Pada bagian main, saya melakukan serangkaian operasi enqueue dan dequeue sebagai simulasi penggunaan queue agar dapat terlihat perubahan isi dan posisi data secara bertahap.

## Unguided - alternatif 3

### 1. queue.hpp
```C++
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### 2. queue.cpp

```C++
#include "queue.hpp"

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

bool isFullQueue(Queue Q) {
    return Q.count == 5;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    Q.info[Q.tail] = x;
    Q.tail = (Q.tail + 1) % 5;
    Q.count++;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype x = Q.info[Q.head];
    Q.head = (Q.head + 1) % 5;
    Q.count--;
    return x;
}

void printInfo(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " C=" << Q.count << " | ";
    if (!isEmptyQueue(Q)) {
        int idx = Q.head;
        for (int i = 0; i < Q.count; i++) {
            cout << Q.info[idx] << " ";
            idx = (idx + 1) % 5;
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "queue.hpp"

int main() {
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    enqueue(Q,1); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,3); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,6); printInfo(Q);

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided ](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan8_Modul8/unguided/output/alternatif3.png)

## Deskripsi
Program ini mengimplementasikan struktur data queue menggunakan konsep circular queue berbasis array statis dengan kapasitas tetap menggunakan bahasa C++. Queue dikelola dengan tiga atribut utama, yaitu head, tail, dan count, yang berfungsi untuk mengatur posisi data serta jumlah elemen yang tersimpan. Operasi enqueue dan dequeue dilakukan secara melingkar (circular) menggunakan operator modulo agar pemanfaatan array lebih efisien tanpa perlu pergeseran data. Program ini juga dilengkapi dengan fungsi pengecekan kondisi kosong dan penuh, serta fungsi untuk menampilkan isi queue beserta nilai head, tail, dan count. Pada bagian main, saya melakukan beberapa operasi untuk menunjukkan cara kerja circular queue dan perubahan data secara berurutan.

## Kesimpulan
Berdasarkan implementasi yang telah dibuat, dapat disimpulkan bahwa penggunaan circular queue dengan bantuan variabel head, tail, dan count mampu mengelola data secara lebih efisien dibandingkan queue biasa karena tidak memerlukan pergeseran elemen saat proses dequeue. Konsep FIFO tetap terjaga, sementara pemanfaatan array menjadi optimal melalui mekanisme indeks melingkar. Program ini menunjukkan bahwa dengan logika yang tepat, struktur data queue dapat diimplementasikan secara sederhana namun efektif untuk menangani proses penyimpanan dan pengambilan data secara terurut.


## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/