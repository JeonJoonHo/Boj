#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num ,a, b;
    cin >> num;
    char str[1000000] = "";
    
    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        cin >> str;
        string st = str;
        int len = st.size();
        
        for (int j = 0; j < len; j++) {
            int x = str[j] - 65;
            str[j] = ((a*x + b) % 26) + 65;
        }
        
        cout << str << endl;
    }
}
