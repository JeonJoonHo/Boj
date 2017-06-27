#include <iostream>
#include <algorithm>
using namespace std;
int N, n[501][501], r[501][501];

int main() {
    cin >> N;
    
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> n[i][j];
        }
    }
    
    r[0][0] = n[0][0];
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                r[i][j] = r[i - 1][j] + n[i][j];
            }
            else if (j == i && j != 0) {
                r[i][j] = r[i - 1][j - 1] + n[i][j];
            }
            else {
                r[i][j] = max(r[i - 1][j] + n[i][j], r[i - 1][j - 1] + n[i][j]);
            }
        }
    }
    int res = 0;
    
    for (int i = 0; i < N; i++) {
        result = r[N - 1][i];
        
        if (result > res) {
            res = result;
        }
    }
    
    cout << res;
}
