#include <iostream>
using namespace std;

int main()
{
    int e, s, m;
    int cnt = 1;
    cin >> e >> s >> m;
    
    if (e == s == m) {
        cout << cnt << endl;
    }
    else {
        while (!(e == 1 && s == 1 && m == 1)) {
            if (e == 0) {
                e = 15;
            }
            if (s == 0) {
                s = 28;
            }
            if (m == 0) {
                m = 19;
            }
            e--;
            s--;
            m--;
            cnt++;
        }
        cout << cnt << endl;
    }
}
