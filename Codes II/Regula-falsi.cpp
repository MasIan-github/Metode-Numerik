#include <iostream>
#include <cmath>

using namespace std;

// fungsi yang diberikan
double f(double x) {
    return exp(x) - 5 * pow(x, 2);
}

// prosedur regula-falsi
void regulaFalsi(double a, double b, double galat) {
    if (f(a) * f(b) >= 0) {
        cout << "Tidak ada akar pada interval ini." << endl;
        return;
    }

    int iterasi = 1;
    double c;

    cout << "Iterasi\t\t a\t\t b\t\t c\t\t f(c)" << endl;

    while (fabs(b - a) >= galat) {
        // rumus 'c' regula-falsi
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << iterasi << "\t\t " << a << "\t\t " << b << "\t\t " << c << "\t\t " << f(c) << endl;

        // jika f(c) sudah cukup mendekati 0 atau toleransi sudah terpenuhi
        if (fabs(f(c)) < galat)
            break;
        // update nilai a dan b berdasarkan lokasi akar
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iterasi++;
    }

    cout << "Akar persamaan adalah: " << c << endl;
}

int main() {
    double a = 0.0; // batas bawah 
    double b = 3.0; // batas atas 
    double galat = 0.00001; // toleransi galat

    regulaFalsi(a, b, galat);

    return 0;
}
