# <h1 align="center">Laporan Praktikum Modul 6</h1>
<p align="center">Rendhi - 103112400148</p>

## Dasar Teori

#### A. Bahasa Pemrograman C++<br/>
Bahasa pemrograman C++ merupakan bahasa tingkat tinggi yang digunakan secara luas dalam dunia akademik maupun industri. Struktur program C++ selalu diawali dengan header file seperti #include <iostream> yang digunakan untuk operasi input dan output standar. Menurut Indahyati dan Rahmawati (2020), bahasa C++ memberikan landasan penting untuk memahami algoritma dan pemrograman, terutama melalui sintaks dasar yang mudah dipelajari oleh pemula. 

#### B. Struktur Data

### 1. Definisi dan Konsep Dasar Linked List
Linked List adalah koleksi elemen data linear di mana urutan logis elemen tidak ditentukan oleh lokasi fisik dalam memori, melainkan oleh pointer atau tautan yang tertanam dalam setiap elemennya. Struktur data ini sangat penting karena memungkinkan alokasi memori secara dinamis (dynamic memory allocation), yang berarti list dapat tumbuh atau menyusut ukurannya saat program sedang berjalan, sangat berbeda dengan Array statis yang ukurannya sudah ditentukan sejak awal kompilasi. Fleksibilitas ini membuat Linked List sangat efisien untuk operasi penyisipan dan penghapusan data di mana saja dalam list.

### 2. Struktur Node dan Singy Linked List
Unit dasar dari Linked List disebut Node, yang merupakan objek yang terdiri dari dua bagian utama: bagian Data (Infotype), yang menyimpan nilai atau informasi yang sebenarnya, dan bagian Pointer (Address), yang menyimpan alamat memori dari node berikutnya dalam urutan. Dalam Singly Linked List, setiap node hanya memiliki satu pointer yang menunjuk ke node selanjutnya, memungkinkan penelusuran (traversal) hanya dalam satu arah (maju), dan pointer pada node terakhir akan bernilai NULL untuk menandai akhir dari list. Secara keseluruhan, list didefinisikan oleh pointer First (Head) yang menunjuk ke node pertama, dan jika list kosong, First bernilai NULL.

### 3. Implementasi Operasi Kunci
Praktikum ini berfokus pada implementasi Abstract Data Type (ADT) dengan berbagai operasi manipulasi data, yang memanfaatkan perubahan pada pointer Next. Operasi Penyisipan (insertFirst, insertLast, insertAfter) dan Penghapusan (delAfter) melibatkan penyesuaian pointer untuk menjaga integritas urutan list. Lebih lanjut, operasi Update memungkinkan modifikasi nilai data pada node tertentu (updateFirst, updateLast, updateAfter), sementara operasi Pencarian (SearchByData, SearchByAddress, SearchByRange) memerlukan penelusuran list dari node pertama hingga node yang dicari ditemukan. Terakhir, fungsi Aritmatika mengharuskan penelusuran seluruh list untuk melakukan komputasi agregat (penjumlahan, pengurangan, perkalian) terhadap semua elemen data di dalamnya.

## Guided 

### 1. listBuah.h

```C++

```

### 2. listBuah.cpp

```C++

```

### 3. main.cpp

```C++

```

## Unguided

### 1. listAngka.h
```C++

```

### 2. listAngka.cpp

```C++

```

### 3. main.cpp

```C++

```

### Output Unguided :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output.png)

### Output Unguided Soal 1 :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output1.png)

Deskripsi

### Output Unguided Soal 2 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output2.png)

Deskkripsi

### Output Unguided Soal 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/renwxyz/103112400148_Rendhi/blob/main/Pertemuan5_Modul5/unguided/output/output3.png)

Deskripsi

## Kesimpulan


## Referensi
[1] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 04 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[2] Mohanty, S. N., & Tripathy, P. K. (2021). Data Structure and Algorithms Using C++: A Practical Implementation. Scrivener Publishing. Diakses pada 18 Oktober melalui https://openlibrary.telkomuniversity.ac.id/