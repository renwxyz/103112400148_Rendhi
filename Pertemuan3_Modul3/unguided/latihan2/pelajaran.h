#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct Pelajaran{
    string namaMapel;
    string KodeMapel;
};

Pelajaran create_pelajaran(string namaMapel, string KodeMapel);
void tampil_pelajaran(Pelajaran pel);

#endif