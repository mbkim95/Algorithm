#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
bool can_make[2000001];

void dfs(int idx, int sum, vector<int> &num, vector<bool> &selected) {
    can_make[sum] = true;

    for (int i = idx + 1; i < n; i++) {
        if (!selected[i]) {
            selected[i] = true;
            dfs(i, sum + num[i], num, selected);
            selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> num(n);
    vector<bool> selected(n, false);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
    dfs(-1, 0, num, selected);

    for(int i=1; i<=2000000; i++) 
        if(!can_make[i]) {
            cout << i << '\n';
            break;
        }
    return 0;
}