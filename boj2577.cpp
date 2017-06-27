#include <iostream>
using namespace std;

int result(int* num, int mul) {
    switch (mul%10)
    {
        case 0:
            num[0]++;
            break;
        case 1:
            num[1]++;
            break;
        case 2:
            num[2]++;
            break;
        case 3:
            num[3]++;
            break;
        case 4:
            num[4]++;
            break;
        case 5:
            num[5]++;
            break;
        case 6:
            num[6]++;
            break;
        case 7:
            num[7]++;
            break;
        case 8:
            num[8]++;
            break;
        case 9:
            num[9]++;
            break;
        default:
            break;
    }
    
    if (mul - 10 < 0) {
        return 0;
    }
    
    return result(num, mul/10);
}

int main() {
    int aNum, bNum, cNum;
    int num[10] = { 0 };
    int mul = 0;
    
    cin >> aNum >> bNum >> cNum;
    
    mul = aNum * bNum * cNum;
    
    result(num, mul);
    
    for (int i = 0; i < 10; i++) {
        cout << num[i] << endl;
    }
}
