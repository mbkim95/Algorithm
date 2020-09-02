#include <string>
#include <vector>
#include <algorithm>
#define DIV 1000000007
using namespace std;

long long dp[5001];

int solution(int n) {
    if (n % 2 == 1) return 0;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[2] * dp[i - 2];
        for (int j = 0; j <= i - 4; j += 2)
            dp[i] += (2 * dp[j]);
        dp[i] %= DIV;
    }
    return dp[n];
}