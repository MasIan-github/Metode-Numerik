#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return exp(x);
}

// Metode Newton-Cotes dengan kaidah Simpson 3/8
double simpsonTigaDelapan(double a, double b, int n) {
    double h = (b - a) / n; // Lebar subinterval
    double integral = func(a) + func(b); // Inisialisasi nilai integral
    double sigma1 = 0;
    double sigma2 = 0;

    // Hitung nilai sigma1 dan sigma2
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sigma2 += func(x);
        } else {
            sigma1 += func(x);
        }
    }

    // Hitung nilai integral numerik menggunakan kaidah Simpson 3/8
    integral += 2 * sigma2 + 3 * sigma1;
    integral *= 3 * h / 8;

    return integral;
}

int main() {
    double lowerLimit = 1.8; // Batas bawah integrasi
    double upperLimit = 3.4; // Batas atas integrasi
    int n = 10000; // Jumlah pias, semakin besar semakin akurat

    double integralResult;

    // Panggil fungsi simpsonTigaDelapan untuk menghitung integral
    integralResult = simpsonTigaDelapan(lowerLimit, upperLimit, n);

    cout << "Hasil integral: " << integralResult << endl;

    return 0;
}
