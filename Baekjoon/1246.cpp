#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p[1000001];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) cin >> p[i];
    sort(p, p+m);
    int ans = 0, price;
    for(int i=p[0]; i<=p[m-1]; i++) {
        int tmp = 0;
        int chk = 0;
        for(int j=0; j<m; j++) if(p[j] >= i && chk < n) {
            tmp += i;
            chk++;
        }
        if(ans < tmp) {
            price = i;
            ans = tmp;
        }
    }
    cout << price << '\n' << ans << '\n';
    return 0;
}