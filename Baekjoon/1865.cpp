#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> v;
int n, m, w, dist[501];
const int INF = -987654321;

bool bellmanFord() {
    for(int i=0; i<n; i++) {
        for(auto p : v) {
            int s = p.first.first;
            int e = p.first.second;
            int cost = p.second;

            if(dist[s] + cost < dist[e]) dist[e] = dist[s] + cost;
        }
    }

    for(auto p : v) {
        int s = p.first.first;
        int e = p.first.second;
        int cost = p.second;

        if(dist[s] + cost < dist[e]) return true;
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        v.clear();
        for(int i=1; i<=n; i++) dist[i] = INF;

        cin >> n >> m >> w;

        for(int i=0; i<m; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, t});
            v.push_back({{e, s}, t});
        }
        for(int i=0; i<w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, -t});
        }
        if(bellmanFord()) cout << "YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}