#include <iostream>
using namespace std;

// fungsi menghitung determinan
float determinant(float A[3][3]) {
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
           A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
           A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

//fungsi mencari invers dari matriks
void inverse(float A[3][3], float invA[3][3]) {
    float det = determinant(A);
    invA[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) / det;
    invA[0][1] = (A[0][2] * A[2][1] - A[0][1] * A[2][2]) / det;
    invA[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) / det;
    invA[1][0] = (A[1][2] * A[2][0] - A[1][0] * A[2][2]) / det;
    invA[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) / det;
    invA[1][2] = (A[0][2] * A[1][0] - A[0][0] * A[1][2]) / det;
    invA[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) / det;
    invA[2][1] = (A[0][1] * A[2][0] - A[0][0] * A[2][1]) / det;
    invA[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) / det;
}

void matriksvektor(float A[3][3], float b[3], float result[3], int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * b[j];
        }
    }
}

int main() {
    float A[3][3] = {{1, -1, 2}, {3, 0, 1}, {1, 0, 2}};
    float b[3] = {5, 10, 5};
    float x[3];

    float invA[3][3];
    inverse(A, invA);

    float bReduced[3], xReduced[3];
    matriksvektor(invA, b, bReduced, 3);
    for (int i = 0; i < 3; ++i) {
        x[i] = bReduced[i];
    }

    cout << "Solution: " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}
