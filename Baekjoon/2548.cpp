#include <iostream>
#include <algorithm>
using namespace std;

int n, num[20000], ans;

int main() {
    int sum = 987654321;
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];

    sort(num, num+n);
    for(int i=num[0]; i<=num[n-1]; i++) {
        int tmp = 0;
        for(int j=0; j<n; j++) {
            tmp += abs(i - num[j]);
        }
        if(tmp < sum) {
            sum = tmp;
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}