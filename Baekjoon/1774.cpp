#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> space = vector<pair<int, int>>(1001);
int root[1001];
vector<pair<double, pair<int, int>>> edge;

int find(int a) {
    if (root[a] == a) return a;
    return root[a] = find(root[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (a > b) swap(a, b);
    root[b] = a;
}

double kruskal() {
    sort(edge.begin(), edge.end());
    double ans = 0;

    for(auto e : edge) {
        double dist = e.first;
        double s1 = e.second.first, s2 = e.second.second;

        if(find(s1) != find(s2)) {
            ans += dist;
            merge(s1, s2);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        space[i] = {x, y};
        root[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        if(find(s1) != find(s2)) merge(s1, s2);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || find(i) == find(j)) continue;

            long long xDiff = space[i].first - space[j].first;
            long long yDiff = space[i].second - space[j].second;
            edge.push_back({sqrt(xDiff * xDiff + yDiff * yDiff), {i, j}});
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << kruskal() << '\n';
    return 0;
}