#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 1000000

int price[101][101];

int main() {
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j)
                price[i][j] = INF;
            else
                price[i][j] = 0;
        }
    }
    
    for(int i = 0; i < M; i++) {
        int start, end, cost;
        
        cin >> start >> end >> cost;
        
        if (price[start][end] > cost) {
            price[start][end] = cost;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if(price[j][k] > price[j][i] + price[i][k]){
                    price[j][k] = price[j][i] + price[i][k];
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << price[i][j] << " ";
        }
        cout << endl;
    }
}
