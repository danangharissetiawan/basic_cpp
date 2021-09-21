#include <iostream>
using namespace std;

int kpk(int n1, int n2);

int main() {
    int n1, n2;

    cout << "Enter two positive integers: ";
    cin >> n1 >> n2;

    cout << "KPK of " << n1 << " & " << n2 << " is: " << kpk(n1, n2) << endl;

    return 0;
}

int kpk(int n1, int n2) {
    if (n2 != 0)
        return kpk(n2,n1 % n2);
    else
        return n1;
}