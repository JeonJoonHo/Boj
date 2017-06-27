#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int per[1000];
    int pSum = 0;
    
    for (int i = 0; i < num; i++) {
        cin >> per[i];
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (per[i] < per[j]) {
                int temp = per[j];
                per[j] = per[i];
                per[i] = temp;
            }
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i+1; j++) {
            pSum += per[j];
        }
    }
    
    cout << pSum << endl;
}
