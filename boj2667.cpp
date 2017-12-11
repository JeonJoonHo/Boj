#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int map[26][26];
int result[26] = { 0, };
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};
int moveX, moveY;
int N, cityN = 1;

void DFS(int x, int y) {
    map[x][y] = 0;
    
    for(int i = 0; i < 4; i++) {
        moveX = x + dx[i];
        moveY = y + dy[i];
        
        if(moveX >= 0 && moveX < N && moveY >= 0 && moveY < N) {
            if(map[moveX][moveY] == 1) {
                result[cityN]++;
                DFS(moveX, moveY);
            }
        }
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1) {
                DFS(i, j);
                cityN++;
            }
        }
    }
    
    cout << cityN - 1 << endl;
    sort(result, result + cityN);
    for(int i = 1; i < cityN; i++)
        cout << result[i] + 1 << endl;
}
