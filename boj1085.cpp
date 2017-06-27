#include <iostream>
using namespace std;

int main() {
    int x, y, w, h = 0;
    
    cin >> x >> y >> w >> h;
    
    int xlen = w - x;
    int ylen = h - y;
    int dx = x;
    int dy = y;
    
    int xres, yres;
    
    if (dx > xlen) {
        xres = xlen;
    }
    else {
        xres = dx;
    }
    if (dy > ylen) {
        yres = ylen;
    }
    else {
        yres = dy;
    }
    
    if (xres > yres) {
        cout << yres << endl;
    }
    else {
        cout << xres << endl;
    }
    
}
