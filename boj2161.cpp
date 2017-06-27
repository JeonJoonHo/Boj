#include <iostream>
using namespace std;

int main() {
    int cardNum = 0;
    
    cin >> cardNum;
    int *card = new int[cardNum * 2];
    
    for (int i = 1; i <= cardNum; i++) {
        card[i] = i;
    }
    
    int start = 1;
    int end = cardNum;
    
    while (start != end) {
        cout << card[start] << " ";
        start++; end++;
        card[end] = card[start];
        start++;
    }
    cout << card[start];
}
