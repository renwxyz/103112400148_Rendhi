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