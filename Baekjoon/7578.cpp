#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n;
vector<ll> a, tree;

ll sum(int node, int start, int end, int left, int right) {
    if (left > end || start > right) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(2 * node, start, mid, left, right) +
           sum(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx, diff);
        update(2 * node + 1, mid + 1, end, idx, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(1000001, 0);
    tree.resize(4 * (n + 1), 0);

    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        a[tmp] = i;
    }

    ll ans = 0;

    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        ans += sum(1, 1, n, a[tmp]+1, n);
        update(1, 1, n, a[tmp], 1);
    }
    cout << ans << '\n';
    return 0;
}
