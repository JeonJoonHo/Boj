//
// Created by 전준호 on 2017. 9. 19..
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

struct map {
    pair<int, int> location;
    int val;
};

bool cmp(map &a, map &b) {
    return a.val < b.val;
}

vector<map> m;
int mm[100010];

int find(int u) {
    if (mm[u] == u) {
        return u;
    }
    else
        return mm[u] = find(mm[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if ( u == v )
        return;

    mm[u] = v;
}

int main() {
    int V, E;
    int result = 0;

    cin >> V >> E;

    for(int i = 1; i <= V; i++)
        mm[i] = i;

    for(int i = 1; i <= E; i++) {
        int x, y, val;

        cin >> x >> y >> val;

        pair<int, int> tmp = make_pair(x, y);
        map mtmp;
        mtmp.location = tmp;
        mtmp.val = val;

        m.push_back(mtmp);
    }

    sort(m.begin(), m.end(), cmp);

    for(int i = 0; i < E; i++) {
        if(find(m[i].location.first) != find(m[i].location.second)) {
            result += m[i].val;
            merge(m[i].location.first, m[i].location.second);
        }
    }

    cout << result << endl;
}
