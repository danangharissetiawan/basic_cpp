#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    int emas_agus;
    int harga_emas;
    cout << "Emas Bu Agus: "; cin >> emas_agus;
    cout << "Harga Emas Sekarang: "; cin >> harga_emas;

    float harga_gadai = emas_agus * harga_emas / 0.7;
    cout << "Emas bu Agus di gadai dengan harga: " << harga_gadai << endl;

    cout << "Harga asli: " << emas_agus * harga_emas << endl;
    return 0;
};