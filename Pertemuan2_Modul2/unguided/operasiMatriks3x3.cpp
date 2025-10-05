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