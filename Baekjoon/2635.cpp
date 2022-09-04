#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num, ans_num;

    int first;
    cin >> first;

    int ans = 1;
    for (int i = first / 2 + 1; i <= first; i++) {
        num.push_back(first);
        num.push_back(i);

        int idx = 2;
        while (true) {
            int next = num[idx - 2] - num[idx - 1];

            if (next < 0) break;

            num.push_back(next);
            idx++;
        }
        if (ans < idx) {
            ans = idx;
            ans_num = num;
        }
        num.clear();
    }
    cout << ans << '\n';
    for (int i : ans_num) cout << i << ' ';
    cout << '\n';
    return 0;
}