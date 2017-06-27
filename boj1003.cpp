#include <iostream>
using namespace std;

int memo[40] = { 1,1, };

int fibonacci(int n) {
    if (n <= 1) {
        return memo[n];
    }
    else {
        if (memo[n] > 0) return memo[n];
    }
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int T; //testCase
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int temp;
        cin >> temp;
        
        if (temp == 0) {
            cout << "1 0" << endl;
        }
        else if (temp == 1) {
            cout << "0 1" << endl;
        }
        else {
            fibonacci(temp);
            cout << memo[temp - 2] << " " << memo[temp - 1] << endl;
        }
    }
}

