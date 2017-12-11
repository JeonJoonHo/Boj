#include <iostream>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int H, W, N, result;
char map[1004][1004];
bool visit[1004][1004];
pair<int,int> sLocation;
int row_move[] = {0,0,-1,1};
int col_move[] = {-1,1,0,0};

int bfs(int e){
    int cnt = 0;
    bool flag = false;
    queue < pair<int,int> > q;
    q.push({sLocation.first,sLocation.second});
    visit[sLocation.first][sLocation.second] = true;
    
    while(!q.empty()){
        cnt++;
        
        int size = q.size();
        
        
        for(int j = 0; j < size; j++){
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            
            if(map[crow][ccol] == e + '0'){
                sLocation.first = crow;
                sLocation.second = ccol;
                flag = true;
                break;
            }
            
            for(int i = 0; i < 4; i++){
                int nrow = crow + row_move[i];
                int ncol = ccol + col_move[i];
                
                if(nrow < 0 || nrow >= H || ncol < 0 || ncol >= W
                   || visit[nrow][ncol] || map[nrow][ncol] == 'X')
                    continue;
                
                visit[nrow][ncol] = true;
                q.push({nrow,ncol});
            }
        }
        
        if(flag)
            return cnt;
    }
}

int main(){
    
    cin >> H >> W >> N;
    
    for(int i = 0; i < H; i++){
        cin >> map[i];
        for(int j = 0; j < W; j++){
            
            if(map[i][j] == 'S'){
                sLocation.first = i;
                sLocation.second = j;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        result += (bfs(i) -1);
        memset(visit, false, sizeof(visit));
    }
    
    cout << result << endl;
}
