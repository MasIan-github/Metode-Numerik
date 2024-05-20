#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegralkan, yaitu e^x
double func(double x) {
    return -(pow(x, 2)) + 6 * x - 8;
}

// Metode Pias Kaidah Segiempat
double piasSegiempat(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;
    for (int i = 0; i < n; ++i) {
        double x0 = a + i * h;
        double x1 = a + (i + 1) * h;
        integral += func((x0 + x1) / 2.0) * h;
        cout << "iterasi: " << i + 1 << " x0 = " << x0 << " x1 = " << x1 <<" hasil sementara : " << integral << endl;
    }
    return integral;
}

int main() {
    double lowerLimit = 2; // batas bawah integrasi
    double upperLimit = 4; // batas atas integrasi
    int n = 20; // jumlah subinterval

    double integralResult = piasSegiempat(lowerLimit, upperLimit, n);

    cout << "Hasil integral: " << integralResult << endl;


    return 0;
}
