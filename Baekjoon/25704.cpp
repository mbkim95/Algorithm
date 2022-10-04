#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    cin >> p;
    int ans = p;
    if(n >= 5) ans = min(ans, max(0, p-500));
    if(n >= 10) ans = min(ans, max(0, p*9/10));
    if(n >= 15) ans = min(ans, max(0, p-2000));
    if(n >= 20) ans = min(ans, max(0, p*3/4));
    cout << ans << '\n';
}