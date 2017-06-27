#include <iostream>
using namespace std;

int main()
{
    int key[9] = {};
    int keya = 0;
    
    for (int i = 0; i < 9; i++) {
        cin >> key[i];
        keya += key[i];
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (key[i] + key[j] == keya - 100) {
                key[i] = key[j] = 0;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (key[i] < key[j]) {
                int temp = key[j];
                key[j] = key[i];
                key[i] = temp;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (key[i] != 0) {
            cout << key[i] << endl;
        }
    }
}
