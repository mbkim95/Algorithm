#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c[1024][1024];

int find(int x, int y, int w) {
    if (w == 1) {
        return c[y][x];
    }

    vector<int> ret;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ret.push_back(find(x + i * w / 2, y + j * w / 2, w / 2));
    sort(ret.begin(), ret.end());
    return ret[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    cout << find(0, 0, n) << '\n';
    return 0;
}