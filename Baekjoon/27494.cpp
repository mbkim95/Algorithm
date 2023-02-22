#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for(int i=2023; i<=n; i++) {
        string s = to_string(i);

        int cnt = 0;
        for (char c : s) {
            if(cnt == 4) break;
            if (((cnt == 0 || cnt == 2) && c == '2') ||
            (cnt == 1 && c == '0') ||
            (cnt == 3 && c == '3')) cnt++;
        }
        if(cnt == 4) ans++;
    }
    cout << ans << '\n';
    return 0;
}