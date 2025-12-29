# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data

### 1. Pengertian Stack dan Array
Stack merupakan struktur data linear berprinsip LIFO (Last In First Out), yang dalam implementasinya pada bahasa C++ sering memanfaatkan struktur Array (larik). Array didefinisikan sebagai tipe data terstruktur yang terdiri dari sejumlah komponen dengan tipe yang sama, sehingga memungkinkan penyimpanan banyak data secara efisien dalam satu nama variabel untuk membentuk tumpukan.

### 2. Implementasi Data dengan Struct
Untuk menangani elemen data yang kompleks dalam tumpukan, pemrograman C++ menyediakan tipe data bentukan yang disebut Struct atau Record, yang disusun oleh satu atau lebih field. Tipe data ini memungkinkan penggabungan berbagai tipe data dasar menjadi satu kesatuan tipe baru yang terdefinisi sendiri, sehingga sangat berguna untuk merepresentasikan simpul data dalam Stack yang memiliki beragam atribut.

### 3. Implementasi dengan Linked List
Stack dengan implementasi Linked List adalah struktur data dinamis yang operasinya mengikuti algoritma sistematis untuk penyelesaian masalah , di mana setiap elemen atau node direpresentasikan menggunakan tipe data bentukan Struct (Record) yang dapat menyimpan sekumpulan variabel dengan tipe berbeda dalam satu kesatuan. Pengelolaan tumpukan ini menerapkan konsep pemrograman modular dengan memecah operasi utama seperti push dan pop menjadi sub-program yang lebih kecil agar kode program menjadi lebih ringkas dan mudah dipahami. Implementasi modular tersebut diwujudkan melalui Prosedur untuk operasi tanpa nilai balik dan Fungsi untuk operasi yang wajib mengembalikan nilai keluaran, sehingga struktur program menjadi lebih terorganisir dan meminimalisir kesalahan

### 4. Operasi Dasar dan Modularitas
Pengelolaan operasi Stack disusun menggunakan metode Pemrograman Modular, yaitu memecah masalah besar menjadi beberapa kelompok masalah yang lebih kecil agar program menjadi lebih ringkas dan kesalahan (bug) lebih mudah ditelusuri karena bersifat lokal. Implementasinya dibagi menjadi dua bentuk modul: Prosedur yang tidak mengembalikan nilai secara langsung, dan Fungsi yang wajib mengembalikan nilai keluaran (return value) ke pemanggilnya.


## Guided 1

### 1. stack.h

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

## Guided 2

### 1. stack.h

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
} 

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}

```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

## Unguided

### 1. stack.h
```C++
#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif
```

### 2. stack.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX_STACK - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top >= MAX_STACK - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);
    
    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan karakter (akhiri dengan Enter): ";
    while (true) {
        ch = cin.get();
        if (ch == '\n'){
            break;
        }
        
        if (isdigit(ch)) {
            int num = ch - '0';
            push(S, num);
        }
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include <limits>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int nomorSoal;
    
    cin >> nomorSoal;

    if (nomorSoal == 3) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (nomorSoal){
        case 1:
            cout << "Hello world!" << endl;
            createStack(S);
            push(S,3);
            push(S,4);
            push(S,8);
            pop(S);
            push(S,2);
            push(S,3);
            pop(S);
            push(S,9);
            printInfo(S);
            cout<<"balik stack"<<endl;
            balikStack(S);
            printInfo(S);
            break;
        case 2:
            cout << "Hello world!" << endl;
            createStack(S);
            pushAscending(S,3);
            pushAscending(S,4);
            pushAscending(S,8);
            pushAscending(S,2);
            pushAscending(S,3);
            pushAscending(S,9);
            printInfo(S);
            cout<<"balik stack"<<endl;
            balikStack(S);
            printInfo(S);
            break;
        case 3:
            cout << "Hello world!" << endl;
            createStack(S);
            getInputStream(S);
            printInfo(S);
            
            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        default:
            cout << "Nomor soal tidak valid\n";
            break;
    }

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan7_Modul7/unguided/output/output.png)

## Deskripsi
Output tersebut menampilkan eksekusi program Stack yang berhasil mendemonstrasikan operasi pembalikan urutan elemen. Awalnya, program menampilkan isi Stack dalam urutan 9, 4, 3, 2, 3 (dimulai dari TOP). Setelah fungsi balikStack(S) dijalankan, program kembali menampilkan isi Stack, yang kini urutannya telah berhasil dibalik secara keseluruhan menjadi 3, 2, 3, 4, 9, membuktikan bahwa implementasi fungsi balikStack telah berhasil bekerja sesuai kaidah struktur data tumpukan

## Kesimpulan
Kesimpulan dari praktikum Stack ini menegaskan prinsip LIFO (Last In First Out) yang menjadi dasar operasi tumpukan. Praktikum berhasil menunjukkan bahwa elemen data hanya dapat ditambahkan (Push) dan dikeluarkan (Pop) melalui satu pintu akses, yaitu bagian teratas (TOP). Selain itu, implementasi operasi pembalikan (balikStack) berhasil membuktikan sifat dinamis dari Stack, di mana seluruh urutan elemen dalam tumpukan berhasil dibalik secara efektif, menunjukkan kemampuan manipulasi data Stack yang kompleks tanpa melanggar prinsip LIFO saat operasi dilakukan.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/