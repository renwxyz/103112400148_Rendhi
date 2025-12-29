#include "users.hpp"

addrUser createUserNode(string username, string password) {
    addrUser P = new User;
    P->username = username;
    P->password = password;

    // Inisialisasi atribut lain
    for (int i = 0; i < 3; i++) {
        P->interestedIn[i] = "";
    }
    P->bio = "";
    P->likeTotal = 0;

    P->left = nullptr;
    P->right = nullptr;
    P->firstPost = nullptr;

    return P;
}

addrUser searchUser(addrUser root, string username) {
    if (root == nullptr) {
        return nullptr;
    }
    if (username == root->username) {
        return root;
    } else if (username < root->username) {
        return searchUser(root->left, username);
    } else {
        return searchUser(root->right, username);
    }
}

addrUser insertUser(addrUser root, addrUser newUser) {
    if (root == nullptr) {
        return newUser;
    }
    if (newUser->username < root->username) {
        root->left = insertUser(root->left, newUser);
    } else if (newUser->username > root->username) {
        root->right = insertUser(root->right, newUser);
    }
    return root;
}

addrUser findMinUser(addrUser root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

addrUser findMaxUser(addrUser root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

addrUser deleteUser(addrUser root, string username) {
    if (root == nullptr) {
        return nullptr;
    }

    if (username < root->username) {
        root->left = deleteUser(root->left, username);

    } else if (username > root->username) {
        root->right = deleteUser(root->right, username);

    } else {
        // Node ditemukan
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;

        } else if (root->left == nullptr) {
            addrUser temp = root->right;
            delete root;
            return temp;

        } else if (root->right == nullptr) {
            addrUser temp = root->left;
            delete root;
            return temp;

        } else {
            // Dua anak: hanya copy username (key)
            addrUser succ = findMinUser(root->right);
            root->username = succ->username;

            root->right = deleteUser(root->right, succ->username);
        }
    }
    return root;
}


int countUsers(addrUser root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countUsers(root->left) + countUsers(root->right);
}

void inorderUsers(addrUser root) {
    if (root != nullptr) {
        inorderUsers(root->left);
        cout << root->username << endl;
        inorderUsers(root->right);
    }
}
