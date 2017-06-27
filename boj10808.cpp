#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int alpha[26] = {}, length = 0;
    
    getline(cin, str);
    
    length = str.size();
    
    for (int i = 0; i < length; i++) {
        int num = (int)str.at(i);
        alpha[num - 97]++;
    }
    
    for (int j = 0; j < 26; j++) {
        cout << alpha[j] << " ";
    }
}

