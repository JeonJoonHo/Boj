#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

bool cmp(vector<int> x, vector<int> y) {
    return x[0] < y[0];
}

vector< vector <int> > vt;
vector< vector <int> > rvt;
stack<int> st;
int visited[10001];

vector< vector <int> > scc;

void DFS(int v) {
    visited[v] = true;

    for(int next : vt[v]) {
        if (!visited[next])
            DFS(next);
    }

    st.push(v);
}

void rDFS(int v, int c) {
    visited[v] = true;
    scc[c].push_back(v);

    for(int next : rvt[v]) {
        if(!visited[next])
            rDFS(next, c);
    }
}

int main() {
    int V, E;

    cin >> V >> E;

    vt.resize(V + 1);
    rvt.resize(V + 1);

    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        vt[a].push_back(b);
        rvt[b].push_back(a);
    }

    for(int i = 1; i <= V; i++) {
        if (!visited[i])
            DFS(i);
    }

    int num = 0;

    for(int i = 0; i <= V; i++)
        visited[i] = 0;

    while(st.size()) {
        int here = st.top();
        st.pop();

        if(!visited[here]) {
            num++;
            scc.resize(num);
            rDFS(here, num - 1);
        }
    }

    for(int i = 0; i < num; i++)
        sort(scc[i].begin(), scc[i].end());
    sort(scc.begin(), scc.end(), cmp);

    cout << num << endl;
    for(int i = 0; i < num; i++) {
        for (int x : scc[i])
            cout << x << " ";
        cout << "-1" << endl;
    }
}