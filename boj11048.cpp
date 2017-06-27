#include <iostream>
#include <algorithm>
using namespace std;
int N, M, maze[1001][1001], D[1001][1001];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int result = 0;
            result = max(D[i - 1][j - 1], max(D[i - 1][j], D[i][j - 1]));
            D[i][j] = result + maze[i][j];
        }
    }
    
    cout << D[N][M] << endl;
}
