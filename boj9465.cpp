#include <iostream>
using namespace std;

int stiker[2][100010];
int DP[2][100010];

int main() {
    int T;
    
    cin >> T;
    
    while(T--){
        int N;
        
        cin >> N;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> stiker[i][j];
            }
        }
        
        for (int i = 0; i < N; i++){
            DP[0][i] = max(max(DP[0][i - 1], DP[1][i - 1] + stiker[0][i]), DP[1][i - 2] + stiker[0][i]);
            DP[1][i] = max(max(DP[1][i - 1], DP[0][i - 1] + stiker[1][i]), DP[0][i - 2] + stiker[1][i]);
        }
        
        if (DP[0][N-1] > DP[1][N-1]) cout << DP[0][N-1] << endl;
        else cout << DP[1][N-1] << endl;
        
        
    }
}
