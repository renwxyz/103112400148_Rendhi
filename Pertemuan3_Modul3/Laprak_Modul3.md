# <h1 align="center">Laporan Praktikum Modul 3 -  ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori
### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Array Multidimensi
Array merupakan tipe data terstruktur yang memungkinkan penyimpanan sejumlah elemen dengan tipe data yang sama di bawah satu nama variabel. Salah satu bentuk khusus dari array adalah array dua dimensi, yang biasa disebut matriks. Matriks dapat dipandang sebagai tabel yang terdiri dari baris dan kolom. Jika array satu dimensi hanya menggunakan satu indeks ([]), maka matriks menggunakan dua indeks ([][]) untuk menentukan posisi elemen, yaitu indeks baris dan indeks kolom.

#### C. Pointer & Reference
Pointer adalah variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain. Dengan pointer, kita bisa mengakses dan mengubah nilai variabel melalui alamat yang disimpannya, biasanya ditulis menggunakan simbol * untuk dereference dan & untuk mengambil alamat. Sementara itu, reference adalah sebuah alias dari variabel lain, artinya reference tidak menyimpan alamat melainkan langsung menjadi nama lain dari variabel tersebut. Reference bersifat tetap sejak pertama kali dideklarasikan, sehingga tidak bisa diubah untuk merujuk ke variabel lain. Perbedaan utama antara pointer dan reference terletak pada fleksibilitas dan cara penggunaannya: pointer dapat dipindahkan untuk menunjuk variabel yang berbeda, sedangkan reference selalu terikat pada satu variabel yang sama, dan penggunaannya lebih sederhana karena tidak memerlukan dereference.

#### B. Fungsi & Prosedur
Fungsi dan prosedur adalah dua konsep penting dalam pemrograman yang digunakan untuk membagi program menjadi bagian-bagian kecil agar lebih terstruktur. Fungsi adalah blok kode yang menerima input (parameter), melakukan proses, dan biasanya mengembalikan sebuah nilai dengan menggunakan kata kunci return. Fungsi cocok digunakan saat kita ingin menghitung atau menghasilkan sesuatu dari data yang diberikan. Sedangkan prosedur (dalam C++ umumnya berupa fungsi dengan tipe void) adalah blok kode yang dapat menerima parameter, melakukan serangkaian instruksi, tetapi tidak mengembalikan nilai. Prosedur lebih tepat digunakan untuk tugas yang hanya menjalankan aksi, seperti menampilkan output atau memodifikasi variabel. Dengan menggunakan fungsi dan prosedur, program menjadi lebih modular, mudah dibaca, serta memudahkan proses debugging maupun pengembangan lebih lanjut.

## Guided 

### 1. 

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; 
    inputMhs(mhs);
    cout << "Rata-rata : " << rata2(mhs); 
    return 0;
}
```
Program di atas berfungsi untuk menghitung dan menampilkan nilai rata-rata seorang mahasiswa berdasarkan dua nilai yang diinputkan. Caranya adalah dengan terlebih dahulu meminta pengguna memasukkan nama dan dua nilai mahasiswa, yang kemudian data tersebut disimpan dalam sebuah variabel struct. Selanjutnya, program memanggil sebuah fungsi khusus untuk menghitung rata-rata dari kedua nilai tersebut dan pada akhirnya menampilkan hasil perhitungan rata-ratanya ke terminal.

### 2. Guided-2

## main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
Program di atas berfungsi untuk membuat dan menampilkan data sebuah mata pelajaran dengan menggunakan fungsi-fungsi yang berada di file terpisah. Caranya adalah dengan menyiapkan data nama dan kode pelajaran di dalam fungsi main, kemudian memanggil fungsi create_pelajaran dari file header "pelajaran.h" untuk membuat sebuah objek pelajaran dari data tersebut. Setelah objek berhasil dibuat, program lalu memanggil fungsi tampil_pelajaran dari file header yang sama untuk menampilkan detail informasi dari objek pelajaran itu ke terminal.

## pelajaran.cpp
```C++
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
```
Program di atas berfungsi sebagai file implementasi yang mendefinisikan kumpulan fungsi untuk mengelola data pelajaran. Caranya adalah dengan menyediakan dua fungsi terpisah: pertama, fungsi create_pelajaran yang bertugas untuk menerima data berupa nama dan kode, lalu membuat dan mengembalikan sebuah objek pelajaran baru dari data tersebut. Kedua, fungsi tampil_pelajaran yang bertugas untuk menerima sebuah objek pelajaran dan kemudian mencetak detail nama serta kode dari pelajaran tersebut ke terminal.

## pelajaran.h
```C++
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
```
Program di atas berfungsi sebagai file header yang bertugas untuk mendefinisikan sebuah struktur data dan mendeklarasikan fungsi-fungsi yang berhubungan dengannya. Caranya adalah dengan menggunakan include guard (#ifndef, #define, #endif) untuk mencegah terjadinya duplikasi saat file ini dipanggil berkali-kali, lalu di dalamnya mendefinisikan sebuah struct bernama Pelajaran sebagai cetak biru data, dan terakhir menyediakan deklarasi atau prototipe fungsi create_pelajaran dan tampil_pelajaran agar dapat diimplementasikan dan digunakan oleh file kode sumber lainnya.


## Unguided 

### 1. Latihan-1

```C++
#include <iostream>
#include <string>

using namespace std;

// Tipe data Mahasiswa menggunakan tipe data string
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data_mahasiswa[10];
    int jumlah_mahasiswa;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah_mahasiswa;

    // Loop untuk input data
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        cout << "\nData Mahasiswa ke-" << i + 1 << ":" << endl;
        
        cout << "Nama: ";
        cin >> data_mahasiswa[i].nama;
        
        cout << "NIM: ";
        cin >> data_mahasiswa[i].nim;
        
        cout << "Nilai UTS: ";
        cin >> data_mahasiswa[i].uts;
        
        cout << "Nilai UAS: ";
        cin >> data_mahasiswa[i].uas;
        
        cout << "Nilai Tugas: ";
        cin >> data_mahasiswa[i].tugas;
        
        data_mahasiswa[i].nilai_akhir = hitungNilaiAkhir(
            data_mahasiswa[i].uts,
            data_mahasiswa[i].uas,
            data_mahasiswa[i].tugas
        );
    }

    // Menampilkan hasil input
    cout << "\n--- Hasil Data Mahasiswa ---" << endl;
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: " << data_mahasiswa[i].nama << endl;
        cout << "NIM: " << data_mahasiswa[i].nim << endl;
        cout << "Nilai Akhir: " << data_mahasiswa[i].nilai_akhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan3_Modul3/unguided/output/latihan1-output.png)

Program di atas berfungsi untuk mengelola data nilai mahasiswa, mulai dari proses input, perhitungan nilai akhir, hingga penampilan hasil. Caranya adalah dengan terlebih dahulu meminta pengguna memasukkan jumlah mahasiswa yang akan diolah, kemudian program melakukan perulangan untuk menginput data nama, NIM, nilai UTS, UAS, dan tugas bagi setiap mahasiswa. Di dalam setiap perulangan input, program akan langsung memanggil fungsi hitungNilaiAkhir untuk mengkalkulasi nilai akhir berdasarkan bobot nilai yang telah ditentukan (30% UTS, 40% UAS, dan 30% tugas), lalu menyimpannya. Setelah semua data berhasil dimasukkan, program akan melakukan perulangan sekali lagi untuk menampilkan ringkasan data yang berisi nama, NIM, dan hasil nilai akhir setiap mahasiswa ke terminal.

### 2. Latihan-2

## main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
Program di atas berfungsi untuk menghitung dan menampilkan nilai rata-rata seorang mahasiswa berdasarkan dua nilai yang diinputkan. Caranya adalah dengan terlebih dahulu meminta pengguna memasukkan nama dan dua nilai mahasiswa, yang kemudian data tersebut disimpan dalam sebuah variabel struct. Selanjutnya, program memanggil sebuah fungsi khusus untuk menghitung rata-rata dari kedua nilai tersebut dan pada akhirnya menampilkan hasil perhitungan rata-ratanya ke terminal.

## pelajaran.cpp
```C++
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
```
Program di atas berfungsi sebagai file implementasi yang mendefinisikan kumpulan fungsi untuk mengelola data pelajaran. Caranya adalah dengan menyediakan dua fungsi terpisah: pertama, fungsi create_pelajaran yang bertugas untuk menerima data berupa nama dan kode, lalu membuat dan mengembalikan sebuah objek pelajaran baru dari data tersebut. Kedua, fungsi tampil_pelajaran yang bertugas untuk menerima sebuah objek pelajaran dan kemudian mencetak detail nama serta kode dari pelajaran tersebut ke terminal.

## pelajaran.h
```C++
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
```

Program di atas berfungsi sebagai file header yang bertugas untuk mendefinisikan sebuah struktur data dan mendeklarasikan fungsi-fungsi yang berhubungan dengannya. Caranya adalah dengan menggunakan include guard (#ifndef, #define, #endif) untuk mencegah terjadinya duplikasi saat file ini dipanggil berkali-kali, lalu di dalamnya mendefinisikan sebuah struct bernama Pelajaran sebagai cetak biru data, dan terakhir menyediakan deklarasi atau prototipe fungsi create_pelajaran dan tampil_pelajaran agar dapat diimplementasikan dan digunakan oleh file kode sumber lainnya.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan3_Modul3/unguided/output/latihan2-output.png)


### 3. Latihan-3

```C++
#include <iostream>

using namespace std;

// Prosedur menampilkan isi sebuah array integer 2D
void tampilArray(int arr[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Prosedur untuk menukarkan isi dari 2 array 2D pada posisi tertentu
void tukarElemenArray(int arrA[][3], int arrB[][3], int baris, int kolom) {
    // Pengecekan posisi valid
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arrA[baris][kolom];
        arrA[baris][kolom] = arrB[baris][kolom];
        arrB[baris][kolom] = temp;
        cout << "\n>> Penukaran elemen pada posisi [" << baris << "][" << kolom << "] berhasil." << endl;
    } else {
        cout << "\n>> Posisi baris/kolom tidak valid!" << endl;
    }
}

// Prosedur menukarkan isi dari variabel yang ditunjuk oleh 2 pointer
void tukarViaPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1; 
    *ptr1 = *ptr2;    
    *ptr2 = temp;    
}

int main() {
    //Deklarasi 2 buah array 2D integer 3x3
    int matriksA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriksB[3][3] = {{99, 88, 77}, {66, 55, 44}, {33, 22, 11}};

    //Deklarasi 2 buah pointer integer
    int nilaiA = 100;
    int nilaiB = 200;
    int* pointerA = &nilaiA;
    int* pointerB = &nilaiB;

    cout << "## KONDISI AWAL MATRIKS ##" << endl;
    cout << "Matriks A:" << endl;
    tampilArray(matriksA);
    cout << "\nMatriks B:" << endl;
    tampilArray(matriksB);
    
    int baris, kolom;
    cout << "\nMasukkan posisi elemen yang ingin ditukar:" << endl;
    cout << "Baris (0-2): ";
    cin >> baris;
    cout << "Kolom (0-2): ";
    cin >> kolom;

    tukarElemenArray(matriksA, matriksB, baris, kolom);

    cout << "\n## KONDISI AKHIR MATRIKS ##" << endl;
    cout << "Matriks A:" << endl;
    tampilArray(matriksA);
    cout << "\nMatriks B:" << endl;
    tampilArray(matriksB);

    cout << "\n----------------------------------------\n" << endl;

    cout << "## KONDISI AWAL POINTER ##" << endl;
    cout << "Nilai A (ditunjuk pointerA) = " << *pointerA << endl;
    cout << "Nilai B (ditunjuk pointerB) = " << *pointerB << endl;

    tukarViaPointer(pointerA, pointerB);

    cout << "\n>> Penukaran nilai via pointer berhasil." << endl;
    
    cout << "\n## KONDISI AKHIR POINTER ##" << endl;
    cout << "Nilai A (ditunjuk pointerA) = " << *pointerA << endl;
    cout << "Nilai B (ditunjuk pointerB) = " << *pointerB << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan3_Modul3/unguided/output/latihan3-output.png)

Program di atas berfungsi untuk mendemonstrasikan dua metode penukaran data yang berbeda: menukar satu elemen spesifik antara dua matriks (array 2D) dan menukar nilai antara dua variabel melalui pointer. Caranya adalah dengan melakukan dua segmen proses yang terpisah. Pada segmen pertama, program meminta pengguna memasukkan koordinat baris dan kolom, lalu memanggil fungsi tukarElemenArray untuk menukar isi elemen matriks pada koordinat tersebut. Pada segmen kedua, program memanggil fungsi tukarViaPointer yang menerima alamat memori dari dua variabel, lalu menukar nilai yang tersimpan di alamat-alamat tersebut secara langsung. Program menampilkan kondisi awal dan akhir dari data pada kedua segmen untuk menunjukkan hasil dari setiap proses penukaran.

## Kesimpulan
Praktikum Modul 3 ini menunjukkan penerapan konsep Abstract Data Type (ADT) dalam bahasa C++ untuk mengelola data secara terstruktur dan modular. Melalui penggunaan struct, data-data kompleks seperti mahasiswa dan pelajaran berhasil dibungkus menjadi satu kesatuan yang logis. Konsep modularitas diperkuat dengan implementasi fungsi dan prosedur, termasuk pemisahan kode ke dalam file header (.h) dan implementasi (.cpp), yang membuat program lebih terorganisir dan mudah dikelola. Selain itu, praktikum ini juga berhasil mendemonstrasikan manipulasi data secara mendalam melalui penggunaan array multidimensi untuk data tabular dan pointer untuk operasi penukaran nilai langsung di memori, yang membuktikan pemahaman tentang manajemen data pada level yang lebih rendah.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 04 Oktober melalui https://openlibrary.telkomuniversity.ac.id/open/index.php/download/flippingbook/eyJkb3dubG9hZCI6IjEiLCJkd24iOnsia25vd2xlZGdlX2l0ZW1faWQiOiIxNjk1NjQiLCJtZW1iZXJfaWQiOiIxNzMzMjIiLCJuYW1lIjoiMjEuMjEuMjA1OV9lYm9vay5wZGYifSwicmVhZCI6eyJrbm93bGVkZ2VfaXRlbV9pZCI6IjE2OTU2NCIsIm1lbWJlcl9pZCI6IjE3MzMyMiIsIm5hbWUiOiIyMS4yMS4yMDU5X2Vib29rLnBkZiJ9LCJyZWFkb25seSI6IjEiLCJuYW1lIjoiMjEuMjEuMjA1OVwvMjEuMjEuMjA1OV9lYm9vay5wZGYiLCJsaW5rIjoiXC9kYXRhXC9iYXRpa1wvc3ltZm9ueV9wcm9qZWN0c1wvYm9va1wvMjEuMjEuMjA1OVwvMjEuMjEuMjA1OV9lYm9vay5wZGYifQ==
