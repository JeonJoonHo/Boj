#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    
    cnt = M - 1;
    for (int i = 0; i < M; i++) {
        cnt += N - 1;
    }
    
    cout << cnt << endl;
}
