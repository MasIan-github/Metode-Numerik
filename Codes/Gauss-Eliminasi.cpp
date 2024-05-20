#include <iostream>
using namespace std;

// prosedur perhitungan matriks segitiga atas dari permasalahaan
void Sulih_Mundur(float A[3][3], float b[3], int n, float x[3]) { // Matriks A berdimensi 4x4
    x[n - 1] = b[n - 1] / A[n - 1][n - 1]; // memulai penyulihan mundur pada matriks
    for (int k = n - 2; k >= 0; k--) {
        float sigma = 0;
        for (int j = k + 1; j < n; j++) {
            sigma += A[k][j] * x[j];
        }
        x[k] = (b[k] - sigma) / A[k][k];
    }
}

int main() {
    float A[3][3] = {{3, -0.1, -0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}}; //Koefisien permasalahaan
    float b[3] = {7.85, -19.3, 71.4}; // Hasil dari permasalahaan
    int n = 3;
    float x[3];

    Sulih_Mundur(A, b, n, x);

    cout << "Solution:" << endl; // print solusi x
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
