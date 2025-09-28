# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### 1. Fungsi
Fungsi pada C++ digunakan untuk memisahkan kode program ke dalam blok tertentu agar lebih terstruktur, mudah dipahami, dan dapat digunakan kembali. Dengan menggabungkan konsep fungsi dan perulangan, programmer dapat membuat program yang lebih sederhana namun tetap mampu menghasilkan pola atau proses yang kompleks.
#### 2. Perulangan
Dalam pemrograman, perulangan (looping) digunakan untuk mengeksekusi perintah secara berulang berdasarkan kondisi tertentu. C++ menyediakan beberapa jenis perulangan seperti for, while, dan do-while. Struktur for sering dipakai ketika jumlah perulangan sudah diketahui, karena terdiri dari inisialisasi, kondisi, dan perubahan nilai variabel kontrol yang jelas.
#### 3. Array
Array dalam C++ adalah struktur data yang digunakan untuk menyimpan sekumpulan elemen dengan tipe data yang sama di bawah satu nama variabel. Setiap elemen array diakses menggunakan indeks, dengan indeks dimulai dari 0 hingga ukuran array dikurangi satu. Array sangat berguna dalam pemrograman karena memudahkan penyimpanan dan pengolahan data yang jumlahnya banyak dan sejenis. Dalam praktik, array sering dipadukan dengan perulangan untuk melakukan proses seperti pencetakan, pencarian, maupun pengurutan data secara lebih efisien.

## Guided 

### 1. Hello World

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    return 0;
}
```
Program di atas adalah bagaimana sebuah teks diprint menggunakan bahasa c++.

### 2. Dasar Input/Output & Perulangan

```C++
#include <iostream>

using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1: ";
    cin >> angka1;
    cout << "Masukkan angka2: ";
    cin >> angka2;

    for (int i = 0; i < angka1; i++) {
        cout << i << " - ";
    }

    cout << endl;

    for (int i = 20; i > angka2; i--) {
        cout << i << " - ";
    }

    cout << endl;
}
```
Program ini menerima dan menyimpan input dari user ke variabel angka1 dan angka2, setelah itu nanti akan di print sebanyak inputan angka secara increment & decrement dengan format keluaran yang sudah ditentukan.

### 3. Dasar Tipe Bentukan Struct

```C++
#include <iostream>

using namespace std;

int main() {
    const int jumlah = 5;

    struct raport {
        char nama[5];
        int nilai;
    };

    raport siswa[jumlah] = {};

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << "\n--- Data Siswa ---" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama siswa: " << siswa[i].nama << ", Nilai: " << siswa[i].nilai << endl;
    }

    return 0;
}
```
Program di atas menggabungkan struct dengan array untuk mengorganisasi data siswa. Program akan meminta masukan data, seperti nama dan nilai, untuk lima siswa (sesuai konstanta jumlah). Setiap set data ini kemudian akan disimpan dalam array siswa. Setelah semua data terkumpul, program akan menggunakan perulangan kedua untuk menelusuri dan menampilkan kembali seluruh data siswa yang telah tersimpan dalam array tersebut.


### 1. Soal Unguided 1 (operasiFloat)

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama (float): ";
    cin >> a;

    cout << "Masukkan bilangan kedua (float): ";
    cin >> b;

    cout << "\nHasil Perhitungan:" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian: " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian: " << a / b << endl;
    } else {
        cout << "Pembagian: Tidak dapat dibagi (Pembagi nol)" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan1_Modul1/unguided/output/operasiFloat-output.png)

Program dari soal Unguided 1 cukup sederhana, dimana saya diharuskan untuk mendeklarasikan 2 variabel bertipe data float untuk menampung inputan dari user kemudian
akan dioperasikan dengan operasi dasar aritmatika sederhana. Di sini saya menambahkan beberapa rules dasar juga seperti validasi penyebut khusus untuk operasi pembagian,
karena bilangan apapun tidak dapat dibagi dengan 0.

### 2. Soal Unguided 2 (sebutAngka)

```C++
#include <iostream>
#include <string>
using namespace std;

string sebutAngka(int n) {
    if (n == 0) return "nol";
    if (n == 100) return "seratus";

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (n < 10) {
        return satuan[n];
    } else if (n < 20) {
        if (n == 10) return "sepuluh";
        if (n == 11) return "sebelas";
        return satuan[n % 10] + " belas";
    } else {
        string hasil = satuan[n / 10] + " puluh";
        if (n % 10 != 0) {
            hasil += " " + satuan[n % 10];
        }
        return hasil;
    }
}

int main() {
    int angka;

    cout << "Masukkan angka bulat positif (0 s.d 100): ";
    cin >> angka;
    
    cout << angka << " : " << sebutAngka(angka) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan1_Modul1/unguided/output/sebutAngka-output.png)

Program dari soal Unguided 2 sudah mulai menantang. Pada program ini saya mendeklarasikan sebuah fungsi bernama sebutAngka(int n) yang bertugas melakukan pengecekan kondisi angka dengan beberapa aturan dasar. Jika angka yang dimasukkan adalah 0 maka akan dikembalikan kata “nol”, sedangkan jika 100 maka hasilnya “seratus”. Untuk angka di bawah 10 program langsung mengambil kata yang sesuai dari array satuan, sementara untuk angka 10–19 digunakan aturan khusus, misalnya 10 menjadi “sepuluh”, 11 menjadi “sebelas”, dan 12–19 menjadi “[satuan] belas”. Untuk angka 20 hingga 99, program membentuk kata dengan mengambil nilai puluhan seperti “dua puluh” atau “tiga puluh”, kemudian menambahkan kata satuan jika angka tidak habis dibagi sepuluh.

### 3. Soal Unguided 3 (mirror/segitiga terbilak)

```C++
#include <iostream>

using namespace std;

void Mirror(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
        for (int k = i; k >= 1; --k) {
            cout << k << " ";
        }
        cout << "*";
        for (int l = 1; l <= i; ++l) {
            cout << " " << l;
        }
        cout << endl;
    }
    
    if (n >= 1) {
        for (int i = 0; i < n; ++i) {
            cout << "  ";
        }
        cout << "* " << endl;
    }
}

int main() {
    int input;
    cout << "input: ";
    cin >> input;
    
    cout << endl << "output: "<< endl << endl;
    
    Mirror(input);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan1_Modul1/unguided/output/mirror-output.png)

Untuk soal unguided yang ke-3 ini cukup mudah karena sebelumnya saya sudah pernah praktik hal demikian akan tetapi berbeda sedikit tapi secara algoritma tidak jauh berbeda, ada beberapa pemahamn baru yang saya dapatkan setelah mecoba menyelesaikan soal ini, yaitu perbedaan antara pre-increment/decrement & post-increment/decrement. Kurang lebih cara kerjanya adalah sebagai berikut, for loop pertama mengatur jumlah baris yang dicetak dari atas ke bawah, for loop ke-2 berfungsi mencetak spasi agar pola bergeser ke kanan, for loop ke-3 mencetak deret angka menurun dari nilai tertentu hingga 1, dan for loop ke-4 mencetak deret angka menaik dari 1 hingga kembali ke nilai semula setelah tanda bintang. Selain itu, terdapat for loop tambahan di dalam blok if yang bertugas mencetak spasi terakhir pada baris paling bawah, kemudian menampilkan satu tanda bintang sebagai penutup pola sehingga bentuk cerminnya terlihat lengkap.

## Kesimpulan
Praktikum Modul 1 ini memberikan pemahaman dasar yang kuat tentang Bahasa Pemrograman C++. Saya belajar bahwa program C++ selalu memerlukan header seperti <iostream> dan bahwa saya bisa membuat kode lebih terstruktur menggunakan fungsi dan perulangan (for, while).

Melalui praktik, saya mengaplikasikan struct dan array secara bersamaan untuk mengelola data terstruktur seperti data siswa (Guided 3). Pada bagian Unguided, saya berhasil menerapkan operasi aritmatika pada tipe data float, membuat fungsi untuk konversi angka menjadi terbilang (0-100) dengan kondisi logis, serta menggunakan perulangan bersarang untuk membuat pola visual mirror yang cukup kompleks. Intinya, modul ini memperkuat penguasaan saya terhadap sintaks dasar C++, kontrol alir, dan problem-solving algoritmik.

## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 27 September 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Putra, C. K. (2022). Pengembangan Media Pembelajaran Mobile Pemrograman C++. Universitas Muhammadiyah Surakarta. Diakses pada 28 September 2025 melalui https://eprints.ums.ac.id/115405/10/Naskah%20Publikasi_Canygia%20Kalindra%20Putra.pdf.
<br>[3] Deitel, H. M., & Deitel, P. J. (2017). C++ How to Program (10th ed.). Pearson.



