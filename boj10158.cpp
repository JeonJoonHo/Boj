#include <iostream>

using namespace std;

int main()
{
    int w, h, p, q, t;
    int dp = 1;
    int dq = 1;
    
    cin >> w >> h >> p >> q >> t;
    
    while (t--) {
        if (p == w || p == 0) {
            dp = -dp;
        }
        if (q == h || q == 0) {
            dq = -dq;
        }
        
        p += dp;
        q += dq;
    }
    
    cout << p << " " << q << endl;
}
