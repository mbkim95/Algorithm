#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
long long n;

vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    vector<vector<long long>> c(2, vector<long long>(2));

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
    vector<vector<long long>> a = {{1, 1}, {1, 0}};
    
    while(n > 0) {
        if(n % 2) {
            ans = multiply(ans, a);
            n--;
            continue;
        }
        a = multiply(a, a);
        n/=2;
    }
    cout << ans[0][1] << '\n';
    return 0;
}