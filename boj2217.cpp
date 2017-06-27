#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int wei[100001];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &wei[i]);
    }
    
    sort(wei + 1, wei + N + 1);
    
    int a = 0;
    for (int i = 1; i <= N; i++) {
        a = max(a, wei[i] * (N - i + 1));
    }
    
    cout << a << endl;
}
