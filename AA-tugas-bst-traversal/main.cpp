#include "bst.hpp"

int main() {
    string task = "5 - create tree";
    
    Node* root = createNode('F');

    // level 1
    root->left  = createNode('A');
    root->right = createNode('D');

    // level 2
    root->left->left  = createNode('E');
    root->left->right = createNode('K');

    root->right->left  = createNode('H');
    root->right->right = createNode('G');

    // level 3
    root->left->right->left = createNode('C');
    root->right->right->left = createNode('B');

    /*
    Exercise 4
    Node* root = createNode('A');
    root->left  = createNode('B');
    root->right = createNode('C');
    root->left->left  = createNode('D');
    root->left->right = createNode('E');
    root->right->left  = createNode('G');
    root->right->right = createNode('H');
    root->left->left->left = createNode('I');
    root->left->right->left  = createNode('J');
    root->left->right->right = createNode('K');
    root->right->left->left  = createNode('L');
    root->right->left->right = createNode('M');
    root->right->left->right->left  = createNode('N');
    root->right->left->right->right = createNode('O');
    */

    /*
    Exercise 3
    Node* root = createNode('/');
    root->left  = createNode('+');
    root->right = createNode('+');
    root->left->left  = createNode('*');
    root->left->right = createNode('D');
    root->right->left  = createNode('E');
    root->right->right = createNode('*');
    root->left->left->left  = createNode('+');
    root->left->left->right = createNode('C');
    root->right->right->left  = createNode('F');
    root->right->right->right = createNode('H');
    root->left->left->left->left  = createNode('A');
    root->left->left->left->right = createNode('B');
    */
 
    /*
    Exercise 2
    Node* root = createNode('/');
    root->left  = createNode('*');
    root->right = createNode('H');
    root->left->left  = createNode('-');
    root->left->right = createNode('G');
    root->left->left->left  = createNode('-');
    root->left->left->right = createNode('F');
    root->left->left->left->left  = createNode('-');
    root->left->left->left->right = createNode('E');
    root->left->left->left->left->left  = createNode('+');
    root->left->left->left->left->right = createNode('N');
    root->left->left->left->left->left->left  = createNode('+');
    root->left->left->left->left->left->right = createNode('M');
    root->left->left->left->left->left->left->left  = createNode('K');
    root->left->left->left->left->left->left->right = createNode('L');
    */

    /*
    Exercise - 1
    Node* root = createNode('/');
    root->left = createNode('+');
    root->right = createNode('g');
    root->left->left = createNode('*');
    root->left->right = createNode('^');
    root->left->left->left = createNode('+');
    root->left->left->right = createNode('/');
    root->left->left->left->left = createNode('a');
    root->left->left->left->right = createNode('b');
    root->left->left->right->left = createNode('c');
    root->left->left->right->right = createNode('d');
    root->left->right->left = createNode('e');
    root->left->right->right = createNode('f');
    */


    cout << "Exercise - write the traversal - " << task << endl;
    cout << "Preorder   : ";
    preorder(root);
    cout << endl;

    cout << "Inorder    : ";
    inorder(root);
    cout << endl;

    cout << "Postorder  : ";
    postorder(root);
    cout << endl;

    cout << "LevelOrder : ";
    levelOrder(root);
    cout << endl;

    return 0;
}
