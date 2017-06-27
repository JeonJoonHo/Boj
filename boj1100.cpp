#include <iostream>
using namespace std;

int main() {
    char chess[8][8];
    int white = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if ((i % 2) == 0) {
            for (int j = 0; j < 8; j++) {
                if ((j % 2) == 0) {
                    if (chess[i][j] == 'F') {
                        white++;
                    }
                }
            }
        }
        else {
            for (int j = 0; j < 8; j++) {
                if ((j % 2) == 1) {
                    if (chess[i][j] == 'F') {
                        white++;
                    }
                }
            }
        }
    }
    cout << white;
}
