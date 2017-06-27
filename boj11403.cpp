#include <iostream>

#include <stdio.h>

using namespace std;

int size;
int map[105][105];
int chk[105];

void input() {
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &map[i][j]);
        }
    }
}



void dfs(int start, int num) {
    
    if(chk[num] == 1) return;
    chk[num] = 1;
    map[start][num] = 1;
    for(int i=0; i<size; i++) {
        if(map[num][i] == 1) {
            dfs(start, i);
        }
    }
}

void chk_init() {
    for(int i=0; i<size; i++) {
        chk[i] = 0;
    }
}

int main() {
    input();
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(map[i][j] == 1){
                chk_init();
                dfs(i,j);
            }
        }
    }
    
    
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}
