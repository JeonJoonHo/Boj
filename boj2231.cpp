#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, number, a;
    cin >> n;
    
    string len = to_string(n);
    if (n >= 18) {
        number = n - (len.size() * 9);
    }
    else {
        number = 1;
    }
    for (int i = number; i <= n; i++) {
        number = i;
        string num = to_string(i);
        
        for (int j = 0; j < num.size(); j++) {
            string s = num.substr(j, 1);
            int sum = stoi(s);
            number += sum;
        }
        if (number == n) {
            cout << i << endl;
            break;
        }
    }
    if (number > n) {
        cout << "0" << endl;
    }
    
}
