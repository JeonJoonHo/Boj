#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string lazer;
    getline(cin, lazer);
    
    stack<char> st;
    int num = 0;
    for (int i = 0; i < lazer.length(); i++) {
        if (lazer[i] == '(') {
            st.push(lazer[i]);
        }
        else {
            st.pop();
            if (lazer[i - 1] == '(') {
                num += st.size();
            }
            else {
                num++;
            }
        }
    }
    cout << num << endl;
}
