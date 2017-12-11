#include <iostream>
#include <utility>
#include <stdio.h>
#include <queue>
using namespace std;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int moveX, moveY;

int N;
char map[101][101];
char amap[101][101];

void DFS(int x, int y, char color) {
    map[x][y] = 'N';
    
    for(int i = 0; i < 4; i++) {
        moveX = x + dx[i];
        moveY = y + dy[i];
        
        if(moveX >= 0 && moveX < N && moveY >= 0 &&
           moveY < N && map[moveX][moveY] == color ) {
            map[moveX][moveY] = 'N';
            DFS(moveX, moveY, color);
        }
    }
}

void aDFS(int x, int y) {
    amap[x][y] = 'N';
    
    for(int i = 0; i < 4; i++) {
        moveX = x + dx[i];
        moveY = y + dy[i];
        
        if(moveX >= 0 && moveX < N && moveY >= 0 && moveY < N) {
            if(amap[moveX][moveY] == 'R' || amap[moveX][moveY] == 'G') {
                aDFS(moveX, moveY);
            }
        }
    }
}

void bDFS(int x, int y) {
    amap[x][y] = 'N';
    
    for(int i = 0; i < 4; i++) {
        moveX = x + dx[i];
        moveY = y + dy[i];
        
        if(moveX >= 0 && moveX < N && moveY >= 0 && moveY < N) {
            if(amap[moveX][moveY] == 'B'){
                bDFS(moveX, moveY);
            }
        }
    }
}

int main() {
    cin >> N;
    
    int bCnt = 0;
    int aCnt = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            amap[i][j] = map[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 'R') {
                DFS(i, j, 'R');
                bCnt++;
            }
            else if(map[i][j] == 'G') {
                DFS(i, j, 'G');
                bCnt++;
            }
            else if(map[i][j] == 'B') {
                DFS(i, j, 'B');
                bCnt++;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(amap[i][j] == 'R' || amap[i][j] == 'G') {
                aDFS(i, j);
                aCnt++;
            }
            else if(amap[i][j] == 'B') {
                bDFS(i, j);
                aCnt++;
            }
        }
    }
    
    cout << bCnt << " " << aCnt << endl;
}
