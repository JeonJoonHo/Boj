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

struct zoo {
    pair<int, int> location;
    int price;
};

vector<zoo> zoos;
vector<int> zooss;
vector<int> ranking;

bool cmp(zoo &a, zoo &b) {
    return a.price < b.price;
}

int find(int u) {
    if(zooss[u] == u) {
        return u;
    }
    else {
        int p = find(zooss[u]);
        zooss[u] = p;
        return p;
    }
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if ( u == v )
        return ;

    zooss[u] = v;
}

int main() {
    int N, M, result = 0;

    cin >> N >> M;
    ranking.resize(N + 1, 1);
    zooss.resize(N + 1, 0);

    int cnt = N;

    for(int i = 1; i <= N; i++) {
        zooss[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int x, y, p;

        cin >> x >> y >> p;

        zoo z;
        pair<int, int> tmp = make_pair(x, y);
        z.price = p;
        z.location = tmp;
        zoos.push_back(z);
    }

    sort(zoos.begin(), zoos.end(), cmp);

    for(int i = 0; i < M; i++) {
        int u = zoos[i].location.first;
        int v = zoos[i].location.second;

        if(find(u) == find(v))
            continue;
        else {
            merge(find(u), find(v));
            result += zoos[i].price;
            cnt--;
        }

        if(cnt == 2)
            break;
    }

    cout << result << endl;
}