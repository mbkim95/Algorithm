#include <iostream>
using namespace std;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int a, b;
        cin >> a >> b;
        if(a * (100 - b) /100 < 100) cout << 1 << '\n';
        else cout << 0 << '\n';
        return 0;
}
