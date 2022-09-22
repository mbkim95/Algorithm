#include <iostream>
#include <algorithm>
using namespace std;

int prefix_sum[250001];

int main() {
    int n, x;
    cin >> n >> x;
    for(int i=1; i<=n; i++) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    int max_value = 0, cnt = 0;
    for(int i=x; i<=n; i++) {
        int sum = prefix_sum[i] - prefix_sum[i-x];
        if(sum > max_value) {
            max_value = sum;
            cnt = 1;
        } else if(sum == max_value) cnt++;
    }
    if(max_value == 0) cout << "SAD\n";
    else cout << max_value << '\n' << cnt << '\n';
    return 0;
}