#ifndef USERS_HPP
#define USERS_HPP

#include <iostream>
using namespace std;

// Deklarasi sementara
struct PostNode;

typedef struct tUser* addrUser;

typedef struct tUser {
    string username;
    string password;

    string interestedIn[3];
    string bio;
    int likeTotal;

    // Pointer BST
    addrUser left;
    addrUser right;

    // Pointer MLL (1-N)
    struct PostNode* firstPost;
    
} User;


addrUser createUserNode(string username, string password);
addrUser searchUser(addrUser root, string username);
addrUser insertUser(addrUser root, addrUser newUser);
addrUser deleteUser(addrUser root, string username);
addrUser findMinUser(addrUser root);
addrUser findMaxUser(addrUser root);
int countUsers(addrUser root);
void inorderUsers(addrUser root);


#endif