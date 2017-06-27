#include <iostream>
using namespace std;

int main() {
    int hour = 0;
    int min = 0;
    int sec = 0;
    
    int add = 0;
    
    cin >> hour >> min >> sec >> add;
    
    sec += add;
    min += sec / 60;
    sec = sec % 60;
    hour += min / 60;
    min = min % 60;
    hour = hour % 24;
    
    cout << hour << " " << min << " " << sec;
}
