//
// Created by 전준호 on 2017. 11. 14..
//
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int init(vector<int> arr, int* tree, int current_node, int current_left, int current_right){
    if(current_left == current_right) {
        return tree[current_node] = arr[current_node];
    }

    int mid = (current_left + current_right) / 2;

    return tree[current_node] = init(arr, tree, current_node*2, current_left, mid) +
                                init(arr, tree, current_node*2+1, mid + 1, current_right);
}

int main() {
    int N, M, K;
    cin >> N;

    vector<int> arr(N);
    int tree[3000000];

    for(int i = 0; i < N; i++){
        int number;
        cin >> number;

        arr.push_back(number);
    }

    init(arr, tree, 1, 0, N-1);

}
