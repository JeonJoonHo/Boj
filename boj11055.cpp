//
// Created by 전준호 on 2017. 11. 12..
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
        dp[i] = sq[i];
        for(int j = 0; j < i; j++) {
            if(sq[j] < sq[i] && dp[i] < dp[j] + sq[i])
                dp[i] = dp[j] + sq[i];
        }
        if(result < dp[i])
            result = dp[i];
    }

    cout << result << endl;
}