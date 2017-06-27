#include <iostream>
using namespace std;

int main(){
    int hamburger[3] = { 0 };
    int drink[2] = { 0 };
    
    int minHam = 2001;
    int minDrink = 2001;
    
    for(int i=0; i<3; i++){
        cin >> hamburger[i];
        if(minHam > hamburger[i]) minHam = hamburger[i];
    }
    for(int i=0; i<2; i++){
        cin >> drink[i];
        if(minDrink > drink[i]) minDrink = drink[i];
    }
    
    cout << minHam + minDrink - 50;
}
