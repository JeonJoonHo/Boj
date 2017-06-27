#include <iostream>
using namespace std;

int main(){
    int num, index;
    int maxSum = 0;
    
    for(int i=0; i<5; i++){
        int sum = 0;
        for(int j=0; j<4; j++){
            cin >> num;
            sum += num;
        }
        if(sum > maxSum) {
            maxSum = sum;
            index = i + 1;
        }
    }
    
    cout << index << " " << maxSum;
}
