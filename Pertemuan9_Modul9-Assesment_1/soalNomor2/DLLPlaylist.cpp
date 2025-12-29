#include "DLLPLAYLIST.H"
#include <iostream>
#include <string>

using namespace std;

bool isEmpty(List L) {
    return (L.head == nullptr && L.tail == nullptr);
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(string title, string artist, int durationSec, int playCount, float rating) {
    address newNode = new Node;
    newNode->info.Title = title;
    newNode->info.Artist = artist;
    newNode->info.DurationSec = durationSec;
    newNode->info.PlayCount = playCount;
    newNode->info.Rating = rating;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void deallocate(address targetNode) {
    delete targetNode;
}

void insertFirst(List &L, address newNode) {
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

void insertLast(List &L, address newNode) {
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void insertAfter(List &L, address targetNode, address newNode) {
    if (targetNode == nullptr) {
        return;
    }

    if (targetNode == L.tail) {
        insertLast(L, newNode);
    } else {
        newNode->next = targetNode->next;
        newNode->prev = targetNode;
        targetNode->next->prev = newNode;
        targetNode->next = newNode;
    }
}

void insertBefore(List &L, address targetNode, address newNode) {
    if (targetNode == nullptr) {
        return;
    }

    if (targetNode == L.head) {
        insertFirst(L, newNode);
    } else {
        newNode->prev = targetNode->prev;
        newNode->next = targetNode;
        targetNode->prev->next = newNode;
        targetNode->prev = newNode;
    }
}

void deleteFirst(List &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address temp = L.head;
        if (L.head == L.tail) {
            L.head = nullptr;
            L.tail = nullptr;
        } else {
            L.head = L.head->next;
            L.head->prev = nullptr;
        }
        deallocate(temp);
    }
}

void deleteLast(List &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address temp = L.tail;
        if (L.head == L.tail) {
            L.head = nullptr;
            L.tail = nullptr;
        } else {
            L.tail = L.tail->prev;
            L.tail->next = nullptr;
        }
        deallocate(temp);
    }
}

void deleteAfter(List &L, address targetNode) {
    if (targetNode == nullptr || targetNode == L.tail) {
        cout << "Hapus gagal. Target kosong atau merupakan tail." << endl;
        return;
    }

    if (targetNode->next == L.tail) {
        deleteLast(L);
    } else {
        address temp = targetNode->next;
        targetNode->next = temp->next;
        temp->next->prev = targetNode;
        deallocate(temp);
    }
}

void deleteBefore(List &L, address targetNode) {
    if (targetNode == nullptr || targetNode == L.head) {
        cout << "Hapus gagal. Target kosong atau merupakan head." << endl;
        return;
    }

    if (targetNode->prev == L.head) {
        deleteFirst(L);
    } else {
        address temp = targetNode->prev;
        targetNode->prev = temp->prev;
        temp->prev->next = targetNode;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)) {
        cout << "List Kosong. Gagal update." << endl;
        return;
    }
    if (posisi < 1) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    address current = L.head;
    int counter = 1;
    while (current != nullptr && counter < posisi) {
        current = current->next;
        counter++;
    }

    if (current == nullptr) {
        cout << "Posisi pada " << posisi << " tidak ditemukan." << endl;
    } else {
        cout << "Update data pada posisi " << posisi << ":" << endl;
        cout << "Title: " << current->info.Title << endl;
        cout << "Masukkan Title baru: ";
        getline(cin >> ws, current->info.Title);

        cout << "Artist: " << current->info.Artist << endl;
        cout << "Masukkan Artist Baru: ";
        getline(cin >> ws, current->info.Artist);

        cout << "Duration (sec): " << current->info.DurationSec << endl;
        cout << "Masukkan Duration (sec) terbaru: ";
        cin >> current->info.DurationSec;

        cout << "Play Count: " << current->info.PlayCount << endl;
        cout << "Masukkan Play Count terbaru: ";
        cin >> current->info.PlayCount;

        cout << "Rating: " << current->info.Rating << endl;
        cout << "Masukkan Rating baru: ";
        cin >> current->info.Rating;

        cout << "Update berhasil." << endl;
    }
}

void updateBefore(List &L, address targetNode) {
    if (targetNode == nullptr || targetNode == L.head) {
        cout << "Update gagal. Target kosong atau merupakan head." << endl;
        return;
    }

    address current = targetNode->prev;
    
    cout << "Update data untuk node sebelum: '" << targetNode->info.Title << "':" << endl;
    cout << "Title: " << current->info.Title << endl;
    cout << "Masukkan Title baru: ";
    getline(cin >> ws, current->info.Title);

    cout << "Artist: " << current->info.Artist << endl;
    cout << "Masukkan Artist baru: ";
    getline(cin >> ws, current->info.Artist);

    cout << "Duration (sec): " << current->info.DurationSec << endl;
    cout << "Masukkan Duration (sec) baru: ";
    cin >> current->info.DurationSec;

    cout << "Play Count: " << current->info.PlayCount << endl;
    cout << "Masukkan Play Count baru: ";
    cin >> current->info.PlayCount;

    cout << "Rating: " << current->info.Rating << endl;
    cout << "Masukkan Rating baru: ";
    cin >> current->info.Rating;

    cout << "Update berhasil." << endl;
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong." << endl;
    } else {
        address current = L.head;
        int i = 1;
        cout << "========== MY PLAYLIST ==========" << endl;
        while (current != nullptr) {
            cout << "--- Song #" << i << " ---" << endl;
            cout << "Title    : " << current->info.Title << endl;
            cout << "Artist   : " << current->info.Artist << endl;
            cout << "Duration : " << current->info.DurationSec << "s" << endl;
            cout << "Played   : " << current->info.PlayCount << " times" << endl;
            cout << "Rating   : " << current->info.Rating << "/5.0" << endl;
            cout << "--------------------" << endl;
            current = current->next;
            i++;
        }
        cout << "=================================" << endl;
    }
}