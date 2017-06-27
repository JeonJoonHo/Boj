#include <iostream>
using namespace std;

int main(){
    int num, index;
    int maxSum = 0;
    
    for(int i=1; i<=9; i++){
        cin >> num;
        if(maxSum < num){
            maxSum = num;
            index = i;
        }
    }
    
    cout << maxSum << endl<< index;
}
