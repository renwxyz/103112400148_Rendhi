#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

#define Nil NULL

struct Node {
    int idProduk;          
    string namaProduk;
    int stok;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(int id, string nama, int stok);

void insertNode(address &root, int id, string nama, int stok);
address searchById(address root, int id);
address searchByProduct(address root, string nama);
void deleteNode(address &root, int id);
void deleteTree(address &root);

void inOrder(address root);
void preOrder(address root);
void postOrder(address root);

address findMin(address root);
address findMax(address root);

#endif
