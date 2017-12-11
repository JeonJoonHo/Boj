#include <iostream>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int map[51][51];

int Xlot[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Ylot[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void BFS(pair<int, int> location ) {
    map[location.first][location.second] = 0;
    
    for(int i = 0; i < 8; i++) {
        if(map[location.first + Xlot[i]][location.second + Ylot[i]] == 1) {
            pair<int, int> temp = make_pair(location.first + Xlot[i], location.second + Ylot[i]);
            
            BFS(temp);
        }
    }
}

int main(){
    while(true) {
        int H, W;
        
        int count = 0;
        
        cin >> W >> H;
        
        if(H == 0 && W == 0) break;
        
        for(int i = 1; i <= H; i++) {
            for(int j = 1; j <= W; j++) {
                cin >> map[i][j];
            }
        }
        
        for(int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if(map[i][j] == 1) {
                    pair<int, int> temp = make_pair(i, j);
                    BFS(temp);
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
}

