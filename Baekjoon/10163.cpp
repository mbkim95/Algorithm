#include <iostream>
using namespace std;

int map[103][103];
int cnt[103];

int main() {
    int n;    
    cin >> n;
    for (int t = 1; t <= n; t++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for (int i = x; i < x + w; i++) {
            for (int j = y; j < y + h; j++)
                map[i][j] = t;
        }
    }
    
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            cnt[map[i][j]]++;
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << '\n';
    return 0;
}