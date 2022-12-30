#include <iostream>
using namespace std;

int n, b[1002][1002], ans[101];

int main() {
    cin >> n;
    for(int p=1; p<=n; p++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for(int i=y; i<y+h; i++) {
            for(int j=x; j<x+w; j++) {
                b[i][j] = p;
            }
        }
    }
    for(int i=0; i<=1001; i++) {
        for(int j=0; j<=1001; j++) {
            if(b[i][j] > 0) ans[b[i][j]]++;
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << '\n';
    return 0;
}