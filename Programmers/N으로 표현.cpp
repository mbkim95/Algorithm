#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num, ans = 9;

void dfs(int N, int cnt, int cur){
    if(cnt >= 9) return;
    if(num == cur){
        ans = min(ans, cnt);
        return;
    }
    int tmp = 0;
    for(int i=0; i+cnt<9; i++){
        tmp = 10 * tmp + N;
        dfs(N, i+cnt+1, cur + tmp);
        dfs(N, i+cnt+1, cur - tmp);
        dfs(N, i+cnt+1, cur * tmp);
        dfs(N, i+cnt+1, cur / tmp);
    }
}

int solution(int N, int number) {
    num = number;
    dfs(N, 0, 0);
    ans = ans == 9 ? -1 : ans;
    return ans;
}