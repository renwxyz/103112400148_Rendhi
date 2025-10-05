# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Rendhi - 103112400148</p>

### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Array Multidimensi
Array merupakan tipe data terstruktur yang memungkinkan penyimpanan sejumlah elemen dengan tipe data yang sama di bawah satu nama variabel. Salah satu bentuk khusus dari array adalah array dua dimensi, yang biasa disebut matriks. Matriks dapat dipandang sebagai tabel yang terdiri dari baris dan kolom. Jika array satu dimensi hanya menggunakan satu indeks ([]), maka matriks menggunakan dua indeks ([][]) untuk menentukan posisi elemen, yaitu indeks baris dan indeks kolom.

#### C. Pointer & Reference
Pointer adalah variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain. Dengan pointer, kita bisa mengakses dan mengubah nilai variabel melalui alamat yang disimpannya, biasanya ditulis menggunakan simbol * untuk dereference dan & untuk mengambil alamat. Sementara itu, reference adalah sebuah alias dari variabel lain, artinya reference tidak menyimpan alamat melainkan langsung menjadi nama lain dari variabel tersebut. Reference bersifat tetap sejak pertama kali dideklarasikan, sehingga tidak bisa diubah untuk merujuk ke variabel lain. Perbedaan utama antara pointer dan reference terletak pada fleksibilitas dan cara penggunaannya: pointer dapat dipindahkan untuk menunjuk variabel yang berbeda, sedangkan reference selalu terikat pada satu variabel yang sama, dan penggunaannya lebih sederhana karena tidak memerlukan dereference.

#### B. Fungsi & Prosedur
Fungsi dan prosedur adalah dua konsep penting dalam pemrograman yang digunakan untuk membagi program menjadi bagian-bagian kecil agar lebih terstruktur. Fungsi adalah blok kode yang menerima input (parameter), melakukan proses, dan biasanya mengembalikan sebuah nilai dengan menggunakan kata kunci return. Fungsi cocok digunakan saat kita ingin menghitung atau menghasilkan sesuatu dari data yang diberikan. Sedangkan prosedur (dalam C++ umumnya berupa fungsi dengan tipe void) adalah blok kode yang dapat menerima parameter, melakukan serangkaian instruksi, tetapi tidak mengembalikan nilai. Prosedur lebih tepat digunakan untuk tugas yang hanya menjalankan aksi, seperti menampilkan output atau memodifikasi variabel. Dengan menggunakan fungsi dan prosedur, program menjadi lebih modular, mudah dibaca, serta memudahkan proses debugging maupun pengembangan lebih lanjut.


## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program di atas mendeklarasikan sebuah array bernama arr dengan ukuran 5, kemudian meminta pengguna untuk memasukkan 5 data yang akan disimpan ke dalam array menggunakan perulangan for. Setelah seluruh data dimasukkan, program menampilkan kembali isi array beserta indeksnya satu per satu menggunakan perulangan while.

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;


void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1,2},
        {3,4}
    };

    int arrB[2][2] = {
        {2,3},
        {4,5}
    };

    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program di atas melakukan operasi dasar pada array dua dimensi (matriks) berupa penjumlahan dan perkalian matriks 2x2. Matriks arrA dan arrB diinisialisasi, lalu hasil penjumlahan disimpan di arrC, sedangkan hasil perkalian disimpan di arrD menggunakan tiga perulangan bersarang. Fungsi tampilkanHasil digunakan untuk menampilkan matriks hasil ke layar.

### 3. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "nilai dari a: " << a << endl;
    cout << "alamat memori variabel a: " << &a << endl;
    cout << "nilai yang disimpan di variabel pointer ptr: " << ptr << endl;
    cout << "nilai yang diarahkan oleh ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "Setelah ditukar, nilai a=" << a << " dan nilai b=" << b << endl;

    return 0;
}
```
Program di atas menggunakan pointer untuk mengakses dan memanipulasi variabel secara tidak langsung. Fungsi tukar menerima dua pointer lalu menukar nilai yang ditunjuk. Di main, variabel a dan b diinisialisasi, pointer ptr diarahkan ke a, kemudian ditampilkan nilai dan alamat terkait. Setelah pemanggilan tukar, nilai a dan b berhasil ditukar melalui alamatnya. Kode ini menekankan konsep pointer, dereferensi, dan passing by reference.

### 4. Fungsi & Prosedur

```C++
#include <iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int Max = arr[0];
    for (int i = 0; i < ukuran; i++) {
        if (arr[i] > Max){
            Max = arr[i];
        }
    }
}

void operasiAritmetika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];

    }

    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }

    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}
```
Program di atas memperlihatkan penggunaan fungsi dan prosedur dalam pengolahan array. Fungsi cariMAX digunakan untuk mencari nilai terbesar dari array, sedangkan prosedur operasiAritmatika menghitung total penjumlahan dan perkalian seluruh elemennya lalu menampilkannya. Di dalam main, pengguna diminta memasukkan lima nilai, kemudian hasil terbesar, jumlah, dan perkalian ditampilkan. Kode ini menekankan pentingnya pemisahan logika ke dalam fungsi dan prosedur agar program lebih mudah dibaca dan terstruktur.

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "nilai dari a: " << a << endl;
    cout << "alamat memori variabel a: " << &a << endl;
    cout << "Nilai dari ref (alias a): " << ref << endl;
    cout << "Alamat dari ref (&ref): " << &ref << endl;

    //mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "nilai a: " << a << endl;
    cout << "nilai ref: " << ref << endl;
    
    tukar(a,b);

    cout << "Setelah ditukar, nilai a=" << a << " dan nilai b=" << b << endl;

    return 0;
}
```
Program di atas menunjukkan konsep reference pada variabel. ref mereferensikan a, sehingga perubahan pada ref juga mengubah a. Fungsi tukar menggunakan parameter referensi agar nilai a dan b bisa langsung ditukar. Output memperlihatkan perubahan nilai dan alamat variabel, sekaligus menegaskan pentingnya reference untuk efisiensi memori dan manipulasi data langsung.

## Unguided 

### 1. Operasi Matriks 3x3

```C++
#include <iostream>

using namespace std;

void cetakHasil(int matriks[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriksA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matriksB[3][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    //wadah hasil penjumlahan
    int matriksC[3][3] = {0};

    //wadah hasil pengurangan
    int matriksD[3][3] = {0};
    
    //wadah hasil perkalian
    int matriksE[3][3] = {0};

    //penjumlahan
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriksC[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    cout << "Hasil penjumlahan matriks: " << endl;
    cetakHasil(matriksC);

    //pengurangan
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriksD[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }

    cout << "Hasil pengurangan matriks: " << endl;
    cetakHasil(matriksD);

    //perkalian
    for(int i = 0; i < 3; i++){                         
        for (int j = 0; j < 3; j++){                    
            for (int k = 0; k < 3; k++){                
                matriksE[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    
    cout << "Hasil perkalian matriks: " << endl;
    cetakHasil(matriksE);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan2_Modul2/unguided/output/operasiMatriks3x3-output.png)

Program dari soal ini berfungsi untuk melakukan operasi dasar pada matriks berordo 3x3. Pada program ini saya mendeklarasikan dua buah matriks awal yaitu matriks A dan matriks B, kemudian menyiapkan tiga matriks kosong sebagai wadah untuk menampung hasil penjumlahan, pengurangan, dan perkalian. Untuk operasi penjumlahan, setiap elemen pada matriks A dijumlahkan dengan elemen pada matriks B sesuai indeksnya lalu dimasukkan ke dalam matriks C. Operasi pengurangan dilakukan dengan cara yang sama, yaitu mengurangi elemen pada matriks A dengan elemen pada matriks B dan hasilnya disimpan ke dalam matriks D. Sedangkan untuk operasi perkalian digunakan tiga perulangan bersarang, dimana setiap elemen matriks E diperoleh dari hasil penjumlahan perkalian baris matriks A dengan kolom matriks B. Semua hasil operasi tersebut kemudian ditampilkan melalui fungsi cetakHasil yang mencetak isi matriks ke terminal dalam bentuk baris dan kolom.

### 2. Tukar 3 Variabel (Pointer & Reference)

## Pointer
```C++
#include <iostream>

using namespace std;

void tukar(int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari b: " << b << endl;
    cout << "Nilai dari c: " << c << endl;
    cout << "Alamat memori variabel a: " << &a << endl;
    cout << "Nilai yang disimpan di variabel pointer ptr: " << ptr << endl;
    cout << "Nilai yang diarahkan oleh ptr: " << *ptr << endl;
    
    tukar(&a, &b, &c);
    
    cout << "Setelah ditukar, nilai a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
```
### Output Unguided 2 - Pointer :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan2_Modul2/unguided/output/tukar3Variabel-pointer-output.png)

Program dari soal ini membahas penggunaan pointer sekaligus implementasi fungsi tukar untuk tiga variabel. Pada program ini saya mendeklarasikan tiga variabel integer yaitu a, b, dan c dengan nilai awal 20, 30, dan 40, serta sebuah pointer ptr yang diarahkan ke variabel a. Program menampilkan nilai dari setiap variabel, alamat memori variabel a, nilai yang disimpan pointer ptr, dan nilai yang ditunjuk oleh ptr. Selanjutnya terdapat fungsi tukar(int *x, int *y, int *z) yang berfungsi menukar nilai ketiga variabel dengan bantuan variabel sementara. Setelah fungsi dipanggil, nilai a, b, dan c berubah urutannya, kemudian hasil akhirnya ditampilkan di layar.

## Reference
```C++
#include <iostream>

using namespace std;

void tukar(int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari b: " << b << endl;
    cout << "Nilai dari c: " << c << endl;
    cout << "Alamat memori variabel a: " << &a << endl;
    cout << "Nilai dari ref (alias a): " << ref << endl;
    cout << "Alamat dari ref (&ref): " << &ref << endl;

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << endl;
    cout << "Nilai dari a: " << a << endl;
    cout << "Nilai dari ref: " << ref << endl;
    
    tukar(a, b, c);
    
    cout << "Setelah ditukar, nilai a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
```
### Output Unguided 2 - Reference :
##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan2_Modul2/unguided/output/tukar3Variabel-reference-output.png)

Program dari soal ini digunakan untuk mempraktikkan konsep reference sekaligus fungsi tukar tiga variabel. Pada program ini saya mendeklarasikan tiga variabel integer a, b, dan c dengan nilai awal 20, 30, dan 40, lalu membuat sebuah reference ref yang menjadi alias dari variabel a. Program menampilkan nilai setiap variabel, alamat memori variabel a, serta nilai dan alamat dari ref. Selanjutnya nilai a diubah melalui reference dengan perintah ref = 50, sehingga nilai a ikut berubah. Program juga memiliki fungsi tukar(int &x, int &y, int &z) yang menukar nilai ketiga variabel dengan bantuan variabel sementara. Setelah fungsi dipanggil, nilai a, b, dan c berubah urutannya, kemudian hasil akhir ditampilkan di layar.

### 3. Program Array

```C++
#include <iostream>

using namespace std;

void cetakArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for(int i = 0; i < ukuran; i++) {
        cout << arr[i];
        if(i < ukuran - 1) cout << ", ";
    }
    cout << endl;
}

int nilaiMaksimum(int arr[], int ukuran) {
    int maksimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }
    return maksimum;
}

int nilaiMinimum(int arr[], int ukuran) {
    int minimum = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

void cetakRataRata(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    double rataRata = (double)totalJumlah / ukuran;
    cout << "Nilai rata-rata: " << rataRata << endl;
}

int main() {
    const int size = 10;
    int arrA[size] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;
    
    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cetakArray(arrA, size);
                break;
            case 2:
                cout << "Nilai maksimum: " << nilaiMaksimum(arrA, size) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << nilaiMinimum(arrA, size) << endl;
                break;
            case 4:
                cetakRataRata(arrA, size);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 5);
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan2_Modul2/unguided/output/programArray-output.png)

Program dari soal ini digunakan untuk mengelola sebuah array dengan berbagai operasi dasar. Pada program ini saya mendeklarasikan sebuah array berukuran 10 elemen dengan nilai yang sudah ditentukan. Program dilengkapi menu yang memungkinkan user memilih beberapa opsi, yaitu menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, serta menghitung nilai rata-rata dari seluruh elemen array. Fungsi cetakArray digunakan untuk menampilkan isi array, fungsi nilaiMaksimum mencari elemen terbesar, fungsi nilaiMinimum mencari elemen terkecil, sedangkan fungsi cetakRataRata menghitung rata-rata dengan cara menjumlahkan semua elemen lalu membaginya dengan ukuran array. Proses berulang menggunakan perulangan do-while sampai user memilih keluar dari program.

## Kesimpulan
Pada praktikum ini dipelajari dasar pemrograman C++ meliputi array satu dan dua dimensi, pointer, reference, serta penggunaan fungsi dan prosedur. Array digunakan untuk menyimpan data sejenis dan mendukung operasi aritmetika sederhana, sedangkan pointer dan reference memungkinkan pengelolaan memori secara langsung. Fungsi dan prosedur membantu modularisasi sehingga program lebih terstruktur. Melalui latihan, mahasiswa memperoleh pemahaman praktis yang menjadi landasan untuk mempelajari struktur data dan algoritma tingkat lanjut.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 04 Oktober melalui https://openlibrary.telkomuniversity.ac.id/open/index.php/download/flippingbook/eyJkb3dubG9hZCI6IjEiLCJkd24iOnsia25vd2xlZGdlX2l0ZW1faWQiOiIxNjk1NjQiLCJtZW1iZXJfaWQiOiIxNzMzMjIiLCJuYW1lIjoiMjEuMjEuMjA1OV9lYm9vay5wZGYifSwicmVhZCI6eyJrbm93bGVkZ2VfaXRlbV9pZCI6IjE2OTU2NCIsIm1lbWJlcl9pZCI6IjE3MzMyMiIsIm5hbWUiOiIyMS4yMS4yMDU5X2Vib29rLnBkZiJ9LCJyZWFkb25seSI6IjEiLCJuYW1lIjoiMjEuMjEuMjA1OVwvMjEuMjEuMjA1OV9lYm9vay5wZGYiLCJsaW5rIjoiXC9kYXRhXC9iYXRpa1wvc3ltZm9ueV9wcm9qZWN0c1wvYm9va1wvMjEuMjEuMjA1OVwvMjEuMjEuMjA1OV9lYm9vay5wZGYifQ==

