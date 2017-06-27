#include <iostream>
using namespace std;

int main() {
    int N = 0;
    int F = 0;
    int result = 0;
    
    cin >> N >> F;
    
    for (int i = 0; i <= 100; i++) {
        N = (N / 100) * 100;
        N += i;
        if (N%F == 0) {
            result = i;
            break;
        }
    }
    
    if (result < 10) {
        cout << "0" << result << endl;
    }
    else {
        cout << result;
    }
}
