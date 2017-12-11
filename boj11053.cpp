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

//int main() {
//    vector<int> vt;
//    vector<int> sq;
//
//    int N;
//    cin >> N;
//
//    for(int i = 0; i < N; i++) {
//        int number;
//        cin >> number;
//
//        sq.push_back(number);
//    }
//
//    vt.push_back(sq[0]);
//    for(int i = 1; i < N; i++) {
//        if(vt.back() < sq[i])
//            vt.push_back(sq[i]);
//        else {
//            auto it = lower_bound(vt.begin(), vt.end(), sq[i]);
//            *it = sq[i];
//        }
//    }
//
//    cout << vt.size() << endl;
//}
// Binary search

int main() {
    vector<int> sq;
    int dp[1001];

    int N, result = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int number;
        cin >> number;

        sq.push_back(number);
    }

    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(sq[i] > sq[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        result = max(result, dp[i]);
    }

    cout << result << endl;
}