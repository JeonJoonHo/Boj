#include <iostream>
using namespace std;

int chk(int num) {
    if (num == 1) {
        return 1;
    }
    else if (num == 2) {
        return 2;
    }
    else if (num == 3) {
        return 4;
    }
    else {
        return chk(num-1)+chk(num-2)+chk(num-3);
    }
}

int main()
{
    int t;
    cin >> t;
    int* num = new int[t];
    
    for (int i = 0; i < t; i++) {
        cin >> num[i];
    }
    
    for (int i = 0; i < t; i++) {
        cout << chk(num[i]) << endl;
    }
}
