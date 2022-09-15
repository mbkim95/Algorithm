#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = -1;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if(a <= b && (ans == -1 || ans > b)) ans = b;
    }
    cout << ans << '\n';
    return 0;
}