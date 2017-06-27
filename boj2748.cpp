#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    scanf("%d", &N);
    long long int a[1000];
    
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= N; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    
    printf("%lld", a[N]);
    return 0;
}
