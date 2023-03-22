#include <iostream>
#include <vector>
using namespace std;

int ans[10], cnt;
vector<int> yj;

void dfs(int idx) {
    if(idx == 10) {
        int tmp = 0;
        for(int i=0; i<10; i++) {
            if(yj[i] == ans[i]) tmp++;
        }
        if(tmp >= 5) cnt++;
        return;
    }

    for(int i=1; i<=5; i++) {
        if(idx >= 2 && yj[idx-2] == yj[idx-1] && yj[idx-1] == i) continue;
        yj.push_back(i);
        dfs(idx+1);
        yj.pop_back();
    }
}

int main() {
    for(int i=0; i<10; i++) cin >> ans[i];
    dfs(0);
    cout << cnt << '\n';
    return 0;
}