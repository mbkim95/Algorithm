#include <iostream>
using namespace std;

int main() {
    string n;

    while (true) {
        cin >> n;
        if (n == "0")
            break;

        int ans = 0;
        for (char c : n) {
            if (c == '0') ans += 4;
            else if (c == '1') ans += 2;
            else ans += 3;
        }
        ans += n.length() + 1;
        cout << ans << '\n';
    }
    return 0;
}