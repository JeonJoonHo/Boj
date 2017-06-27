#include <iostream>
using namespace std;

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int main() {
    int inputNumber = 0;
    int wineArr[10001];
    int sum[10001];
    int result = 0;
    
    cin >> inputNumber;
    
    for (int i = 0; i < inputNumber; i++) {
        cin >> wineArr[i];
    }
    
    sum[0] = wineArr[0];
    sum[1] = sum[0] + wineArr[1];
    result = max(sum[0], sum[1]);
    
    for (int i = 2; i < inputNumber; i++) {
        sum[i] = wineArr[i] + max(sum[i - 2], sum[i - 3] + wineArr[i - 1]);
        sum[i] = max(sum[i], sum[i - 1]);
        result = max(result, sum[i]);
    }
    
    cout << result;
    
    
}
