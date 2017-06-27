#include <iostream>

using namespace std;

bool isTrue(int num) {
    int n1, n2, n3;
    
    n1 = num / 100;
    n2 = (num / 10) % 10;
    n3 = num % 10;
    
    if (n2 == 0) return false;
    else if ((n1 + n3) / 2 == n2 && (n1 + n3) % 2 == 0)
        return true;
    else
        return false;
    
}

int main(void) {
    int N;
    int cnt = 0;
    cin >> N;
    
    for (int i = N; i >= 1; i--) {
        if (i < 100)
            cnt++;
        else if (isTrue(i)) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
