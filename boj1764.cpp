#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, count = 0;
    set<string> s1;
    vector<string> s2;
    vector<string> result;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string s;
        
        cin >> s;
        
        s1.insert(s);
    }
    
    for(int i = 0; i < M; i++){
        string s;
        
        cin >> s;
        
        s2.push_back(s);
    }
    
    for(int i = 0; i < M; i++){
        if(s1.count(s2[i]))
            result.push_back(s2[i]);
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}



