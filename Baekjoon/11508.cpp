#include <iostream>
#include <algorithm>
using namespace std;

int n, c[100000], sum;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> c[i];

    sort(c, c+n, greater<int>());

    for(int i=0; i<n/3; i++) sum += c[3 * i] + c[3 * i + 1];
    for(int i=(n/3)*3; i<n; i++) sum += c[i];
    cout << sum << '\n';
    return 0;
}