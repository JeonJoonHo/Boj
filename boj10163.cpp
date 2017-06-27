#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int num = 0;
    int startX[102] = {};
    int startY[102] = {};
    int width[102] = {};
    int height[102] = {};
    int result[102] = {};
    int paper[102][102];
    memset(paper, -1, 102 * 102 * sizeof(int));
    
    cin >> num;
    
    for (int k = 0; k < num; k++) {
        cin >> startX[k] >> startY[k] >> width[k] >> height[k];
        for (int i = startX[k]; i < width[k] + startX[k]; i++) {
            for (int j = startY[k]; j < height[k] + startY[k]; j++) {
                if (paper[i][j] == -1) {
                    result[k]++;
                    paper[i][j] = k;
                }
                else {
                    result[paper[i][j]]--;
                    result[k]++;
                    paper[i][j] = k;
                }
            }
        }
    }
    
    for (int i = 0; i < num; i++) {
        cout << result[i] << endl;
    }
}
