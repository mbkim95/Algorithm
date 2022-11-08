#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int s = 0, e = 1, ans = 0;
    long long sum = 0;
    while(s < e) {
        if(sum <= n) {
            if(sum == n) ans++;
            sum += e;
            e++;
        }
        else {
            sum -= s;
            s++;
        }
    }
    cout << ans << '\n';
    return 0;
}