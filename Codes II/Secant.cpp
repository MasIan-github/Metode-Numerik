#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang diberikan
double f(double x) {
    return exp(x) - 5 * pow(x, 2);
}

// Metode secant
void secant(double tebakan_awal1, double tebakan_awal2, double galat) {
    double x0 = tebakan_awal1;
    double x1 = tebakan_awal2;
    int iterasi = 0;

    cout << "Iterasi\t\tX0\t\tX1\t\tX2\t\tf(X2)" << endl;

    while (true) {
        double f_x0 = f(x0); // masukkan nilai tebakan x0 dan x1 ke dalam fungsi
        double f_x1 = f(x1);

        double x2 = x1 - (f_x1 * (x1 - x0) / (f_x1 - f_x0));

        cout << iterasi << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << f(x2) << endl;

        // Jika nilai f(X2) sudah cukup mendekati 0 atau toleransi sudah terpenuhi
        if (fabs(f(x2)) < galat)
            break;

        x0 = x1;
        x1 = x2;
        iterasi++;
    }

    cout << "Akar persamaan adalah: " << x1 << endl;
}

int main() {
    double tebakan_awal1 = 0.5; // Tebakan awal 1
    double tebakan_awal2 = 1.0; // Tebakan awal 2
    double galat = 0.00001; // Toleransi galat

    secant(tebakan_awal1, tebakan_awal2, galat);

    return 0;
}
