#include <iostream>
using namespace std;

int main()
{
    int n;
    int num[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    for (int i = 0; i < n; i++) {
        int div = 2;
        int cnt = 0;
        
        while (num[i] != 1) {
            if (num[i] % div == 0) {
                num[i] = num[i] / div;
                cnt++;
            }
            else {
                if (cnt != 0) {
                    cout << div << " " << cnt << endl;
                    cnt = 0;
                    div++;
                }
                else {
                    div++;
                }
            }
        }
        cout << div << " " << cnt << endl;
    }
}
