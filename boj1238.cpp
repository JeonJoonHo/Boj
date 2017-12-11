#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 1000000

int map[1001][1001];

int main() {
    int N, M, X;
    
    scanf("%d %d %d", &N, &M, &X);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map[i][j] = INF;
            if(i == j)
                map[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= M; i++) {
        int x, y, time;
        
        scanf("%d %d %d", &x, &y, &time);
        
        map[x][y] = time;
    }
    
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if(map[j][i] == INF) {
                    break;
                }
                if(map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
    
    int distance = 0;
    for(int i = 1 ; i <= N; i++)
        distance = max(distance, map[i][X] + map[X][i]);
    
    cout << distance << endl;
}
