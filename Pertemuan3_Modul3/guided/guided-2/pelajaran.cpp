#include "pelajaran.h"

Pelajaran create_pelajaran(string namaMapel, string kodePel) {
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.KodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(Pelajaran pel){
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.KodeMapel << endl;
}