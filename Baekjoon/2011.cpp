#include <iostream>
using namespace std;

const int MOD = 1000000;
int dp[5001];

int main() {
    string s;
    cin >> s;

    if(s[0] == '0') {
        cout << "0\n";
        return 0;
    }

    dp[0] = dp[1] = 1;
    for(int i=2; i<=s.length(); i++) {
        if(s[i-1] != '0') {
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }
        int tmp = (s[i-2]-'0') * 10 + s[i-1]-'0';
        if(10 <= tmp && tmp <= 26) {
            dp[i] += dp[i-2];
            dp[i] %= MOD;
        }
    }
    cout << dp[s.length()] << '\n';
    return 0;
}