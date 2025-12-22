#include "graph.h"
#include <queue>
#include <stack>

void createGraph(GraphKota &G) {
    G.first = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, string nama) {
    adrKota P = alokasiNode(nama);
    P->next = G.first;
    G.first = P;
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        if (P->namaKota == nama)
            return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(adrKota A, adrKota B, int jarak) {
    if (A == NULL || B == NULL) return;

    adrEdge E1 = alokasiEdge(B, jarak);
    E1->next = A->firstEdge;
    A->firstEdge = E1;

    adrEdge E2 = alokasiEdge(A, jarak);
    E2->next = B->firstEdge;
    B->firstEdge = E2;
}

void disconnectNode(adrKota A, adrKota B) {
    adrEdge prev = NULL, curr = A->firstEdge;
    while (curr != NULL) {
        if (curr->kotaTujuan == B) {
            if (prev == NULL)
                A->firstEdge = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    prev = NULL;
    curr = B->firstEdge;
    while (curr != NULL) {
        if (curr->kotaTujuan == A) {
            if (prev == NULL)
                B->firstEdge = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota target = findNode(G, nama);
    if (target == NULL) return;

    adrKota P = G.first;
    while (P != NULL) {
        if (P != target)
            disconnectNode(P, target);
        P = P->next;
    }

    if (G.first == target) {
        G.first = target->next;
    } else {
        adrKota prev = G.first;
        while (prev->next != target)
            prev = prev->next;
        prev->next = target->next;
    }

    delete target;
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;

    adrKota P = G.first;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->kotaTujuan->namaKota
                 << " (" << E->jarak << " KM)";
            if (E->next != NULL) cout << ", ";
            E = E->next;
        }
        cout << "," << endl;
        P = P->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota &G, adrKota start) {
    if (start == NULL) return;

    queue<adrKota> Q;
    start->visited = 1;
    Q.push(start);

    cout << "BFS Traversal: ";

    while (!Q.empty()) {
        adrKota P = Q.front();
        Q.pop();
        cout << P->namaKota << " - ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->kotaTujuan->visited == 0) {
                E->kotaTujuan->visited = 1;
                Q.push(E->kotaTujuan);
            }
            E = E->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota &G, adrKota start) {
    if (start == NULL) return;

    stack<adrKota> S;
    S.push(start);

    cout << "DFS Traversal: ";

    while (!S.empty()) {
        adrKota P = S.top();
        S.pop();

        if (P->visited == 0) {
            P->visited = 1;
            cout << P->namaKota << " - ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->kotaTujuan->visited == 0)
                    S.push(E->kotaTujuan);
                E = E->next;
            }
        }
    }
    cout << endl;
}


