#include <iostream>
#include <cmath>

using namespace std;

// F\fungsi nirlanjar 
double f(double x) {
    return exp(x) - 5 * pow(x, 2);  // bawaan cmath; (1) exp fungsi bilangan euler (2,718281828…) pangkat (x), 
                                    // (2) pow(a, b) == a pangkat b #power of a to b
}

// prosedur bagidua
void bagidua2(double a, double b, double galat) {
    if (f(a) * f(b) >= 0) {
        cout << "Tidak ada akar pada interval ini." << endl;
        return;
    }

    int iterasi = 1;
    double c;

    cout << "Iterasi\t  a\t  b\t  c\t  f(c)" << endl; // "\t" buat tab horizontal di output

    while ((b - a) >= galat) {
        // Menentukan titik tengah
        c = (a + b) / 2;

        cout << iterasi << "\t  " << a << "\t  " << b << "\t  " << c << "\t  " << f(c) << endl;

        // jika f(c) adalah akar yang diinginkan
        if (f(c) == 0.0)
            break;
        // jika f(c) memiliki tanda yang sama dengan f(a), maka akar berada di antara c dan b
        else if (f(c) * f(a) < 0)
            b = c;
        // jika f(c) memiliki tanda yang sama dengan f(b), maka akar berada di antara a dan c
        else
            a = c;

        iterasi++;
    }

    cout << "Akar persamaan adalah: " << c << endl;
}

int main() {
    double a = 0.0; // batas bawah interval
    double b = 1.0; // batas atas intervals
    double galat = 0.00001; // toleransi galat

    bagidua2(a, b, galat);

    return 0;
}
