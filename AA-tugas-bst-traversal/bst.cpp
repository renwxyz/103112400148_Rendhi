
#include "bst.hpp"

Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insert(Node* root, int data) {
    if (root == nullptr){
        return createNode(data);
    }

    if (data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// DFS 
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << char(root->data) << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << char(root->data) << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << char(root->data) << " ";
}

// BFS
void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << char(curr->data) << " ";

        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);
    }
}
