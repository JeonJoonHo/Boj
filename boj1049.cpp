#include <iostream>
using namespace std;

int main()
{
    int line, brand, pr;
    int s, o;
    int sline = 1001;
    int oline = 1001;
    cin >> line >> brand;
    for (int i = 0; i < brand; i++) {
        cin >> s >> o;
        if (sline > s) {
            sline = s;
        }
        if (oline > o) {
            oline = o;
        }
    }
    
    if (oline * 6 <= sline) {
        cout << line * oline << endl;
    }
    else {
        if ((line / 6 * sline) + sline < (line / 6 * sline) + (line % 6) * oline) {
            cout << (line / 6 * sline) + sline << endl;
        }
        if ((line / 6 * sline) + sline >= (line / 6 * sline) + (line % 6) * oline) {
            cout << (line / 6 * sline) + (line % 6) * oline << endl;
        }
    }
}
