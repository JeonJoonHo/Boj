#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if ((a%b) == 0) {
        return b;
    }
    return gcd(b,(a%b));
}

int main() {
    int line;
    int a, b, result;
    cin >> line;
    int *res = new int[line];
    
    for (int i = 0; i < line; i++) {
        cin >> a >> b;
        result = gcd(a, b);
        res[i] = (a*b) / result;
    }
    
    for (int i = 0; i < line; i++) {
        cout << res[i] << endl;
    }
    
}
