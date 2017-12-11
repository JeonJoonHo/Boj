#include <iostream>
using namespace std;

int arr[10000000] = { 0, };

int func(int number, int P, int index) {
    
    if (arr[number] != 0) return arr[number] - 1;
    
    arr[number] = index;
    
    int next = number;
    int result = 0;
    
    while (next > 0) {
        int a = next % 10;
        int tmp = 1;
        for (int i = 0; i < P; i++) {
            tmp = tmp * a;
        }
        result += tmp;
        next = next / 10;
    }
    
    return func(result, P, index + 1);
}

int main() {
    int A, P;
    cin >> A >> P;
    
    cout << func(A, P, 1);
    
    return 0;
}
