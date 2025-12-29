#include "queue.hpp"

int main() {
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    enqueue(Q,1); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,3); printInfo(Q);
    dequeue(Q);  printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,6); printInfo(Q);

    return 0;
}
