#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) {
        cout << a << "+" << b << "=" << c << endl;
    }
    else if (a - b == c) {
        cout << a << "-" << b << "=" << c << endl;
    }
    else if (a / b == c) {
        cout << a << "/" << b << "=" << c << endl;
    }
    else if (a*b == c) {
        cout << a << "*" << b << "=" << c << endl;
    }
    else if (a == b+c) {
        cout << a << "=" << b << "+" << c << endl;
    }
    else if (a == b-c) {
        cout << a << "=" << b << "-" << c << endl;
    }
    else if (a == b*c) {
        cout << a << "=" << b << "*" << c << endl;
    }
    else if (a == b/c) {
        cout << a << "=" << b << "/" << c << endl;
    }
    
}
