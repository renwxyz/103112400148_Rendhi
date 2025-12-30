#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data);
Node* insert(Node* root, int data);

// DFS
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

// BFS
void levelOrder(Node* root);

#endif