#include <iostream>
#include <cmath>
using namespace std;

void gaussSeidelMethod(double A[3][3], double B[3], double P[3], int maxIterations, double tolerance) {
    double P_new[3]; // Vektor solusi baru
    int iterations = 0;
    double error = 0;

    do {
        for (int i = 0; i < 3; ++i) {
            double sum1 = 0;
            double sum2 = 0;
            for (int j = 0; j < i; ++j) {
                sum1 += A[i][j] * P_new[j];
            }
            for (int j = i + 1; j < 3; ++j) {
                sum2 += A[i][j] * P[j];
            }
            P_new[i] = (B[i] - sum1 - sum2) / A[i][i];
        }

        // kalkulasi galat
        error = 0;
        for (int i = 0; i < 3; ++i) {
            error += abs(P_new[i] - P[i]);
        }

        for (int i = 0; i < 3; ++i) {
            P[i] = P_new[i];
        }

        iterations++;

    } while (error > tolerance && iterations < maxIterations);

    cout << "jumlah iteraso: " << iterations << " iterations. " <<endl;
    cout << "solusi :";
    for (int i = 0; i < 3; ++i) {
        cout << "x" << i + 1 << " = " << P[i] << ", ";
    }
    cout << endl;
}

int main() {
    // koefisien permasalahan
    double A[3][3] = {{3, -0.1, -0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}};

    // vektor kanan
    double B[3] = {7.85, -19.3, 71.4};

    // tebakan awal P0 = {x0, y0, z0}
    double P[3] = {1, 2, 2}; 

    int maxIterations = 1000; // batas iterasi
    double tolerance = 1e-6; // toleransi konvergensi

    gaussSeidelMethod(A, B, P, maxIterations, tolerance);


    return 0;

}
