#include <iostream>
#include <vector>
using namespace std;

int preSum[26][200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q;
    cin >> s;
    cin >> q;

    for (int i = 0; i < 26; i++) {
        vector<int> tmp(s.length() + 1, 0);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] - 'a' == i) tmp[j + 1]++;
        }
        for (int j = 0; j < s.length(); j++) preSum[i][j + 1] = preSum[i][j] + tmp[j + 1];
    }

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << preSum[c - 'a'][r + 1] - preSum[c - 'a'][l] << '\n';
    }
    return 0;
}