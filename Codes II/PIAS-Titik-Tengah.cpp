#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return exp(x);
}

// Prosedur metode titik tengah
void titikTengah(double a, double b, int n, double& I) {
    double h = (b - a) / n; // Lebar subinterval
    double x = a + h / 2; // Titik tengah pertama
    double sigma = func(x); // Inisialisasi nilai sigma

    // Hitung nilai sigma
    for (int r = 1; r < n; ++r) {
        x += h;
        sigma += func(x);
        cout <<"iterasi :"<< r << " x : " << x << " sigma :" << sigma << endl;

    }

    // Hitung nilai integral numerik
    I = sigma * h;
}

int main() {
    double lowerLimit = 1.8; // Batas bawah 
    double upperLimit = 3.4; // Batas atas 
    int n = 10000; // Jumlah pias

    double integralResult;

    // Panggil prosedur titikTengah untuk menghitung integral
    titikTengah(lowerLimit, upperLimit, n, integralResult);

    cout << "Hasil integral ((sigma * h)): " << integralResult << endl;

    return 0;
}
