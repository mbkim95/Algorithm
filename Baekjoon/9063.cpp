#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, minX, minY, maxX, maxY;
    minX = minY = 10001;
    maxX = maxY = -10001;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);        
        maxY = max(maxY, y);
    }
    if(n == 1) cout << 0 << '\n';
    else cout << (maxX - minX) * (maxY - minY) << '\n';
    return 0;
}