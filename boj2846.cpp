#include <iostream>
using namespace std;

int main()
{
    int start = 0;
    int next = 0;
    int end = 0;
    int num = 0;
    int length = 0;
    cin >> num;
    int* ride = new int[num];
    
    for (int i = 0; i < num; i++) {
        cin >> ride[i];
    }
    
    start = ride[0];
    end = ride[0];
    for (int i = 1; i <= num; i++) {
        next = ride[i];
        if (start < next && end < next) {
            end = next;
        }
        else if (end >= next) {
            int prevLen = length;
            length = end - start;
            if (prevLen > length) {
                length = prevLen;
            }
            start = ride[i];
            end = ride[i];
        }
    }
    
    cout << length << endl;
    delete ride;
}
