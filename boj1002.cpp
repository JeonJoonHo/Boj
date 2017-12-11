#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    
    cin >> T;
    
    while(T--) {
        int x1, y1, r1, x2, y2, r2;
        
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        int rd = abs(r1 - r2);
        int rs = r1 + r2;
        double d = sqrt( pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0) );
        
        int result;
        
        if (rd < d && rs > d)
            result = 2;
        else if (rs == d || rd == d)
            result = 1;
        else
            result = 0;
        
        if (x1 == x2 && y1 == y2 && r1 == r2)
            result = -1;
        
        cout << result << endl;
    }
}



