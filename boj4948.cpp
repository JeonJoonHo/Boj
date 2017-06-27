#include <iostream>
using namespace std;

bool p[270000];
int s[270000];
int n;

int main() {
    std::ios::sync_with_stdio(false);
    p[0] = p[1] = true;
    for (int i = 2; i <= 270000; i++) {
        if (p[i])continue;
        for (int j = i + i; j <= 270000; j += i) {
            p[j] = true;
        }
    }
    for (int i = 2; i <= 270000; i++) {
        if (!p[i])s[i]++;
        s[i] += s[i - 1];
    }
    cin >> n;
    
    while (n) {
        cout << s[2*n] - s[n] << endl;
        cin >> n;
    }
}
