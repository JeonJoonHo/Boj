#include <iostream>
using namespace std;

int DP[201];

int main(){
    int N;
    int order[201];
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> order[i];
    }
    
    for(int i=1; i<=N; i++){
        DP[i] = 1;
        for (int j = 1; j <= i; j++){
            if (order[j]<order[i] && DP[j] + 1> DP[i]){
                DP[i] = DP[j] + 1;
            }
        }
    }
    
    int max = -1;
    for (int i = 1; i <= N; i++){
        if (max == -1 || max < DP[i]){
            max = DP[i];
        }
    }
    cout << N - max << endl;
}

