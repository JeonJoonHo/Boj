#include <iostream>
#include <string.h>
using namespace std;

long long int DP[1001][10];

int main() {
    int N;
    
    cin >> N;
    
    for(int i = 0; i < 10; i++) {
        DP[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = j; k >= 0; k--) {
                DP[i][j] += DP[i-1][k] % 10007;
            }
        }
    }
    
    long long int result = 0;
    
    for(int i = 0; i < 10; i++) {
        result += DP[N][i] % 10007;
    }
    
    cout << result % 10007 << endl;
}

