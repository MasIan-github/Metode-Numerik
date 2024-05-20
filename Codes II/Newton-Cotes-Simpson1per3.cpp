#include <iostream>
#include <cmath>

using namespace std;

// fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return exp(x);
}

// prosedur metode Newton-Cotes dengan kaidah Simpson 1/3
void simpsonSepertiga(double a, double b, int n, double& I) {
    double h = (b - a) / n; // jarak antar titik
    double x = a; // awal selang 
    I = func(a) + func(b); // inisialisasi nilai integral
    double sigma = 0;

    // Hitung nilai sigma
    for (int r = 1; r < n; ++r) {
        x += h;
        if (r % 2 == 1) { // r = 1, 3, 5, ..., n-1
            sigma += 4 * func(x);
        } else { // r = 2, 4, 6, ..., n-2
            sigma += 2 * func(x);
        }
    }

    // Hitung nilai integral numerik
    I = (I + sigma) * h / 3;
}

int main() {
    double lowerLimit = 1.8; // Batas bawah 
    double upperLimit = 3.4; // Batas atas 
    int n = 10000; // Jumlah pias, harus genap

    double integralResult;

    // Panggil prosedur simpsonSepertiga untuk menghitung integral
    simpsonSepertiga(lowerLimit, upperLimit, n, integralResult);

    cout << "Hasil integral: " << integralResult << endl;

    return 0;
}
