#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

string na[100001];
map<string, int> ind;
map<int, string> name;


int main() {
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        
        char a[25];
        scanf("%s", a);
        
        name[i] = a;
        ind[a] = i;
    }
    
    for(int i = 0; i < M; i++) {
        char quiz[25];
        
        scanf("%s", quiz);
        
        if(quiz[0] >= '0' && quiz[0] <= '9') {
            cout << name[stoi(quiz)] << "\n";
        }
        else {
            printf("%d \n", ind[quiz]);
        }
    }
}
