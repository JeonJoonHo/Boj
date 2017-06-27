#include <iostream>
using namespace std;

long long myPibonach[68];

int main() {
    int T, n;
    cin >> T;
    
    myPibonach[0] = 1;
    myPibonach[1] = 1;
    myPibonach[2] = 2;
    myPibonach[3] = 4;
    for(int i = 0 ; i < T; i++) {
        cin >> n;
        if (myPibonach[n] == 0) {
            for (int i = 4; i <= n; i++) {
                myPibonach[i] = myPibonach[i-4] + myPibonach[i-3] + myPibonach[i-2] + myPibonach[i-1];
            }
        }
        cout << myPibonach[n] << endl;
    }
}
