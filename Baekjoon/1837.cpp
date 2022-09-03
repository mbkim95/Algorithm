#include <iostream>
using namespace std;

string p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> p >> k;
    int ans = 987654321;
    for(int i=2; i<k; i++) {
        int ret = 0;
        for(int j=0; j<p.length(); j++) ret = (ret * 10 + (p[j] - '0')) % i;
        if(ret == 0) {
            ans = i;
            break;
        }
    }
    if(ans < k) cout << "BAD " << ans << '\n';
    else cout << "GOOD\n";
    return 0;
}