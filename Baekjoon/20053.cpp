#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, max = -1000001, min = 1000001;
        cin >> n;
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            if(tmp > max) max = tmp;
            if(tmp < min) min = tmp;
        }
        cout << min << ' ' << max << '\n';
    }
    return 0;
}