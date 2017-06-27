#include <iostream>
#include <string>
using namespace std;

int rNum(string str) {
    if (str == "black") {
        return 0;
    }
    else if (str == "brown") {
        return 1;
    }
    else if (str == "red") {
        return 2;
    }
    else if (str == "orange") {
        return 3;
    }
    else if (str == "yellow") {
        return 4;
    }
    else if (str == "green") {
        return 5;
    }
    else if (str == "blue") {
        return 6;
    }
    else if (str == "violet") {
        return 7;
    }
    else if (str == "grey") {
        return 8;
    }
    else if (str == "white") {
        return 9;
    }
}

int rMul(string str) {
    if (str == "black") {
        return 1;
    }
    else if (str == "brown") {
        return 10;
    }
    else if (str == "red") {
        return 100;
    }
    else if (str == "orange") {
        return 1000;
    }
    else if (str == "yellow") {
        return 10000;
    }
    else if (str == "green") {
        return 100000;
    }
    else if (str == "blue") {
        return 1000000;
    }
    else if (str == "violet") {
        return 10000000;
    }
    else if (str == "grey") {
        return 100000000;
    }
    else if (str == "white") {
        return 1000000000;
    }
}

int main() {
    string input[3];
    long long int result = 0;
    for (int i = 0; i < 3; i++) {
        getline(cin, input[i], '\n');
    }
    
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            result = rNum(input[0]) * 10;
        }
        else if (i == 1) {
            result = result + rNum(input[1]);
        }
        else if (i == 2) {
            result = result * rMul(input[2]);
        }
    }
    
    cout << result;
}
