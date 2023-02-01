#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> p;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    p.resize(n);
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    for(int i=0; i<n; i++) {
        int t = p[i] - i;
        if(t > 0) ans += t;
    }
    cout << ans << '\n';
    return 0;
}