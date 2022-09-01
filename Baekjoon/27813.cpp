#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string cmds[] = {"D", "S", "L", "R" };
bool visited[10001];

string bfs(int a, int b) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;
    q.push({a, ""});
    visited[a] = true;

    while(!q.empty()) {
        pair<int, string> cur = q.front();
        q.pop();

        if(cur.first == b) return cur.second;

        for(auto cmd : cmds) {
            int num = cur.first;
            if(cmd == "D") num = (2 * num) % 10000;
            else if(cmd == "S") num = num == 0 ? 9999 : num-1;
            else if(cmd == "L") num = (num % 1000) * 10 + num / 1000;
            else num = (num % 10) * 1000 + num / 10;

            if(!visited[num]) {
                if(num == b) return cur.second + cmd;

                q.push({num, cur.second + cmd});
                visited[num] = true;
            }
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
    return 0;
}