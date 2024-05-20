#include <iostream>
using namespace std;


void decomposeLU(double A[3][3], double L[3][3], double U[3][3]) {
    for (int i = 0; i < 3; ++i) {
        L[i][i] = 1;
    }

    for (int i = 0; i < 3; ++i) {
        for (int k = i; k < 3; ++k) {
            double sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i + 1; k < 3; ++k) {
            double sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += (L[k][j] * U[j][i]);
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
}

void solve(double A[3][3], double B[3], double X[3]) {
    double L[3][3] = {0};
    double U[3][3] = {0};

    decomposeLU(A, L, U);

    double Y[3] = {0};
    for (int i = 0; i < 3; ++i) {
        double sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = (B[i] - sum) / L[i][i];
    }

    for (int i = 3 - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < 3; ++j) {
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }
}

int main() {
    double A[3][3] = {{3, -0.1, -0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}};
    double B[3] = {7.85, -19.3, 71.4};
    double X[3];

    solve(A, B, X);

    cout << "Solution:" << endl;
    cout << "x1 = " << X[0] << endl;
    cout << "x2 = " << X[1] << endl;
    cout << "x3 = " << X[2] << endl;

    return 0;
}
