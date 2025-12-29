#include "queue.hpp"

int main() {
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T | Queue info" << endl;
    cout << "----------------------" << endl;

    enqueue(Q,10); printInfo(Q);
    enqueue(Q,20); printInfo(Q);
    enqueue(Q,30); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,40); printInfo(Q);
    enqueue(Q,50); printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
