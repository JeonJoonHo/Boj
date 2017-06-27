#include <iostream>
using namespace std;

int main(){
    int num;
    int res[3] = { 0 };
    
    for(int j=0; j<3; j++) {
        for (int i = 0; i < 4; i++) {
            cin >> num;
            if (num == 0) {
                res[j]++;
            }
        }
        switch(res[j]){
            case 0:
                cout << "E" << endl;
                break;
            case 1:
                cout << "A" << endl;
                break;
            case 2:
                cout << "B" << endl;
                break;
            case 3:
                cout << "C" << endl;
                break;
            case 4:
                cout << "D" << endl;
                break;
        }
    }
}
