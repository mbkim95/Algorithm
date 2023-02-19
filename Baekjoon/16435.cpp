#include <iostream>
#include <algorithm>
using namespace std;

int n, l, h[10000];
int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++) cin >> h[i];

    sort(h, h + n);
    int cur = 0;

    while( cur < n && h[cur] <= l) {
        l++;
        cur++;
    }
    cout << l << '\n';
    return 0;
}