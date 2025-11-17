#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Pelanggan{
    string nama;
};

typedef struct Node* address;

struct Node{
    Pelanggan infoPelanggan;
    address next;

};

struct Queue{
    address Head;
    address Tail;
};

bool isEmpty(Queue q){}
bool isFull (Queue q){}

void createQueue(Queue &q){}
void clearqueue(Queue &q){}
void viewQueue(Queue &q){}

void enqueue(Queue &q, string namaPelanggan){}
void dequeue(Queue &q){}




#endif