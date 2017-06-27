#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int person = 0;
    int max = 0;
    int out, in;
    
    for (int i = 0; i < 4; i++) {
        cin >> out >> in;
        person -= out;
        person += in;
        if (person > max) {
            max = person;
        }
    }
    cout << max << endl;
}
