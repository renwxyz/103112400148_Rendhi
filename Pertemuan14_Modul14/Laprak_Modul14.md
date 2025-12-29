# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data 

### 1. Pengertian Graph
Graph adalah struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar objek, di mana data dinyatakan dalam bentuk himpunan simpul (vertex) dan himpunan sisi (edge) yang menghubungkan antar simpul tersebut. Graph digunakan untuk memodelkan berbagai jenis relasi data, baik yang bersifat terarah (directed) maupun tidak terarah (undirected), sehingga banyak diterapkan pada permasalahan seperti jaringan komputer, peta rute, media sosial, dan hubungan antar entitas dalam sistem komputer [3]

### 2. Properti Graph
Properti graph merupakan karakteristik yang dimiliki oleh suatu graph untuk menggambarkan struktur dan hubungan antar simpul di dalamnya. Beberapa properti utama graph meliputi vertex (simpul) sebagai elemen dasar graph, edge (sisi) sebagai penghubung antar simpul, derajat (degree)** yang menunjukkan jumlah sisi yang terhubung pada suatu simpul, arah (directed atau undirected) yang menunjukkan ada atau tidaknya orientasi sisi, serta bobot (weight) pada sisi yang merepresentasikan nilai atau biaya tertentu. Properti-properti ini digunakan untuk menganalisis dan menentukan perilaku graph dalam berbagai penerapan komputasi [3].

## Guided 

### 1. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

### 2. graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>     //library queue untuk BFS
#include <stack>     //library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "--- REPRESENTASI ADJACENCY LIST ---" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "--- HASIL TRAVERSAL ---" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "--- HAPUS NODE E ---" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "--- REPRESENTASI ADJACENCY LIST ---" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "--- HASIL TRAVERSAL ---" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```

## Unguided

### 1. graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
adrNode FindNode(Graph G, infoGraph data);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);

void PrintBFS(Graph G, adrNode N);
void PrintDFS(Graph G, adrNode N);

#endif
```

### 2. graph.cpp

```C++
#include "graph.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph data) {
    adrNode newNode = new ElmNode;
    newNode->info = data;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    return newNode;
}

adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = nodeTujuan;
    newEdge->Next = NULL;
    return newEdge;
}

void InsertNode(Graph &G, infoGraph data) {
    adrNode newNode = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = newNode;
    } else {
        adrNode P = G.First;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph data) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == data) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = AlokasiEdge(node2);
        edge1->Next = node1->firstEdge;
        node1->firstEdge = edge1;

        adrEdge edge2 = AlokasiEdge(node1);
        edge2->Next = node2->firstEdge;
        node2->firstEdge = edge2;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    
    if (N == NULL) {
        return;
    }

    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode currNode = Q.front();
        Q.pop();
        cout << currNode->info << " ";

        adrEdge E = currNode->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}

void PrintDFS(Graph G, adrNode N) {
    ResetVisited(G);

    if (N == NULL) {
        return;
    }

    stack<adrNode> S;
    S.push(N);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode currNode = S.top();
        S.pop();

        if (currNode->visited == 0) {
            currNode->visited = 1;
            cout << currNode->info << " ";

            adrEdge E = currNode->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    S.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== INFORMASI GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode StartNode = FindNode(G, 'A');

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintDFS(G, StartNode);
    PrintBFS(G, StartNode);

    return 0;
}
```

### Output Unguided :

##### Output
![Screenshot Output Unguided](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan14_Modul14/unguided/output/output.png)

## Deskripsi
Berdasarkan hasil eksekusi program pada Modul 14, output menampilkan representasi graph dalam bentuk adjacency list, di mana setiap node ditunjukkan beserta node-node lain yang terhubung dengannya. Pada bagian informasi graph, terlihat bahwa setiap simpul (A sampai H) memiliki relasi yang sesuai dengan proses penghubungan (connect) yang telah dilakukan pada program. Hal ini menunjukkan bahwa struktur graph tidak berarah (undirected) telah terbentuk dengan benar.

Selanjutnya, dilakukan proses traversal menggunakan metode Depth First Search (DFS) dan Breadth First Search (BFS) dengan titik awal pada node A. Hasil traversal DFS menampilkan urutan kunjungan simpul berdasarkan penelusuran mendalam ke satu cabang terlebih dahulu sebelum berpindah ke cabang lain, sedangkan traversal BFS menampilkan urutan kunjungan simpul secara melebar berdasarkan tingkat kedekatan node dengan node awal. Perbedaan urutan hasil DFS dan BFS menunjukkan bahwa kedua metode traversal bekerja sesuai dengan konsep dan algoritma graph yang digunakan. Output yang dihasilkan membuktikan bahwa proses pembentukan graph dan traversal telah berjalan dengan benar.

## Kesimpulan
Berdasarkan praktikum Modul 14, dapat disimpulkan bahwa struktur data Graph mampu merepresentasikan hubungan antar data secara fleksibel dan kompleks. Implementasi graph menggunakan bahasa C++ dengan representasi adjacency list berhasil dilakukan, ditunjukkan oleh keberhasilan penambahan node, penghubungan antar node, serta penelusuran graph menggunakan algoritma DFS dan BFS. Praktikum ini memberikan pemahaman yang lebih mendalam mengenai konsep graph, perbedaan metode traversal, serta penerapannya dalam pemodelan relasi data seperti jaringan dan jalur koneksi. Dengan demikian, mahasiswa mampu memahami dan mengimplementasikan graph sebagai salah satu struktur data non-linier yang penting dalam pemrograman dan algoritma.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/
<br>[3] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.