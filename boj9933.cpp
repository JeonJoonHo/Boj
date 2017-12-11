#include <iostream>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int N;
    
    cin >> N;
    
    string pw[101];
    
    for(int i = 0; i < N; i++) {
        cin >> pw[i];
    }
    
    for(int i = 0; i < N; i++) {
        bool check = false;
        string rev_pw;
        for(string::reverse_iterator rit = pw[i].rbegin(); rit != pw[i].rend(); ++rit) {
            rev_pw += *rit;
        }
        
        for(int j = 0; j < N; j++) {
            if(rev_pw.compare(pw[j]) == 0) {
                cout << pw[j].size() << " " << pw[j].at( pw[j].size() / 2 );
                check = true;
            }
            else continue;
        }
        
        if(check == true) break;
    }
}
