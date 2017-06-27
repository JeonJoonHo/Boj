#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t, m, n;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &m);
        int *num1 = new int[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &num1[i]);
        }
        
        sort(num1, num1 + m);
        
        scanf("%d", &n);
        int *num2 = new int[n];
        bool found;
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &num2[j]);
            found = binary_search(num1, num1+m, num2[j]);
            if (found == true) {
                printf("1\n");
            }
            else if (found == false) {
                printf("0\n");
            }
        }
        delete num1;
        delete num2;
    }
    
}
