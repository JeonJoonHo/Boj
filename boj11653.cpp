#include <iostream>
using namespace std;

int main() {
    int num = 0;
    
    cin >> num;
    
    for (int i = 2; i*i <= num; i++)
    {
        if (num%i == 0)
        {
            cout << i << endl;
            num /= i;
            --i;
        }
    }
    
    if (num > 1) {
        cout << num << endl;
    }
}
