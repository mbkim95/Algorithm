#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    n = n ^ -n;
    for(int i=0; i<32; i++) {
        if(n & 1) cnt++;
        n = n >> 1;
    }
    cout << cnt << '\n';
    return 0;
}