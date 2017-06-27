#include <iostream>
using namespace std;

int num, s[1000][1000], res[1000];

int main() {
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> s[i][j];
        }
    }
    
    
    if (num == 2) {
        res[0] = 1;
        res[1] = s[0][1] - 1;
    }
    else {
        res[0] = (s[0][1] + s[0][2] - s[1][2]) / 2;
        for (int i = 1; i < num; i++) {
            res[i] = s[i - 1][i] - res[i-1];
        }
    }
    
    for (int i = 0; i < num; i++) {
        cout << res[i] << " ";
    }
    
}
