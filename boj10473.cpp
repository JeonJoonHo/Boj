//
// Created by 전준호 on 2017. 9. 30..
//
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cstdio>
using namespace std;

typedef pair<double, int> pair_temp;
const double V = 5.0;

double dist[102] = {0, };
bool visit[102] = {0, };
int p[102] = {0, };


double distance_vertex(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

int main() {
    double x[102], y[102];
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    int N;
    cin >> N;
    vector< vector < pair_temp > > data(N + 2);

    for(int i = 2; i < N + 2; i++)
        cin >> x[i] >> y[i];

    dist[0] = 0;
    for(int i = 1; i < N+2; i++) {
        dist[i] = -1;

        data[0].push_back( pair_temp(distance_vertex(x[0], y[0], x[i], y[i])/V, i) );
        if(i == 1) continue;

        data[i].push_back( pair_temp( 2.0 + abs(distance_vertex(x[1], y[1], x[i], y[i])-50.0)/V, 1) );

        for(int j = i + 1; j < N+2; j++) {
            double double_temp = 2.0 + abs(distance_vertex(x[i], y[i], x[j], y[j]) - 50.0) / V;

            data[i].push_back(pair_temp(double_temp, j));
            data[j].push_back(pair_temp(double_temp, i));
        }
    }

    priority_queue< pair_temp > pq;
    pq.push(pair_temp(0,0));
    for(int i = 0; i < N + 2; i++) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        }while(visit[cur]);

        visit[cur] = true;

        for(auto& edge: data[cur]){
            if(dist[edge.second] < 0 || dist[edge.second] > dist[cur]+edge.first){
                dist[edge.second] = dist[cur]+edge.first;
                pq.push(pair_temp(-dist[edge.second], edge.second));
                p[edge.second] = cur;
            }
        }
    }

    cout << dist[1] << endl;
}
