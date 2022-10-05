#include <iostream>
#include <cstring>
using namespace std;

long long dp[65][10];

long long solve(int len, int last) {
    long long& ret = dp[len][last];

    if(ret != -1) return ret;

    if(len == 1) return ret = 1;

    ret = 0;
    for(int i=0; i<=last; i++) ret += solve(len-1, i);
    return ret;
}

int main() {
    int t;
    cin >> t;

    memset(dp, -1, sizeof(dp));

    while(t--) {
        int n;
        cin >> n;
        long long ans = 0;
        for(int i=0; i<10; i++) ans += solve(n, i);
        cout << ans << '\n';
    }
    return 0;
}