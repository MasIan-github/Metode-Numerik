#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return exp(x) - 5 * pow(x, 2);
}

// Prosedur metode trapesium
void trapesium(double a, double b, int n, double& I) {
    double h = (b - a) / n; // Lebar subinterval
    double x = a; // Titik awal integrasi
    I = func(a) + func(b); // Inisialisasi nilai integral

    // Hitung nilai sigma
    double sigma = 0;
    for (int r = 1; r < n; ++r) {
        x += h;
        sigma += 2 * func(x);
        cout << "iterasi : " << r << " x : " << x << " sigma : " << sigma << endl;
    }

    // Hitung nilai integral numerik
    I = (I + sigma) * h / 2;
}

int main() {
    double lowerLimit = 0.0; // Batas bawah 
    double upperLimit = 1.0; // Batas atas 
    int n = 10000; // Jumlah pias

    double integralResult;

    // Panggil prosedur trapesium untuk menghitung integral
    trapesium(lowerLimit, upperLimit, n, integralResult);

    cout << "Hasil integral ((I + sigma) * h / 2): " << integralResult << endl;

    return 0;
}
