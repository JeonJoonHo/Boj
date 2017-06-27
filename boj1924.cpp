#include <iostream>
using namespace std;

int main() {
    int month, day;
    int monthArr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    
    cin >> month >> day;
    
    for (int i = 0; i < month - 1; i++) {
        sum = sum + monthArr[i];
    }
    sum = sum + day;
    
    switch (sum % 7)
    {
        case 0:
            cout << "SUN" << endl;
            break;
        case 1:
            cout << "MON" << endl;
            break;
        case 2:
            cout << "TUE" << endl;
            break;
        case 3:
            cout << "WED" << endl;
            break;
        case 4:
            cout << "THU" << endl;
            break;
        case 5:
            cout << "FRI" << endl;
            break;
        case 6:
            cout << "SAT" << endl;
            break;
    }
    
}
