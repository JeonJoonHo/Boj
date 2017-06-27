#include <iostream>
using namespace std;

class Person {
public:
    int key = 0;
    int wei = 0;
    int rank = 1;
    
    Person() {
        wei = 0;
        key = 0;
    }
    void insert(int k, int w) {
        this->key = k;
        this->wei = w;
        this->rank = 1;
    }
};

int main()
{
    int num, key, wei;
    cin >> num;
    Person *per = new Person[num];
    int maxKey = 0;
    int maxWie = 0;
    
    for (int i = 0; i < num; i++) {
        cin >> key >> wei;
        per[i].insert(key, wei);
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (per[i].wei < per[j].wei && per[i].key < per[j].key) {
                per[i].rank++;
            }
        }
    }
    
    for (int i = 0; i < num; i++) {
        cout << per[i].rank << " ";
    }
}
