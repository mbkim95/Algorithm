#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<int> dp;

int solve(int idx){
    int& ret = dp[idx];
    if(ret != -1) return ret;
    if(idx == 1) return ret = 1;
    if(idx == 2) return ret = 2;
    return ret = (solve(idx-1) + solve(idx-2)) % MOD;
}

int solution(int n) {
    int answer = 0;
    dp = vector<int>(n+1, -1);
    return solve(n);
}