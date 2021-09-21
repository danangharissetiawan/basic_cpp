#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Initialization
double volumeTabung(int r, int t);
int volumeBox(int p, int l, int t);
double kapasitasBox(int box, double tabung);

struct armada {
    char platno[10];
    char merk[30];
    int p_box, l_box, t_box, volume;
    double kapasitas;
};

void header_display();
void display(int i, armada n);
armada getData(int i, armada data);

// Main function
int main() {
    int r, t, j_armada;
    double v_tabung;

    cout << "Masukan jumlah armada: ";
    cin >> j_armada;
    
    armada truk[j_armada];
    
    // tabung
    cout << "---Ukuran Tabung---" << endl;
    cout << "Masukan jari-jari tabung: ";
    cin >> r;
    cout << "Masukan dan tinggi tabung: ";
    cin >> t;
    v_tabung = volumeTabung(r, t);
    
    // armada truk
    for (int i = 0; i < j_armada; i++){
        truk[i] = getData(i, truk[i]);

        truk[i].volume = volumeBox(truk[i].p_box, truk[i].l_box, truk[i].t_box);
        truk[i].kapasitas = kapasitasBox(truk[i].volume, v_tabung);
    }

    printf("\n***Volume tabung: %.2f \u33A5 ***\n", v_tabung);
    
    header_display();
    for (int n = 0; n < j_armada; ++n) {
        display(n, truk[n]);
    }    

    return 0;
}

// fungsi untuk menghitung folume tabung
double volumeTabung(int r, int t) {
    double volume;
    volume = M_PI * r * r * t;

    return volume;
}

// volume box
int volumeBox(int p, int l, int t) {
    int volume = p * l * t;
    return volume;
}

// kapasitas box muat berapa tabung
double kapasitasBox(int box, double tabung) {
    double kapasitas = box / tabung;
    return floor(kapasitas);
}

// header untuk menampilkan data
void header_display() {
    cout << "---Data Armada Truk---" << endl;
    cout
        << left << setw(10) << "ID"
        << left << setw(15) << "PLAT NOMOR"
        << left << setw(30) << "MERK"
        << left << setw(30) << "VOLUME BOX"
        << left << setw(15) << "KAPASITAS"
        << endl;
}

// input data 
armada getData(int i, armada data) {
    cout << "\n--- Data Petani ke - " << i + 1 << " ---" << endl;
    cout << "Plat Nomor: ";cin >> data.platno;
    cout << "Merk: ";cin >> data.merk;
    cout << "Panjang Box: ";cin >> data.p_box;
    cout << "Lebar Box: ";cin >> data.l_box;
    cout << "Tinggi Box: "; cin >> data.t_box;

    return data;
}

// menampilkan data
void display(int i, armada n) {
    
    cout
        << left << setw(10) << (i+1)
        << left << setw(15) << n.platno
        << left <<  setw(30) <<n.merk
        << left << n.volume << setw(30)  << " \u33A5"
        << left << n.kapasitas << setw(15) << " tabung"
        << endl;
}
