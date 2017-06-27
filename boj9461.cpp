#include <iostream>
using namespace std;

long long int DP[101];
int main () {
    std::ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while(T--){
        int N;
        
        cin >> N;
        
        for(int i = 1; i <= N; i++){
            if(i <= 3) DP[i] = 1;
            else if(i <= 5) DP[i] = 2;
            else {
                DP[i] = DP[i-1] + DP[i-5];
            }
        }
        
        cout << DP[N] << endl;
    }
}
