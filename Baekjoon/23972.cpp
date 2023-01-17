#include <iostream>
using namespace std;

int main() {
    long long k, n, ans;
    cin >> k >> n;
    if(n == 1) ans = -1;
    else {
        ans = (k*n) / (n-1);
        if((k*n) % (n-1)) ans++;
    }
    cout << ans << '\n';
    return 0;
}