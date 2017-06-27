#include <iostream>
using namespace std;

int main()
{
    int cNum, cSum, index = 0;
    int coin[10];
    int coinN = 0;
    
    cin >> cNum >> cSum;
    for (int i = 0; i < cNum; i++) {
        cin >> coin[i];
    }
    
    for (int i = 0; i < cNum; i++) {
        if (coin[i] <= cSum) {
            index++;
        }
    }
    
    while (cSum != 0) {
        int sum = 0;
        if (coin[index - 1] <= cSum) {
            while (sum + coin[index - 1] <= cSum) {
                sum += coin[index - 1];
                coinN++;
            }
            cSum = cSum - sum;
        }
        index--;
    }
    cout << coinN << endl;
}
