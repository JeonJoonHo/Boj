#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    set<string> employee;
    set<string>::reverse_iterator itor;
    itor = employee.rbegin();
    for(int i = 0; i < N; i++) {
        string logName;
        string logEnter;
        
        cin >> logName >> logEnter;
        
        size_t ent = logEnter.find("enter");
        size_t exi = logEnter.find("leave");
        if(ent != string::npos) {
            employee.insert(logName);
        }
        if(exi != string::npos ) {
            employee.erase( employee.find(logName) );
        }
    }
    
    for(itor=employee.rbegin(); itor != employee.rend(); itor++)
    {
        cout<< *itor << endl;
    }
}
