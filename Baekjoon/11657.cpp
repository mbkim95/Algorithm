#include <iostream>
#include <vector>
using namespace std;

bool isCycle = false;
int n, m;
long long dist[501];
vector<pair<pair<int, int>, int>> v;
const int INF = 987654321;

void bellmanFord() {
    dist[1] = 0;

    for(int i=0; i<n; i++) {
        for(auto p : v) {
            int s = p.first.first;
            int e = p.first.second;
            int cost = p.second;

            if(dist[s] == INF) continue;

            if(dist[s] + cost < dist[e]) {
                dist[e] = dist[s] + cost;
                if(i == n-1) isCycle = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    for(int i=1; i<=n; i++) dist[i] = INF;
    bellmanFord();

    if(isCycle) cout << "-1\n";
    else {
        for(int i=2; i<=n; i++) {
            if(dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}