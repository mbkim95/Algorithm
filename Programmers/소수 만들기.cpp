#include <vector>
#include <iostream>
using namespace std;

int ans;
bool chk[3001];

void precalc() {
    fill(chk, chk + 3001, true);
    chk[0] = false;
    chk[1] = false;

    for (int i = 2; i * i <= 3000; i++) {
        if (!chk[i]) continue;
        for (int j = i * i; j <= 3000; j += i)
            chk[j] = false;
    }
}

void dfs(vector<int>& nums, int idx, int cnt, int sum) {
    if (cnt == 3) {
        if (chk[sum]) ans++;
        return;
    }

    for (int i = idx + 1; i < nums.size(); i++) {
        dfs(nums, i, cnt + 1, sum + nums[i]);
    }
}