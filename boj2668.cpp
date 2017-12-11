#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int number[101];
int visit[101];
int N;
int result = 0;
vector <int> res;

void DFS(int index, int des) {
    visit[index] = 1;
    
    if(number[index] == des) {
        result++;
        res.push_back(index);
        return;
    }
    
    if(number[index] == index) {
        return;
    }
    else {
        if(visit[number[index]] == 0) {
            DFS(number[index], des);
        }
    }
}

int main() {
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> number[i];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) visit[j] = 0;
        DFS(i, i);
    }
    
    sort(res.begin(), res.end());
    cout << result << endl;
    for(int i = 0; i < result; i++) {
        cout << res[i] << endl;
    }
}
