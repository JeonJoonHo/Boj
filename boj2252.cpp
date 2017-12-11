//
// Created by 전준호 on 2017. 9. 13..
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

vector<int> graph[32001];
int indegree[32001];

vector<int> result;
queue<int> q;

int main() {
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int x, y;

        cin >> x >> y;

        graph[x].push_back(y);
        indegree[y]++;
    }

    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(-i);
        }
    }

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int index = -q.front();
            for(int j = 0; j < graph[index].size(); j++) {
                indegree[graph[index][j]]--;
                if(indegree[graph[index][j]] == 0) {
                    q.push(-graph[index][j]);
                }
            }
            result.push_back( index );
            q.pop();
        }
    }

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

