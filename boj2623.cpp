#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int graph[1001][1001];
int indgree[1001] = { 0, };

queue<int> q;
vector<int> result;

int main() {
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int num, first, prev;
        cin >> num;

        for(int j = 0; j < num; j++) {
            int graphIndex;

            cin >> graphIndex;

            if(j == 0)
                first = graphIndex;
            else {
                graph[prev][graphIndex] = 1;
                indgree[graphIndex]++;
            }

            prev = graphIndex;
        }
    }

    bool check = false;

    for(int i = 1; i <= N; i++) {
        if( indgree[i] == 0 ) {
            q.push( -i );
            check = true;
        }
    }

    if(!check) {
        cout << "0" << endl;
        return 0;
    }

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int index = -q.front();
            for (int j = 1; j <= N; j++) {
                if (graph[index][j] == 1) {
                    indgree[j]--;
                    if (indgree[j] == 0) {
                        q.push( -j );
                    }
                }
            }
            result.push_back( index );
            q.pop();
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) {
                if(graph[i][j] == 1) {
                    cout << "0" << endl;
                    return 0;
                }
            }
        }
    }

    if(result.size() < N) cout << "0" << endl;
    else {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }
}