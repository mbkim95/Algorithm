#include <iostream>
using namespace std;

int n, t[50];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> t[i];
    int ans = 0, div = 0;
    for(int i=0; i<n; i++) {
        if(div < t[i]) {
            div = t[i];
            ans++;
        }
    }
    cout << ans << '\n';
    ans = 0, div = 0;
    for(int i=n-1; i>=0; i--) {
        if(div < t[i]) {
            div = t[i];
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}