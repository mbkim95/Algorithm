#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool bad[201][201], selected[201];
vector<int> tmp;

int select(int idx, int cnt) {
    if (cnt == 3)
        return 1;

    int ret = 0;

    for (int i = idx + 1; i <= n; i++) {
        if (!selected[i]) {
            bool is_pickable = true;
            for (int j = 0; j < tmp.size(); j++) {
                if (bad[i][tmp[j]]) {
                    is_pickable = false;
                    break;
                }
            }
            if (!is_pickable) continue;

            selected[i] = true;
            tmp.push_back(i);
            ret += select(i, cnt + 1);
            tmp.pop_back();
            selected[i] = false;
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        bad[a][b] = bad[b][a] = true;
    }
    cout << select(0, 0) << '\n';
    return 0;
}