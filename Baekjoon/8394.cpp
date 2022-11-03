#include <iostream>
using namespace std;

int p[10000001];

int main() {
    int n;
    cin >> n;
    p[0] = p[1] = 1;
    for(int i=2; i<=n; i++) p[i] = (p[i-1] + p[i-2]) % 10;
    cout << p[n] << '\n';
    return 0;
}