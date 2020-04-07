#include <string>
#include <vector>

using namespace std;

long long dp[2001];

long long solve(int idx){
    if(dp[idx] != -1) return dp[idx];
    return dp[idx] = (solve(idx-1) + solve(idx-2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    fill(dp, dp+n+1, -1);
    dp[1] = 1;
    dp[2] = 2;
    answer = solve(n);
    return answer;
}