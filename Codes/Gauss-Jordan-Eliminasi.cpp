#include <iostream>
using namespace std;

// fungsi absolut untuk x
float absolute(float x) {
    return (x >= 0) ? x : -x;
} 

// fungsi untuk mencari akar dari x
float sqrt(float x) {
    float guess = x / 2;
    for (int i = 0; i < 10; ++i) {
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

// fungsi perhitungan SSPL dengan Gauss Jordan
void GaussJordan(float A[3][3], float B[3], int n) {
    float temp;

    for (int i = 0; i < n; i++) {
        // pivot sebagian
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (absolute(A[j][i]) > absolute(A[maxRow][i])) {
                maxRow = j;
            }
        }

        // tukar deret jika maks deret tidak sama dengan 1
        if (maxRow != i) {
            for (int k = i; k < n; k++) {
                temp = A[i][k];
                A[i][k] = A[maxRow][k];
                A[maxRow][k] = temp;
            }
            temp = B[i];
            B[i] = B[maxRow];
            B[maxRow] = temp;
        }

        // eliminasi kedepan
        for (int j = i + 1; j < n; j++) {
            float factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }

    // subtitusi kebelakang
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            B[i] -= A[i][j] * B[j];
        }
        B[i] /= A[i][i];
    }
}

int main() {
    float A[3][3] = {{3, -0.1, -0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}};
    float B[3] = {7.85, -19.3, 71.4};
    float n = 3;

    GaussJordan(A, B, n);

    cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << B[i] << endl;
    }

    return 0;
}
