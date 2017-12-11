//
// Created by 전준호 on 2017. 9. 27..
//
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 10000000

struct ticket{
    int u, v, cost, dist;
};

struct pq{
    int pos, cost, dist;

    bool operator <(const pq &n) const
    {
        return pos == n.pos ? cost > n.cost : dist > n.dist;
    }
};

vector< ticket > data[10001];
int dp[101][10001] = {0, };

int main() {
    int T;

    cin >> T;

    while(T--) {
        priority_queue< pq > pq;
        int N, M, K;
        // N : 공항 수, M : 지원비용 K : 티켓 수
        cin >> N >> M >> K;

        for(int i = 0; i < K; i++) {
            int u, v, cost, dist;
            cin >> u >> v >> cost >> dist;

            ticket t = {0, 0, 0, 0};
            t.u = u;
            t.v = v;
            t.cost = cost;
            t.dist = dist;

            data[u].push_back( t );
        }

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                dp[i][j] = INF;

        dp[1][1] = 0;
        pq.push({1, 0, 0}); // 현재 위치, 거리, 비용
        int currentPos;
        int currentCost;
        int currentDist;
        while(!pq.empty()) {
            currentPos = pq.top().pos;
            currentCost = pq.top().cost;
            currentDist = pq.top().dist;
            pq.pop();

            if(dp[currentPos][currentCost] < currentDist) continue;
            dp[currentPos][currentCost] = currentDist;

            for(int i = 0; i < data[currentPos].size(); i++) {
                int v = data[currentPos][i].v;
                int d = data[currentPos][i].dist;
                int c = data[currentPos][i].cost;

                if(currentCost + c <= M && dp[v][currentCost + c] > currentDist + d) {
                    dp[v][currentCost + c] = currentDist + d;
                    pq.push({v, currentCost + c, dp[v][currentCost + c]});
                }
            }
        }

        int result = INF;
        for(int i = 1; i <= M; i++) {
            if(result > dp[N][i]) result = dp[N][i];
        }

        if(result == INF)
            cout << "Poor KCM" << endl;
        else
            cout << result << endl;

        for(int i = 1; i <= N; i++) data[i].clear();
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                dp[i][j] = 0;
    }
}

