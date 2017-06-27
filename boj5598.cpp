#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string input;
    char arr[1001];
    int num;
    getline(cin, input, '\n');
    
    for (int i = 0; i < input.size(); i++) {
        arr[i] = input.at(i);
        if (arr[i] == 'A') {
            arr[i] = 'X';
        }
        else if (arr[i] == 'B') {
            arr[i] = 'Y';
        }
        else if (arr[i] == 'C') {
            arr[i] = 'Z';
        }
        else {
            num = (int)arr[i];
            num = num - 3;
            arr[i] = (char)num;
        }
        cout << arr[i];
    }
}
