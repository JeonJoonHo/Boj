//
// Created by 전준호 on 2017. 9. 22..
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

struct meeting {
    pair<int, int> location;
    int distance;
};

vector<meeting> app;
int apps[1001];
bool visit[1001];
char university[1001];

bool cmp(meeting &a, meeting &b) {
    return a.distance < b.distance;
}

int find(int u) {
    if (apps[u] == u) {
        return u;
    }
    else
        return apps[u] = find(apps[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if ( u == v )
        return;

    apps[u] = v;
}

int main() {
    int N, M, result = 0;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        char gender;

        cin >> gender;

        university[i] = gender;
        apps[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int x, y, dist;

        cin >> x >> y >> dist;

        pair<int, int> tmp = make_pair(x, y);
        meeting m;
        m.distance = dist;
        m.location = tmp;
        app.push_back(m);
    }

    sort(app.begin(), app.end(), cmp);

    for(int i = 0; i < M; i++) {
        int u = app[i].location.first;
        int v = app[i].location.second;

        if(university[u] == university[v])
            continue;
        if(find(u) != find(v)) {
            result += app[i].distance;
            merge(u, v);
            visit[u] = visit[v] = true;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(!visit[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << result << endl;
}