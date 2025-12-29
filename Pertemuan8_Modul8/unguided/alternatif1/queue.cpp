#include "queue.hpp"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i+1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";
    if (!isEmptyQueue(Q)) {
        for (int i = Q.head; i <= Q.tail; i++) cout << Q.info[i] << " ";
    }
    cout << endl;
}
