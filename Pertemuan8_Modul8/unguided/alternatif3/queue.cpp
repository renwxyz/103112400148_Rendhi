#include "queue.hpp"

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

bool isFullQueue(Queue Q) {
    return Q.count == 5;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    Q.info[Q.tail] = x;
    Q.tail = (Q.tail + 1) % 5;
    Q.count++;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype x = Q.info[Q.head];
    Q.head = (Q.head + 1) % 5;
    Q.count--;
    return x;
}

void printInfo(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " C=" << Q.count << " | ";
    if (!isEmptyQueue(Q)) {
        int idx = Q.head;
        for (int i = 0; i < Q.count; i++) {
            cout << Q.info[idx] << " ";
            idx = (idx + 1) % 5;
        }
    }
    cout << endl;
}
