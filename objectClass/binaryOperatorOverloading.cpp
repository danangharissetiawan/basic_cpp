#include <iostream>
using namespace std;

class Complex 
{
    private:
        float real;
        float imag;
    public:
        Complex(): real(0), imag(0) { }
        void input() {
            cout << "Masukan masing-masing bilangan real dan imaginer: ";
            cin >> real >> imag;
        }

        // Operator overloading
        Complex operator - (Complex c2)
        {
            Complex temp;
            temp.real = real - c2.real;
            temp.imag = imag - c2.imag;

            return temp;
        }

        void output() {
            if (imag < 0) {
                cout << "Output Complex number: " << real << imag << "i" << endl;
            } else {
                cout << "Output Complex number: " << real << " + " << imag << "i" << endl;
            }
        }
};

int main() 
{
    Complex c1, c2, result;

    cout << "Masukan bilangan Complex pertama: \n"; c1.input();
    cout << "Masukan bilangan Complex kedua: \n"; c2.input();

    // Dalam kasus overloading operator" biner dalam pemrograman C++,
    // objek di sebelah kanan operator selalu dianggap sebagai argumen oleh compiler.
    result = c1 - c2;
    result.output();

    return 0;
}