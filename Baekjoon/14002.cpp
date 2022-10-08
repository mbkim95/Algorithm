#include <iostream>
#include <vector>
using namespace std;

int n, tmp, idx, a[1000], dp[1000];
vector<int> lis;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    tmp = 1;
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        for(int  j=0; j<i; j++) {
            if(a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if(tmp < dp[i]) {
                    tmp = dp[i];
                    idx = i;
                }
            }
         }
    }
    for(int i=idx; i>=0; i--) {
        if(dp[i] == tmp) {
            lis.push_back(a[i]);
            tmp--;
        }
    }
    cout << lis.size() << '\n';
    while(!lis.empty()) {
        cout << lis.back() << ' ';
        lis.pop_back();
    }
    cout << '\n';
    return 0;
}