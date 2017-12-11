#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 1000000

int map[101][101];
int visit[101];
vector<int> arr;
vector<int> result;

void linked() {
    int res = INF;
    int resIndex;
    for(int i = 0; i < arr.size(); i++) {
        int index = arr[i];
        int time = 0;

        for(int j = 0; j < arr.size(); j++) {
            int yindex = arr[j];
            if(time < map[index][yindex]) {
                time = map[index][yindex];
            }
        }

        if(res > time) {
            res = time;
            resIndex = index;
        }

        visit[index] = 1;
    }
    result.push_back(resIndex);

    arr.clear();
}

int main() {
    int N, M;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        visit[i] = 0;
        for(int j = 1; j <= N; j++) {
            map[i][j] = INF;
            if(i == j) map[i][j] = 0;
        }
    }

    for(int i = 1; i <= M; i++) {
        int x, y;

        scanf("%d %d", &x, &y);

        map[x][y] = 1;
        map[y][x] = 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] != INF && visit[j] == 0) {
                arr.push_back(j);
            }
        }
        if(!arr.empty()) {
            linked();
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}