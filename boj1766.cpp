//
// Created by 전준호 on 2017. 10. 31..
//
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> vt[32001];
int indegree[32001];

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        vt[a-1].push_back(b-1);
        indegree[b-1] += 1;
    }

    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int index = pq.top();
        pq.pop();
        cout << index+1 << " ";
        for(int i = 0; i < vt[index].size(); i++) {
            int nextNode = vt[index][i];
            indegree[nextNode] -= 1;
            if(indegree[nextNode] == 0) pq.push(nextNode);
        }
    }
}