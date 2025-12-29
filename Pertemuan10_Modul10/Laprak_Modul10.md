# <h1 align="center">Laporan Praktikum Modul 10 - Binary Search Tree</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data 

### 1. Pengertian Tree
Tipe data tree adalah struktur data non-linier yang digunakan untuk merepresentasikan data dalam bentuk hierarki, terdiri dari simpul (node) yang saling terhubung melalui relasi induk–anak. Tree memiliki satu simpul utama yang disebut root, dan setiap simpul dapat memiliki nol atau lebih anak, tetapi hanya satu induk (kecuali root). Struktur ini umum digunakan untuk merepresentasikan data bertingkat seperti struktur folder, silsilah, dan organisasi data dalam komputer.

### 2. Pengertian Binary Search Tree
Binary Search Tree (BST) adalah jenis tree biner yang memiliki aturan khusus, yaitu setiap simpul (node) memiliki paling banyak dua anak, di mana nilai pada anak kiri selalu lebih kecil dari nilai simpul induk, dan nilai pada anak kanan selalu lebih besar. Dengan aturan ini, BST memungkinkan proses pencarian, penyisipan, dan penghapusan data dilakukan secara efisien, sehingga sering digunakan dalam pengelolaan data terurut dan algoritma pencarian.


## Guided 

### 1. bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);


void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);

node mostRight(BinTree tree);
node mostLeft(BinTree tree);

void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);


#endif
```

### 2. xxx.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

## Unguided

### 1. bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
struct Node {
    infotype info;
    Node *left;
    Node *right;
};
typedef Node* address;

address alokasi(infotype x);                                  
void insertNode(address &root, infotype x);                   
address findNode(infotype x, address root);                   
void printInOrder(address root);                              

int hitungKedalaman(address root);                            
int hitungJumlahNode(address root);                           
int hitungTotal(address root);                                

void printPreOrder(address root);                             
void printPostOrder(address root);                            

#endif
```

### 2. bst.cpp

```C++
#include "bst.h"
using namespace std;

address alokasi(infotype x) {           
    address p = new Node;
    p->info  = x;
    p->left  = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {   
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInOrder(address root) {              
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

int hitungKedalaman(address root) {
    if (root == Nil) return 0;
    int L = hitungKedalaman(root->left);
    int R = hitungKedalaman(root->right);
    return (L > R ? L : R) + 1;
}

int hitungJumlahNode(address root) {          
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

int hitungTotal(address root) {              
    if (root == Nil) return 0;
    return root->info + hitungTotal(root->left)
                      + hitungTotal(root->right);
}

void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {           
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}
```

### soal1.cpp

```C++
// main_soal1.cpp
#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);     
    cout << endl;

    return 0;
}
```

### soal2.cpp

```C++
#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);
    cout << endl;

    cout << "kedalaman : "   << hitungKedalaman(root)    << endl;
    cout << "jumlah node : " << hitungJumlahNode(root)   << endl;
    cout << "total : "       << hitungTotal(root)        << endl;

    return 0;
}
```

### soal3.cpp

```C++
#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    address root = Nil;
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "Pre-order  : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-order : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan10_Modul10/unguided/output/output.png)

## Deskripsi
Pada praktikum Modul 10 ini, dilakukan implementasi struktur data Binary Search Tree (BST) menggunakan bahasa pemrograman C++. Praktikum diawali dengan pembuatan header file (bst.h) dan file implementasi (bst.cpp) yang berisi fungsi-fungsi dasar BST, seperti alokasi node, penyisipan data, pencarian node, serta traversal tree. Selain itu, diimplementasikan pula fungsi tambahan untuk menghitung kedalaman tree, jumlah node, dan total nilai seluruh node. Pada bagian unguided, program diuji melalui beberapa file main (soal1.cpp, soal2.cpp, dan soal3.cpp) untuk menampilkan hasil traversal inorder, preorder, dan postorder, serta untuk memastikan fungsi perhitungan bekerja dengan benar. Hasil output menunjukkan bahwa struktur BST dan seluruh operasi yang dibuat dapat berjalan sesuai dengan konsep dan teori yang dipelajari.

## Kesimpulan
Berdasarkan hasil praktikum Modul 10, dapat disimpulkan bahwa struktur data Binary Search Tree (BST) mampu mengelola data secara terurut dengan aturan tertentu sehingga proses pencarian, penyisipan, dan pengolahan data dapat dilakukan secara efisien. Implementasi BST menggunakan bahasa C++ berhasil dilakukan dengan baik, dibuktikan melalui keberhasilan traversal inorder, preorder, dan postorder, serta perhitungan kedalaman, jumlah node, dan total nilai node. Dengan praktikum ini, mahasiswa dapat memahami konsep hierarki pada tree, cara kerja BST, serta penerapannya dalam pemrograman secara lebih mendalam dan praktis.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/
<br>[3] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.