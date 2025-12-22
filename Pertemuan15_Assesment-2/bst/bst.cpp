#include "bst.h"

address alokasi(int id, string nama, int stok) {
    address P = new Node;
    P->idProduk = id;
    P->namaProduk = nama;
    P->stok = stok;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, int id, string nama, int stok) {
    if (root == Nil) {
        root = alokasi(id, nama, stok);
    } else if (id < root->idProduk) {
        insertNode(root->left, id, nama, stok);
    } else if (id > root->idProduk) {
        insertNode(root->right, id, nama, stok);
    }
}

address searchById(address root, int id) {
    if (root == Nil || root->idProduk == id)
        return root;

    if (id < root->idProduk)
        return searchById(root->left, id);
    else
        return searchById(root->right, id);
}

address searchByProduct(address root, string nama) {
    if (root == Nil)
        return Nil;

    if (root->namaProduk == nama)
        return root;

    address kiri = searchByProduct(root->left, nama);
    if (kiri != Nil)
        return kiri;

    return searchByProduct(root->right, nama);
}

address findMin(address root) {
    while (root && root->left != Nil)
        root = root->left;
    return root;
}

address findMax(address root) {
    while (root && root->right != Nil)
        root = root->right;
    return root;
}

void deleteNode(address &root, int id) {
    if (root == Nil) return;

    if (id < root->idProduk) {
        deleteNode(root->left, id);
    } else if (id > root->idProduk) {
        deleteNode(root->right, id);
    } else {
        if (root->left == Nil && root->right == Nil) {
            delete root;
            root = Nil;
        }
        else if (root->left == Nil) {
            address temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == Nil) {
            address temp = root;
            root = root->left;
            delete temp;
        }
        else {
            address temp = findMin(root->right);
            root->idProduk = temp->idProduk;
            root->namaProduk = temp->namaProduk;
            root->stok = temp->stok;
            deleteNode(root->right, temp->idProduk);
        }
    }
}

void deleteTree(address &root) {
    if (root != Nil) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = Nil;
    }
}

void inOrder(address root) {
    if (root != Nil) {
        inOrder(root->left);
        cout << root->idProduk << " | "
             << root->namaProduk << " | stok: "
             << root->stok << endl;
        inOrder(root->right);
    }
}

void preOrder(address root) {
    if (root != Nil) {
        cout << root->idProduk << " | "
             << root->namaProduk << " | stok: "
             << root->stok << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->idProduk << " | "
             << root->namaProduk << " | stok: "
             << root->stok << endl;
    }
}
