#include <iostream>
using namespace std;

int h, w, ans[100][100];
char s[100][100];

int main() {
    cin >> h >> w;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) cin >> s[i][j];

    for(int i=0; i<h; i++) {
        for(int j=w-1; j>=0; j--) {
            if(s[i][j] == 'c') continue;
            if(j < w-1 && ans[i][j+1] == -1) {
                ans[i][j] = -1;
                continue;
            }
            if(j < w-1 && ans[i][j+1] > 0) {
                ans[i][j] = ans[i][j+1]-1;
                continue;
            }
            ans[i][j] = -1;
            if(j == 0) continue;
            for(int k=j-1; k>=0; k--)  {
                if(s[i][k] == 'c') {
                    ans[i][j] = j - k;
                    break;
                }
            }
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) cout << ans[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}