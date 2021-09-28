// Program untuk menambahkan bilangan kompleks dengan melewati struck ke fungsi
// mengambil dua bilangan kompleks sebagai struct dan menambahkannya dengan menggunakan fungsi

#include <iostream>
using namespace std;

typedef struct complex {
    float real;
    float imag;
} complexNumber;

complexNumber addComplexNumbers(complex, complex);

int main() {
    complexNumber num1, num2, complexSum;
    char signOfImg;

    cout << "For 1st complex number," << endl;
    cout << "Enter real and imaginary parts respectively: " << endl;
    cin >> num1.real >> num1.imag;

    cout << "\nFor 2nd complex number," << endl;
    cout << "Enter real and imaginary parts respectively: " << endl;
    cin >> num2.real >> num2.imag;

    // panggil fungsi add dan simpan hasil di complexSum
    complexSum = addComplexNumbers(num1, num2);

    // Gunakan operator ternary untuk memeriksa tanda bilangan imajiner
    signOfImg = (complexSum.imag > 0) ? '+' : '-';

    // Gunakan operator ternary untuk menyesuaikan tanda bilangan imaginer
    complexSum.imag = (complexSum.imag > 0) ? complexSum.imag : -complexSum.imag;

    cout << "Sum = " << complexSum.real << signOfImg << complexSum.imag << "i" << endl;

    return 0;

}

complexNumber addComplexNumbers(complex num1, complex num2) {
    complex temp;
    temp.real = num1.real + num2.real;
    temp.imag = num1.imag + num2.imag;
    return (temp);
}