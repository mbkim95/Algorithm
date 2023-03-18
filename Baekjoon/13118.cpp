#include <iostream>
using namespace std;

int p[5], x, y, r;

int main() {
    for(int i=1; i<=4; i++) cin >> p[i];
    cin >> x >> y >> r;
    int ans = 0;
    for(int i=1; i<=4; i++) {
        if(p[i] == x) ans = i;
    }
    cout << ans << '\n';
    return 0;
}