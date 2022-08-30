#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    bool find = false;
    for (int i = l; i <= 100; i++) {
        long long s = (n / i) - i;
        long long sum = 0;
        while(sum < n) {       
            if(s < 0) {
                s++;
                continue;
            }

            long long e = s + i - 1;
            if((s + e) % 2 == 0) sum = ((s + e) / 2) * (e - s + 1);
            else sum = (s + e) * ((e - s + 1) / 2);

            if(sum == n) {
                for(int j=s; j<=e; j++) cout << j << ' ';
                cout << '\n';
                find = true;
                break;
            }
            s++;
        }
        if(find) break;
    }
    if (!find) cout << -1 << '\n';
    return 0;
}