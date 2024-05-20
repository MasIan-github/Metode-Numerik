#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang diberikan
double f(double x) {
    return exp(x) - 5 * pow(x, 2);
}

// Turunan pertama fungsi f(x)
double fturunan1(double x) {
    return exp(x) - 10 * x;
}

// Metode Newton-Raphson
void newtonRaphson(double tebakan_awal, double galat) {
    double x = tebakan_awal;
    int iterasi = 1;

    cout << "Iterasi\t\tX \t\tf(X)" << endl;

    while (true) {
        double fx = f(x);
        double f_turunanx = fturunan1(x);

        cout << iterasi << "\t\t " << x << "\t\t " << fx << endl;

        // Jika nilai f(x) sudah cukup mendekati 0 atau toleransi sudah terpenuhi
        if (fabs(fx) < galat)
            break;

        // Update nilai x menggunakan rumus iterasi Newton-Raphson
        x = x - (fx / f_turunanx);

        iterasi++;
    }

    cout << "Akar persamaan adalah: " << x << endl;
}

int main() {
    double tebakan_awal = 1.0; // Tebakan awal
    double galat = 0.00001; // Toleransi galat

    newtonRaphson(tebakan_awal, galat);

    return 0;
}
