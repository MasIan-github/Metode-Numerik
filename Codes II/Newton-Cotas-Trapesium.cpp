#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return exp(x);
}

// Metode Newton-Cotes dengan kaidah trapesium
double newtonCotesTrapesium(double a, double b, int n) {
    double h = (b - a) / n; // Lebar subinterval
    double integral = 0.5 * (func(a) + func(b)); // Inisialisasi nilai integral

    // Hitung nilai integral numerik menggunakan kaidah trapesium
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        integral += func(x);
        cout << "iterasi :" << i << " x : " << x << " integral sementara : " << integral << endl;
    }

    integral *= h; // Perhitungan nilai akhir integral
    return integral;
}

int main() {
    double lowerLimit = 1.8; // Batas bawah integrasi
    double upperLimit = 3.4; // Batas atas integrasi
    int n = 10000; // Jumlah pias, semakin besar semakin akurat

    double integralResult;

    // Panggil fungsi newtonCotesTrapesium untuk menghitung integral
    integralResult = newtonCotesTrapesium(lowerLimit, upperLimit, n);

    cout << "Hasil integral ( integral *= h ): " << integralResult << endl;

    return 0;
}
