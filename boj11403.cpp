#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int result[101][101];
int visit[101][101];
queue<int> que;

void DFS(int start, int size){
    que.push(start);
    
    while(!que.empty()){
        int current = que.front();
        que.pop();
        
        for(int i = 0; i < size; i++) {
            if(!visit[current][i] && map[current][i] == 1) {
                que.push(i);
                visit[current][i] = 1;
                result[start][i] = 1;
            }
        }
    }
}

void reset(int size){
    for(int i = 0; i < size; i++){
        for(int j =0; j < size; j++) {
            visit[i][j] = 0;
        }
    }
}

int main() {
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0 ; i < N; i++) {
        reset(N);
        DFS(i, N);
    }
    
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
