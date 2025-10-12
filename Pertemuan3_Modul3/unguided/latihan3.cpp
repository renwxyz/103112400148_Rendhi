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