//
// Created by 전준호 on 2017. 9. 26..
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define INF 100000000

struct location {
    int u, v, w;
};

bool cmp(location a, location b) {
    return a.w < b.w;
}

vector<location> loc;
vector<pair<int, int>> data[20001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;
int dist[20001];
int check[20001];

int main() {
    int V, E;

    cin >> V >> E;

    int K;

    cin >> K;

    for(int i = 0; i < E; i++) {
        location a;

        int x, y, z;
        cin >> x >> y >> z;

        a.u = x;
        a.v = y;
        a.w = z;

        loc.push_back(a);
        data[x].push_back({y, z});
    }

    for(int i = 1; i <= V; i++)
        dist[i] = INF;

    dist[K] = 0;
    pq.push({0, K});
    int cur;
    while(!pq.empty()) {
        cur = pq.top().second;
        pq.pop();
        while(!pq.empty() && check[cur]){
            cur = pq.top().second;
            pq.pop();
        }

        if(check[cur]) break;

        check[cur] = true;

        for(int i = 0; i < data[cur].size(); i++) {
            int v = data[cur][i].first;
            int w = data[cur][i].second;

            if(dist[v] > dist[cur] + w) {
                dist[v] = dist[cur] + w;
                pq.push({dist[v], v});
            }

        }
    }

    for(int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}