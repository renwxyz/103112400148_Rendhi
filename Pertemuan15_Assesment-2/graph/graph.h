#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef struct ElmKota* adrKota;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct ElmKota {
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct GraphKota {
    adrKota first;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota tujuan, int jarak);

void insertNode(GraphKota &G, string nama);
adrKota findNode(GraphKota G, string nama);

void connectNode(adrKota A, adrKota B, int jarak);
void disconnectNode(adrKota A, adrKota B);

void deleteNode(GraphKota &G, string nama);
void printGraph(GraphKota G);

void resetVisited(GraphKota &G);
void printBFS(GraphKota &G, adrKota start);
void printDFS(GraphKota &G, adrKota start);


#endif
