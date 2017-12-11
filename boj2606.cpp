#include <iostream>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int Co, Cn;

int connection[101][101] = {0, };
int virus[101] = {0, };

void dfs(int index) {
    virus[index] = 1;
    
    for(int i = 1; i <= Co; i++) {
        if(virus[i] == 0 && connection[index][i] == 1){
            dfs(i);
        }
    }
}

int main(){
    cin >> Co >> Cn;
    
    for(int i = 1; i <= Cn; i++) {
        int num1, num2;
        
        cin >> num1 >> num2;
        
        connection[num1][num2] = 1;
        connection[num2][num1] = 1;
    }
    
    dfs(1);
    
    int result = 0;
    for(int i = 1; i <= Co; i++) {
        if(virus[i] == 1)
            result++;
    }
    
    cout << result - 1 << endl;
}
