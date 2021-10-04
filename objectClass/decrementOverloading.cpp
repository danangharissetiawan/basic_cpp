#include <iostream>
using namespace std;

class Check {
    private:
        int i;
    public:
        Check(): i(3) { }
        Check operator -- () {
            Check temp;
            temp.i = --i;
            return temp;
        }

        // Perhatikan int inside bracket yang menunjukan postfix decrement.
        Check operator -- (int) {
            Check temp;
            temp.i = i--;
            return temp;
        }

        void Display() { cout << "i = " << i << endl; }
};

int main() {
    Check obj, obj1;
    obj.Display();
    obj1.Display();

    // Fungsi operator dipanggil, kemudian menepatkan nilai obj ke obj1
    obj1 = --obj;
    obj.Display();
    obj1.Display();

    // Menepatkan nilai obj ke obj1, hanya ketika fungsi operator sudah dipanggil.
    obj1 = obj--;
    obj.Display();
    obj1.Display();

    return 0;
}