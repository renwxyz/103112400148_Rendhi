#include "graph.h"

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Bekasi");
    insertNode(G, "Tangerang");

    connectNode(findNode(G,"Bogor"), findNode(G,"Bekasi"), 60);
    connectNode(findNode(G,"Bogor"), findNode(G,"Jakarta"), 42);
    connectNode(findNode(G,"Bogor"), findNode(G,"Depok"), 22);

    connectNode(findNode(G,"Jakarta"), findNode(G,"Bekasi"), 16);
    connectNode(findNode(G,"Jakarta"), findNode(G,"Depok"), 21);
    connectNode(findNode(G,"Jakarta"), findNode(G,"Tangerang"), 24);

    connectNode(findNode(G,"Depok"), findNode(G,"Bekasi"), 25);
    connectNode(findNode(G,"Depok"), findNode(G,"Tangerang"), 30);

    connectNode(findNode(G,"Bekasi"), findNode(G,"Tangerang"), 45);

    printGraph(G);
    cout << endl;

    deleteNode(G, "Depok");

    printGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;

    resetVisited(G);
    printBFS(G, findNode(G, "Tangerang"));

    resetVisited(G);
    printDFS(G, findNode(G, "Tangerang"));

    return 0;
}
