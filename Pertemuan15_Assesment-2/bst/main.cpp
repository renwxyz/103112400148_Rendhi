#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    address root = Nil;

    insertNode(root, 50, "Monitor LED", 10);
    insertNode(root, 30, "Keyboard RGB", 20);
    insertNode(root, 70, "Mouse Gaming", 15);
    insertNode(root, 20, "Kabel HDMI", 50);
    insertNode(root, 40, "Headset 7.1", 12);
    insertNode(root, 60, "Webcam HD", 8);
    insertNode(root, 80, "Speaker BT", 5);

    cout << "\n=== InOrder ===\n";
    inOrder(root);

    cout << "\n=== PreOrder ===\n";
    preOrder(root);

    cout << "\n=== PostOrder ===\n";
    postOrder(root);

    cout << "\n=== Search ID 40 ===\n";
    address P = searchById(root, 40);
    if (P != Nil)
        cout << "Ditemukan: " << P->namaProduk << " | stok: " << P->stok << endl;
    else
        cout << "Produk tidak ditemukan\n";

    cout << "\n=== Search ID 99 ===\n";
    P = searchById(root, 99);
    if (P != Nil)
        cout << "Ditemukan: " << P->namaProduk << endl;
    else
        cout << "Produk tidak ditemukan\n";

    cout << "\n=== Search Produk: Webcam HD ===\n";
    P = searchByProduct(root, "Webcam HD");
    if (P != Nil)
        cout << "ID: " << P->idProduk << " | stok: " << P->stok << endl;
    else
        cout << "Produk tidak ditemukan\n";

    cout << "\n=== Search Produk: Printer ===\n";
    P = searchByProduct(root, "Printer");
    if (P != Nil)
        cout << "ID: " << P->idProduk << endl;
    else
        cout << "Produk tidak ditemukan\n";

    cout << "\n=== Min & Max ===\n";
    cout << "Min ID : " << findMin(root)->idProduk << endl;
    cout << "Max ID : " << findMax(root)->idProduk << endl;

    cout << "\n=== Delete ID 20 ===\n";
    deleteNode(root, 20);

    cout << "\nInOrder setelah delete 20:\n";
    inOrder(root);

    cout << "\n=== Delete ID 30 ===\n";
    deleteNode(root, 30);


    cout << "\nInOrder setelah delete 30:\n";
    inOrder(root);

    cout << "\n=== Delete ID 50 ===\n";
    deleteNode(root, 50);

    cout << "\nInOrder setelah delete 50:\n";
    inOrder(root);

    cout << "\n=== Delete Tree ===\n";
    deleteTree(root);

    cout << "\nInOrder setelah deleteTree:\n";
    inOrder(root);

    return 0;
}
