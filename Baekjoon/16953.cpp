#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

const int MAX = 1e9;
int a, b;
unordered_set<int> s;

int bfs() {
    queue<pair<long long, int>> q;
    q.push({a, 1});
    s.insert(a);

    while(!q.empty()){ 
        auto cur = q.front();
        q.pop();
        if(cur.first > b) continue;

        if(cur.first == b) return cur.second;

        long long next = cur.first * 2;
        if(next <= b && s.find(next) == s.end()) {
            q.push({next, cur.second + 1});
            s.insert(next);
        }
        next = 10 * cur.first + 1;
        if(next <= b && s.find(next) == s.end()) {
            q.push({next, cur.second + 1});
            s.insert(next);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cout << bfs() << '\n';
    return 0;
}