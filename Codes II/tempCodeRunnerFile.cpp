#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang diberikan
double f(double x) {
    return pow(x, 2) + 2 * x - 3;
}

// Metode regula falsi
void regulaFalsi(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Tidak ada akar pada interval ini." << endl;
        return;
    }

    int iterasi = 1;
    double c;

    cout << "Iterasi\t\ta\t\tb\t\tc\t\tf(c)" << endl;

    while (fabs(b - a) >= tolerance) {
        // Hitung nilai c menggunakan rumus regula falsi
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << iterasi << "\t\t" << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(c) << endl;

        // Jika f(c) sudah cukup mendekati 0 atau toleransi sudah terpenuhi
        if (fabs(f(c)) < tolerance)
            break;
        // Update nilai a dan b berdasarkan lokasi akar
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iterasi++;
    }

    cout << "Akar persamaan adalah: " << c << endl;
}

int main() {
    double a = -1.0; // Batas bawah interval
    double b = 3.0; // Batas atas interval
    double tolerance = 0.00001; // Toleransi galat

    regulaFalsi(a, b, tolerance);

    return 0;
}
