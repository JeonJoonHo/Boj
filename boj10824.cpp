#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int bb = 1;
    long long int dd = 1;
    long long int bnum = b;
    long long int dnum = d;
    
    do {
        bb *= 10;
        b = b / 10;
    } while (b > 0);
    
    do {
        dd *= 10;
        d = d / 10;
    } while (d> 0);
    
    long long int frontS = a * bb + bnum;
    long long int backS = c * dd + dnum;
    cout << frontS + backS << endl;
}
