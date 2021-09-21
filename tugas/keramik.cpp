//
// Created by haris on 07/09/21.
//

#include <iostream>

using namespace std;

int main() {
    int pj_kamar, lb_kamar, pj_keramik, lb_keramik, isi_perdus, harga_perdus;

    cout << "Panjang Kamar: "; cin >> pj_kamar;
    cout << "Lebar Kamar: "; cin >> lb_kamar;
    int luas_kamar = pj_kamar * lb_kamar; // Hitung luas kamar
    cout << "Luas kamar: " << luas_kamar << endl; // Output luas kamar

    cout << "Panjang Keramik: "; cin >> pj_keramik;
    cout << "Lebar Keramik: "; cin >> lb_keramik;
    int luas_keramik = pj_keramik * lb_keramik; // Hitung luas keramik
    cout << "Luas Keramik: " << luas_keramik << endl; // Output luas keramik
    int jml_keramik = luas_kamar / luas_keramik;
    cout << "Jumlah keramik yang dibutuhkan: " << jml_keramik << endl;

    cout << "Isi keramik per dus: "; cin >> isi_perdus;
    int dus_keramik = jml_keramik / isi_perdus;

    cout << "Jumlah dus kramik yang harus dibeli: " << dus_keramik << endl;

    cout << "Harga keramik per dus: "; cin >> harga_perdus;
    int biaya = dus_keramik * harga_perdus;
    cout << "Biaya yang harus dikeluarkan: " << biaya << endl;

    return 0;
};