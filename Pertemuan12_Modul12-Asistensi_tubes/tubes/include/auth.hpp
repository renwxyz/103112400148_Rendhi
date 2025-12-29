#ifndef AUTH_HPP
#define AUTH_HPP

#include "users.hpp"
using namespace std;

// Untuk register user baru
void registerUser(addrUser &root);

// Untuk login dan mengembalikan node user
addrUser loginUser(addrUser root);

#endif
