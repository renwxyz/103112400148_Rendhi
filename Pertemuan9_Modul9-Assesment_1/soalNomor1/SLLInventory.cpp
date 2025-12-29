#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List L){
    return (L.head == nullptr);
}

void createList(List &L){
    L.head = nullptr;
}

address allocate(string nama, string sku, int jumlah, float harga, float diskonPersen){
    address newNode = new Node;
    newNode->info.Nama = nama;
    newNode->info.SKU = sku;
    newNode->info.Jumlah = jumlah;
    newNode->info.HargaSatuan = harga;
    newNode->info.DiskonPersen = diskonPersen;
    newNode->next = nullptr;
    return newNode;
}

void insertLast(List &L, address newNode){
    if (isEmpty(L)){
        L.head = newNode;
    } else {
        address current = L.head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}

void deallocate(address targetNode){
    targetNode -> next = nullptr;
    delete targetNode;
}

void deleteFirst(List &L){
    if(isEmpty(L)){
        cout << "List kosong!\n";
    } else {
        address temp;
        temp = L.head;
        L.head = L.head->next;
        temp->next = nullptr;
        deallocate(temp);
        cout << "Berhasil dihapus!\n";
    }
}

void viewList(List L){
    if(isEmpty(L)){
        cout << "List kosong!\n";
    } else {
        address current = L.head;
        while (current != nullptr){
            cout << "\nINFORMASI DATA PRODUCT\n";
            cout << "Nama           : " << current->info.Nama << endl;
            cout << "SKU            : " << current->info.SKU << endl;
            cout << "Jumlah         : " << current->info.Jumlah << endl;
            cout << "Harga satuan   : " << current->info.HargaSatuan << endl;
            cout << "Diskon (persen): " << current->info.DiskonPersen << endl;
            cout << "----------------------\n";
            current = current->next;
        }
    }
}


void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada data untuk di-update.\n";
        return; 
    }
    
    if (posisi < 1) {
        cout << "Posisi tidak valid. Harus >= 1.\n";
        return;
    }

    int counter = 1;
    address current = L.head;


    while (current != nullptr && counter < posisi) {
        current = current->next;
        counter++;
    }

 
    if (current == nullptr) {

        cout << "\nPosisi " << posisi << " berada di luar jangkauan list.\n";
    } else {

        cout << "Data lama di posisi " << posisi << ":\n";
        cout << "Nama           : " << current->info.Nama << endl;
        cout << "SKU            : " << current->info.SKU << endl;
        cout << "Jumlah         : " << current->info.Jumlah << endl;
        cout << "Harga satuan   : " << current->info.HargaSatuan << endl;
        cout << "Diskon (persen): " << current->info.DiskonPersen << endl;
        cout << "----------------------\n";
        
        cout << "Masukkan Nama Baru: ";
        cin >> current->info.Nama;

        cout << "Masukkan SKU Baru: ";
        cin >> current->info.SKU;

        cout << "Masukkan Jumlah Baru: ";
        cin >> current->info.Jumlah;

        cout << "Masukkan Harga Satuan Baru: ";
        cin >> current->info.HargaSatuan;

        cout << "Masukkan Diskon (persen) Baru: ";
        cin >> current->info.DiskonPersen;
        
        cout << "Data di posisi " << posisi << " berhasil di-update!\n";
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice){
    if (isEmpty(L)){
        cout << "List kosong!\n";
    } else {
        address current = L.head;
        bool found = false;
        int posisi = 0;

        cout << "\nProduct dalam range harga " << minPrice << " - " << maxPrice << ":\n";
        while (current != nullptr){
            float price = current->info.HargaSatuan;
            posisi++;
            if(price >= minPrice && price <= maxPrice){
                cout << "Data ditemukan pada posisi " << posisi << ":\n";
                cout << "Nama           : " << current->info.Nama << endl;
                cout << "SKU            : " << current->info.SKU << endl;
                cout << "Jumlah         : " << current->info.Jumlah << endl;
                cout << "Harga satuan   : " << current->info.HargaSatuan << endl;
                cout << "Diskon (persen): " << current->info.DiskonPersen << endl;
                cout << "----------------------\n";
                found = true;
            }
            current = current->next;
        }

        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!\n";
            cout << "----------------------\n";
        }

    }
}

void maxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada data untuk ditampilkan.\n";
        return;
    }

    address current = L.head;
    address maxNode = L.head; 

    float harga = current->info.HargaSatuan;
    float diskon = current->info.DiskonPersen;
    float maxFinalPrice = harga * (1.0 - (diskon / 100.0));

    current = current->next;

    while (current != nullptr) {
        harga = current->info.HargaSatuan;
        diskon = current->info.DiskonPersen;
        float currentFinalPrice = harga * (1.0 - (diskon / 100.0));

        if (currentFinalPrice > maxFinalPrice) {
            maxFinalPrice = currentFinalPrice;
            maxNode = current;
        }

        current = current->next;
    }


    cout << "\nPRODUK DENGAN HARGA FINAL TERTINGGI\n";
    cout << "Nama           : " << maxNode->info.Nama << endl;
    cout << "SKU            : " << maxNode->info.SKU << endl;
    cout << "Harga satuan   : " << maxNode->info.HargaSatuan << endl;
    cout << "Diskon (persen): " << maxNode->info.DiskonPersen << endl;
    cout << "HARGA FINAL TERTINGGI : " << maxFinalPrice << " <==\n";
    cout << "-------------------------------------------\n";
}