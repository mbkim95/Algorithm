#include <iostream>
#include <map>
#include <climits>
using namespace std;

int n;
map<long long, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    int cnt = 0;
    long long ans = LLONG_MIN;
    while(n--) {
        long long tmp;
        cin >> tmp;
        m[tmp]++;
        if(cnt < m[tmp]) {
            cnt = m[tmp];
            ans = tmp;
        } else if(cnt == m[tmp] && ans > tmp) 
            ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}